HEADERS = BuildReplacement.h MyVisitor.h InsnUtils.h Mutation.h make-mutants.pl

default: ReplaceInsn dyninst-test

ReplaceInsn: ReplaceInsn.cpp $(HEADERS)
	    c++ ReplaceInsn.cpp -g -o ReplaceInsn  -I /export/scratch/vaibhav/local/include -L /export/scratch/vaibhav/local/lib -ldyninstAPI -linstructionAPI -ldw -lelf -lpatchAPI -lsymtabAPI -std=c++0x -lparseAPI -lcommon

dyninst-test: dyninst-test.c
	    gcc dyninst-test.c -o dyninst-test

clean:
		  rm -f ReplaceInsn dyninst-test
