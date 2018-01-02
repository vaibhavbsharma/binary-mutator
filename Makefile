HEADERS = BuildReplacement.h MyVisitor.h InsnUtils.h Mutation.h make-mutants.pl

DYNINST_INSTALL_ROOT = /export/scratch/vaibhav/local

default: ReplaceInsn dyninst-test

ReplaceInsn: ReplaceInsn.cpp $(HEADERS)
	    c++ ReplaceInsn.cpp -g -o ReplaceInsn  -I $(DYNINST_INSTALL_ROOT)/include -L $(DYNINST_INSTALL_ROOT)/lib -ldyninstAPI -linstructionAPI -ldw -lelf -lpatchAPI -lsymtabAPI -std=c++0x -lparseAPI -lcommon

#-L/home/taejoon/git/cba/coverage/tools/binary-mutator/libs/ 

dyninst-test: dyninst-test.c
	    gcc dyninst-test.c -o dyninst-test

clean:
		  rm -f ReplaceInsn dyninst-test
