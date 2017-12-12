HEADERS = BuildReplacement.h MyVisitor.h InsnUtils.h Mutation.h make-mutants.pl

default: ReplaceInsn dyninst-test

ReplaceInsn: ReplaceInsn.cpp $(HEADERS)
	    c++ ReplaceInsn.cpp -g -o ReplaceInsn -ldyninstAPI -linstructionAPI -lelf -lpatchAPI -lsymtabAPI -std=c++0x -lparseAPI -lcommon
			cp ReplaceInsn ../

#-L/home/taejoon/git/cba/coverage/tools/binary-mutator/libs/ 
#-I /export/scratch/vaibhav/local/include

dyninst-test: dyninst-test.c
	    gcc dyninst-test.c -o dyninst-test

clean:
		  rm -f ReplaceInsn dyninst-test
