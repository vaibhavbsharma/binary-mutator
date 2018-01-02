// c++ ReplaceInsn.cpp -g -o ReplaceInsn  -I /export/scratch/vaibhav/local/include -L /export/scratch/vaibhav/local/lib -ldyninstAPI -linstructionAPI -ldw -lelf -lpatchAPI -lsymtabAPI -std=c++0x -lparseAPI -lcommon  

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

#include "Mutation.h"
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
					Instruction::Ptr iptr = (*j).second;
					if(debug) {
						cout<<"  "<<iptr->format()<<endl;
					}
          int nbytes = iptr->size();
#define MAX_RAW_INSN_SIZE 16
          assert(nbytes <= MAX_RAW_INSN_SIZE);
          // vector<Operand> operands;
			    // iptr->getOperands(operands);
			    // MyVisitor myVisitor;
			    // for(int i=0; i < operands.size(); i++) {
			    // 	Expression::Ptr ePtr = operands[i].getValue();
			    //   ePtr->apply(&myVisitor);
			    // }
          // if(myVisitor.getRegUsed() == "x86_64::eax" &&
			    // 	 myVisitor.getIsImmediate() == 1 &&
			    // 	 myVisitor.getImmediateValue() == 1 &&
			    // 	 iptr->getOperation().getID() == e_add &&
					// 	 f->name().find(functionName) != string::npos) {
			    // 	cout<< "\nfound add %eax: "<<iptr->format()<<endl;
					// 	PointMaker *pointMaker = patchMgrPtr->pointMaker();
					// 	Location loc = Location::InstructionInstance(
					// 			PatchAPI::convert((*all_BPatch_funcs)[i]),
					// 			patchBLock, (Address)addr);
					// 	Point *point = pointMaker->createPoint(loc, Point::Type::PreInsn);
					// 	BPatch_registerExpr *intCounter = new BPatch_registerExpr(Dyninst::x86_64::eax);
          //   BPatch_arithExpr *add42 = 
		      //   	new BPatch_arithExpr(BPatch_plus, *intCounter, BPatch_constExpr(42));
		      //   BPatch_arithExpr *addOne = new BPatch_arithExpr(BPatch_assign, *intCounter,
		      //   		 *add42);
          //   Snippet::Ptr handler = PatchAPI::convert(addOne);
					// 	buildReplacement(addr, &(*iptr), patchBlock, true, point, handler);
			    // } 
			    if(isCMOVCC(iptr->getOperation().getID()) &&
						 (!mutatedBranch(addr, COND_NOT_TAKEN) ||
							!mutatedBranch(addr, COND_TAKEN)) && 
						 !mutated) {
			    	cout<< "  found cmovCC: "<<iptr->format()<<endl;
						PointMaker *pointMaker = patchMgrPtr->pointMaker();
						Location loc = Location::InstructionInstance(
								PatchAPI::convert((*all_BPatch_funcs)[i]),
								patchBlock, (Address)addr);
						Point *point = pointMaker->createPoint(loc, Point::Type::PreInsn);
						Snippet::Ptr handler;
						if(!mutatedBranch(addr, COND_NOT_TAKEN)) {
						  BPatch_constExpr *nop = new BPatch_constExpr(42);
              handler = PatchAPI::convert(nop);
							condition = COND_NOT_TAKEN;
							conditionString = "NOP";
							cout<<"  replacing with nop\n";
						} else if(!mutatedBranch(addr, COND_TAKEN)) {
							MachRegister srcReg, dstReg;
              vector<Operand> operands;
			        iptr->getOperands(operands);
			        MyVisitor *myVisitor = new MyVisitor();
			        Expression::Ptr ePtr = operands[0].getValue();
			        ePtr->apply(myVisitor);
						  BPatch_registerExpr *dst = new BPatch_registerExpr(myVisitor->getRegUsed());
							dstReg = myVisitor->getRegUsed();
							myVisitor = new MyVisitor();
              ePtr = operands[1].getValue();
			        ePtr->apply(myVisitor);
							// if source is register
							if(myVisitor->getRegUsed() != Dyninst::x86_64::rip) {
						    BPatch_registerExpr *src = new BPatch_registerExpr(myVisitor->getRegUsed());
							  srcReg = myVisitor->getRegUsed();
		            BPatch_arithExpr *mov= new BPatch_arithExpr(BPatch_assign, *dst, *src);
                handler = PatchAPI::convert(mov);
							  cout<<"  replacing with "<<dstReg.name() <<" = " << srcReg.name()<<endl;
							} else { // source is immediate
						    BPatch_constExpr *src = new BPatch_constExpr(myVisitor->getImmediateValue());
		            BPatch_arithExpr *mov= new BPatch_arithExpr(BPatch_assign, *dst, *src);
                handler = PatchAPI::convert(mov);
							  cout<<"  replacing with "<<dstReg.name() <<" = " 
									<< myVisitor->getImmediateValue()<<endl;
							}
							condition = COND_TAKEN;
							conditionString = "MOV";
						}
						buildReplacement(addr, &(*iptr), patchBlock, debug, point, handler);
					  checkpointMutation(addr, condition);
						char tmpString[20];
						sprintf(tmpString, "0x%x", addr);
						mutationSuffix = tmpString;
						mutationSuffix += "-cmovCC-" + conditionString;
						mutated = true;
			    }

          if(isSETCC(iptr->getOperation().getID()) &&
						 (!mutatedBranch(addr, COND_NOT_TAKEN) ||
							!mutatedBranch(addr, COND_TAKEN)) && 
						 !mutated) {
			    	cout<< "  found setCC: "<<iptr->format()<<endl;
						PointMaker *pointMaker = patchMgrPtr->pointMaker();
						Location loc = Location::InstructionInstance(
								PatchAPI::convert((*all_BPatch_funcs)[i]),
								patchBlock, (Address)addr);
						Point *point = pointMaker->createPoint(loc, Point::Type::PreInsn);
						Snippet::Ptr handler;
						EdgeTypeEnum condition;
            MachRegister srcReg, dstReg;
            vector<Operand> operands;
			      iptr->getOperands(operands);
			      MyVisitor *myVisitor = new MyVisitor();
			      Expression::Ptr ePtr = operands[0].getValue();
			      ePtr->apply(myVisitor);
						BPatch_registerExpr *dst = new BPatch_registerExpr(myVisitor->getRegUsed());
						dstReg = myVisitor->getRegUsed();

						if(!mutatedBranch(addr, COND_NOT_TAKEN)) {
						  BPatch_constExpr *setZero = new BPatch_constExpr(0);
		          BPatch_arithExpr *mov= new BPatch_arithExpr(BPatch_assign, *dst, *setZero);
              handler = PatchAPI::convert(mov);
							condition = COND_NOT_TAKEN;
							conditionString = "SET0";
							cout<<"  setting "<<dstReg.name()<<" to 0\n";
						} else if(!mutatedBranch(addr, COND_TAKEN)) {
             BPatch_constExpr *setOne = new BPatch_constExpr(1);
		          BPatch_arithExpr *mov= new BPatch_arithExpr(BPatch_assign, *dst, *setOne);
              handler = PatchAPI::convert(mov);
							condition = COND_TAKEN;
							conditionString = "SET1";
							cout<<"  setting "<<dstReg.name()<<" to 1\n";
						}
						buildReplacement(addr, &(*iptr), patchBlock, debug, point, handler);
					  checkpointMutation(addr, condition);
						char tmpString[20];
						sprintf(tmpString, "0x%x", addr);
						mutationSuffix = tmpString;
						mutationSuffix += "-setCC-" + conditionString;
						mutated = true;
			    }

					if(iptr->getCategory()==c_BranchInsn && 
							iptr->getOperation().getID() != e_jmp &&
							!mutatedBranch(addr, COND_NOT_TAKEN) &&
							!mutated) {
						cout << "  found branch (COND_NOT_TAKEN) \n";
						vector<PatchEdge *> edges = patchBlock->targets();
						assert(edges.size()==2);
						if(edges[0]->type() == COND_NOT_TAKEN) {
							bool redirectStatus = 
								PatchModifier::redirect(edges[0], edges[1]->trg());
							if(!redirectStatus) 
								cout<<"  failed to redirect edge\n";
							else cout<<"  redirect successful (1)\n";
							checkpointMutation(addr, COND_NOT_TAKEN);
						  char tmpString[20];
						  sprintf(tmpString, "0x%x", addr);
						  mutationSuffix = tmpString;
						  mutationSuffix += "-jCC-CNT";
							mutated = true;
						} else if(edges[1]->type() == COND_NOT_TAKEN) {
							bool redirectStatus = 
								PatchModifier::redirect(edges[1], edges[0]->trg());
							if(!redirectStatus) 
								cout<<"  failed to redirect edge\n";
							else cout<<"  redirect successful (2)\n";
							checkpointMutation(addr, COND_NOT_TAKEN);
						  char tmpString[20];
						  sprintf(tmpString, "0x%x", addr);
						  mutationSuffix = tmpString;
						  mutationSuffix += "-jCC-CNT";
							mutated = true;
						}
					}
					if(iptr->getCategory()==c_BranchInsn &&
							iptr->getOperation().getID() != e_jmp &&
							!mutatedBranch(addr, COND_TAKEN) &&
							!mutated) {
						cout << "  found branch (COND_TAKEN) \n";
						vector<PatchEdge *> edges = patchBlock->targets();
						assert(edges.size()==2);
						if(edges[0]->type() == COND_TAKEN) {
							bool redirectStatus = 
								PatchModifier::redirect(edges[0], edges[1]->trg());
							if(!redirectStatus) 
								cout<<"  failed to redirect edge\n";
							else cout<<"  redirect successful (1)\n";
							checkpointMutation(addr, COND_TAKEN);
						  char tmpString[20];
						  sprintf(tmpString, "0x%x", addr);
						  mutationSuffix = tmpString;
						  mutationSuffix += "-jCC-CT";
							mutated = true;
						} else if(edges[1]->type() == COND_TAKEN) {
							bool redirectStatus = 
								PatchModifier::redirect(edges[1], edges[0]->trg());
							if(!redirectStatus) 
								cout<<"  failed to redirect edge\n";
							else cout<<"  redirect successful (2)\n";
							checkpointMutation(addr, COND_TAKEN);
						  char tmpString[20];
						  sprintf(tmpString, "0x%x", addr);
						  mutationSuffix = tmpString;
						  mutationSuffix += "-jCC-CT";
							mutated = true;
						}
					}
      }
		}

    // //get address of entry point for current function
    // Address crtAddr = f->addr();
    // int instr_count = 0;
    // InstructionDecoder decoder(f->isrc()->getPtrToInstruction(f->addr()),
  	// 	InstructionDecoder::maxInstructionLength,
  	// 	f->region()->getArch());
		// Instruction::Ptr instr = decoder.decode((unsigned char *)f->isrc()->getPtrToInstruction(crtAddr));

    // auto fbl = f->blocks().end();
    // fbl--;
    // Block *b = *fbl;
    // Address lastAddr = b->last();
    // //if current function has zero instructions, dont output it
    // if(crtAddr == lastAddr || !is_testFn)
    // continue;
    // cout << "\n\n\"" << f->name() << "\" :";
    // while(crtAddr < lastAddr){
    //   //decode current instruction
    //   instr = decoder.decode((unsigned char *)f->isrc()->getPtrToInstruction(crtAddr));
    //   cout << "\n" << hex << crtAddr;
    //   cout << ": \"" << instr->format() << "\"";
    //   //go to the address of the next instruction
    //   crtAddr += instr->size();
		// 	vector<Operand> operands;
		// 	instr->getOperands(operands);
		// 	cout<< " ("<<operands.size()<<")";
		// 	MyVisitor myVisitor;
		// 	for(int i=0; i < operands.size(); i++) {
		// 		Expression::Ptr ePtr = operands[i].getValue();
		// 	  ePtr->apply(&myVisitor);
		// 	}
    //   if(myVisitor.getRegUsed() == "x86_64::eax" &&
		// 		 myVisitor.getIsImmediate() == 1 &&
		// 		 myVisitor.getImmediateValue() == 1 &&
		// 		 instr->getOperation().getID() == e_add 
		// 	   ) {
		// 		cout<< " interesting instruction";

		// 	}
    //   instr_count++;
		// 	fflush(stdout);
    // }
	}
  //obj->funcs(back_inserter(all));
  
  // for (std::vector<PatchFunction*>::iterator fi = all.begin();
  //   fi != all.end(); fi++) {
  //   // Print out each function’s name
  //   PatchFunction* func = *fi;
  //   std::cout << func->name() << std::endl;
  //   
  //   const PatchFunction::Blockset & blks = func->blocks();
  //   for (PatchFunction::Blockset::iterator bi = blks.begin();
  //     bi != blks.end(); bi++) {
  //     // Print out each block’s size
  //     PatchBlock* blk = *bi;
  //     std::cout << "\tBlock size:" << blk->size() << std::endl;
  //   }
  // }
	if(!mutated) { cout <<"No mutations found\n"; return 1; }
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

