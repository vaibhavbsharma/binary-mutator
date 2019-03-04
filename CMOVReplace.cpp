// c++ CMOVReplace.cpp -g -o CMOVReplace  -I /export/scratch/vaibhav/local/include -L /export/scratch/vaibhav/local/lib -ldyninstAPI -linstructionAPI -ldw -lelf -lpatchAPI -lsymtabAPI -std=c++0x -lparseAPI -lcommon  

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

#include "CodeObject.h"
#include "InstructionDecoder.h"
#include "PatchCFG.h"
#include "PatchObject.h"
#include "MyVisitor.h"
#include "BuildReplacement.h"
#include "BPatch.h"
#include "BPatch_addressSpace.h"
#include "BPatch_process.h"
#include "BPatch_binaryEdit.h"
#include "BPatch_function.h"
#include "BPatch_point.h"
#include "BPatch_flowGraph.h"

#include "InsnUtils.h"

using namespace std;
using namespace Dyninst;
using namespace ParseAPI;
using namespace PatchAPI;
using namespace InstructionAPI;

BPatch bpatch;

BPatch_addressSpace *startInstrumenting(const char *name) {
  BPatch_addressSpace *handle = NULL;
  handle = bpatch.openBinary(name);
  return handle;
}

int main(int argc, char **argv){
  if(argc < 2){
    printf("Usage: %s <binary path>\n", argv[0]);
    return -1;
  }
  char *binaryPath = argv[1];
  char *functionName;
  BPatch_addressSpace *handle = startInstrumenting(binaryPath);
  handle->beginInsertionSet();
  PatchMgrPtr patchMgrPtr = PatchAPI::convert(handle);
  
  // Find all functions in the object
  std::vector<PatchFunction*> all;
  vector<BPatch_function *> *all_BPatch_funcs = handle->getImage()->getProcedures();
  string conditionString;
  string mutationSuffix;
  for(int i=0; i<all_BPatch_funcs->size(); i++) {
    all.push_back(PatchAPI::convert((*all_BPatch_funcs)[i]));
    Function *f = ParseAPI::convert((*all_BPatch_funcs)[i]);
    std::set<BPatch_basicBlock*> blocks;
    BPatch_flowGraph *cfg = ( (*all_BPatch_funcs)[i] )->getCFG();
    cfg->getAllBasicBlocks(blocks);
    for (set<BPatch_basicBlock*>::iterator b = blocks.begin(); 
        b != blocks.end(); b++) {
      PatchBlock::Insns insns;
      PatchBlock *patchBlock = PatchAPI::convert(*b);
      patchBlock->getInsns(insns);
      PatchBlock::Insns::iterator j;
      for (j = insns.begin(); j != insns.end(); j++) {
        // get instruction bytes
        void *addr = (void*)((*j).first);
        InstructionAPI::Instruction insn = (*j).second;
        InstructionAPI::Instruction *iptr = &insn;
        int nbytes = iptr->size();
#define MAX_RAW_INSN_SIZE 16
        assert(nbytes <= MAX_RAW_INSN_SIZE);
        if(isCMOVCC(iptr->getOperation().getID())) {
          cout<< "  found cmovCC: "<<iptr->format()<<endl;
          PointMaker *pointMaker = patchMgrPtr->pointMaker();
          Location loc = Location::InstructionInstance(
              PatchAPI::convert((*all_BPatch_funcs)[i]),
              patchBlock, (Address)addr);
          Point *point = pointMaker->createPoint(loc, Point::Type::PreInsn);
          Snippet::Ptr handler;
          BPatch_constExpr *nop = new BPatch_constExpr(42);
          handler = PatchAPI::convert(nop);
          conditionString = "NOP";
          cout<<"  replacing with nop\n";
          buildReplacement(addr, &(*iptr), patchBlock, true, point, handler);
          char tmpString[20];
          sprintf(tmpString, "0x%x", addr);
          mutationSuffix = tmpString;
          mutationSuffix += "-cmovCC-" + conditionString;
        }
      }
    }
  }
  handle->finalizeInsertionSet(false);

  char str[500];
  sprintf(str, "%s-mutants/%s", binaryPath, mutationSuffix.c_str());
  string outFile(str);

  sprintf(str, "%s-mutants", binaryPath);
  mkdir(str, S_IRWXU);

  printf("Writing new binary to \"%s\" ...\n", outFile.c_str());
  ((BPatch_binaryEdit*)handle)->writeFile(outFile.c_str());
  printf("Done.\n");
  return 0;
}

