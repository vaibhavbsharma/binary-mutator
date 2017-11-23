// c++ dyninst-ex3.cpp -g -o dyninst-ex3  -I /export/scratch/vaibhav/local/include -L /export/scratch/vaibhav/local/lib -ldyninstAPI -linstructionAPI -ldw -lelf -lpatchAPI -lsymtabAPI -std=c++0x -lparseAPI -lcommon

#include <iostream>
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
  if(argc != 2){
    printf("Usage: %s <binary path>\n", argv[0]);
    return -1;
  }
  char *binaryPath = argv[1];
	BPatch_addressSpace *handle = startInstrumenting(binaryPath);
	PatchMgrPtr patchMgrPtr = PatchAPI::convert(handle);

	//PatchObject* obj = PatchAPI::convert(handle);
  
  // Find all functions in the object
  std::vector<PatchFunction*> all;
	vector<BPatch_function *> *all_BPatch_funcs = handle->getImage()->getProcedures();
	for(int i=0; i<all_BPatch_funcs->size(); i++) {
		all.push_back(PatchAPI::convert((*all_BPatch_funcs)[i]));
    Function *f = ParseAPI::convert((*all_BPatch_funcs)[i]);
    //get address of entry point for current function
    
    Address crtAddr = f->addr();
    int instr_count = 0;
    InstructionDecoder decoder(f->isrc()->getPtrToInstruction(f->addr()),
  		InstructionDecoder::maxInstructionLength,
  		f->region()->getArch());
		Instruction::Ptr instr = decoder.decode((unsigned char *)f->isrc()->getPtrToInstruction(crtAddr));
    auto fbl = f->blocks().end();
    fbl--;
    Block *b = *fbl;
    Address lastAddr = b->last();
    //if current function has zero instructions, dont output it
    if(crtAddr == lastAddr)
    continue;
    cout << "\n\n\"" << f->name() << "\" :";
    while(crtAddr < lastAddr){
      //decode current instruction
      instr = decoder.decode((unsigned char *)f->isrc()->getPtrToInstruction(crtAddr));
      cout << "\n" << hex << crtAddr;
      cout << ": \"" << instr->format() << "\"";
      //go to the address of the next instruction
      crtAddr += instr->size();
			vector<Operand> operands;
			instr->getOperands(operands);
			cout<< " ("<<operands.size()<<")";
			MyVisitor myVisitor;
			for(int i=0; i < operands.size(); i++) {
				Expression::Ptr ePtr = operands[i].getValue();
			  ePtr->apply(&myVisitor);
			}
      if(myVisitor.getRegUsed() == "x86_64::eax" &&
				 myVisitor.getIsImmediate() == 1 &&
				 myVisitor.getImmediateValue() == 1 &&
				 instr->getOperation().getID() == e_add 
			   ) {
				cout<< " interesting instruction";

			}
      instr_count++;
			fflush(stdout);
    }
	}
  //obj->funcs(back_inserter(all));
  
  for (std::vector<PatchFunction*>::iterator fi = all.begin();
    fi != all.end(); fi++) {
    // Print out each function’s name
    PatchFunction* func = *fi;
    std::cout << func->name() << std::endl;
    
    const PatchFunction::Blockset & blks = func->blocks();
    for (PatchFunction::Blockset::iterator bi = blks.begin();
      bi != blks.end(); bi++) {
      // Print out each block’s size
      PatchBlock* blk = *bi;
      std::cout << "\tBlock size:" << blk->size() << std::endl;
    }
  }
  return 0;
}

