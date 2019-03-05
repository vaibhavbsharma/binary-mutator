// c++ ReplaceInsn.cpp -g -o ReplaceInsn  -I /export/scratch/vaibhav/local/include -L /export/scratch/vaibhav/local/lib -ldyninstAPI -linstructionAPI -ldw -lelf -lpatchAPI -lsymtabAPI -std=c++0x -lparseAPI -lcommon  

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <memory>
#include <stdexcept>
#include <cstdio>

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

#include "Mutation.h"
#include "InsnUtils.h"
#include "ExecUtils.h"

using namespace std;
using namespace Dyninst;
using namespace ParseAPI;
using namespace PatchAPI;
using namespace InstructionAPI;

BPatch bpatch;

// 1 = noops, 2 = cmovCC, 4 = setCC, 8 = jCC
int targetInsnType = 2 + 4 + 8; 

BPatch_addressSpace *startInstrumenting(const char *name) {
  BPatch_addressSpace *handle = NULL;
  handle = bpatch.openBinary(name);
  return handle;
}

int main(int argc, char **argv){
  if(argc < 2){
    printf("Usage: %s <binary path> [function-name] [debug]\n", argv[0]);
    return -1;
  }
  char *binaryPath = argv[1];
  char *functionName;
  bool singleFunction = false;
  if(argc > 2) {
    functionName = argv[2];
    singleFunction = true;
  }
  else { 
    functionName = 0;
    singleFunction = false; 
  }
  bool debug = false;
  if(argc > 3) {
    if(strcmp(argv[3],"1") == 0 || strcmp(argv[3], "true") == 0)
      debug = true;
  }
  char fixOrigBinaryCmd[100];
  sprintf(fixOrigBinaryCmd, "python rewrite-binary.py %s original", binaryPath);
  printf("about to fix original binary: %s\n", fixOrigBinaryCmd);
  system(fixOrigBinaryCmd);
  initMutationCheckpoint(binaryPath, debug);
  BPatch_addressSpace *handle = startInstrumenting(binaryPath);
  handle->beginInsertionSet();
  PatchMgrPtr patchMgrPtr = PatchAPI::convert(handle);
  
  //PatchObject* obj = PatchAPI::convert(handle);
  
  // Find all functions in the object
  std::vector<PatchFunction*> all;
  vector<BPatch_function *> *all_BPatch_funcs = handle->getImage()->getProcedures();
  bool mutated = false;
  EdgeTypeEnum condition;
  string conditionString;
  string mutationSuffix;
  for(int i=0; i<all_BPatch_funcs->size() && !mutated; i++) {
    all.push_back(PatchAPI::convert((*all_BPatch_funcs)[i]));
    Function *f = ParseAPI::convert((*all_BPatch_funcs)[i]);
    if(debug)
      cout<< "found function : "<<f->name()<<endl;
    if(singleFunction)
      if(f->name().find(functionName) == string::npos) continue; 
    
    std::set<BPatch_basicBlock*> blocks;
    BPatch_flowGraph *cfg = ( (*all_BPatch_funcs)[i] )->getCFG();
    cfg->getAllBasicBlocks(blocks);
    for (set<BPatch_basicBlock*>::iterator b = blocks.begin(); 
        b != blocks.end() && !mutated; b++) {
      PatchBlock::Insns insns;
      PatchBlock *patchBlock = PatchAPI::convert(*b);
      patchBlock->getInsns(insns);
      PatchBlock::Insns::iterator j;
      for (j = insns.begin(); j != insns.end() && !mutated; j++) {
        // get instruction bytes
        void *addr = (void*)((*j).first);
        InstructionAPI::Instruction insn = (*j).second;
        InstructionAPI::Instruction *iptr = &insn;
        cout<<"  "<<iptr->format()<<endl;
      }
    }

  }
  return 0;
}



