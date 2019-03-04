HEADERS = BuildReplacement.h MyVisitor.h InsnUtils.h Mutation.h make-mutants.pl

DYNINST_INSTALL_ROOT = /export/scratch/vaibhav/dyninst/build-install
TBB_INCLUDE_DIRS=/export/scratch/vaibhav/tbb/tbb2019_20181203oss/include
LIBDWARF_LIBRARIES_DIR=/export/scratch/vaibhav/elfutils/elfutils-install/


PATH_BOOST=/export/scratch/vaibhav/boost_1_69_0/boost-install
TBB_tbb_LIBRARY_RELEASE=/export/scratch/vaibhav/tbb/tbb2019_20181203oss/lib/intel64/gcc4.7/libtbb.so 
LIBELF_INCLUDE_DIR=/export/scratch/vaibhav/elfutils/elfutils-install/include 
LIBELF_LIBRARIES=/export/scratch/vaibhav/elfutils/elfutils-install/lib/  
LIBDWARF_INCLUDE_DIR=/export/scratch/vaibhav/elfutils/elfutils-install/include/ 
LIBDWARF_LIBRARIES=/export/scratch/vaibhav/elfutils/elfutils-install/lib/


default: ReplaceInsn CMOVReplace dyninst-test small-cmov-eg small-setcc-eg

ReplaceInsn: ReplaceInsn.cpp $(HEADERS)
	    c++ ReplaceInsn.cpp -g -o ReplaceInsn  \
	      -L $(DYNINST_INSTALL_ROOT)/lib -L $(LIBDWARF_LIBRARIES_DIR)/lib -L $(LIBELF_LIBRARIES) \
	      -I $(DYNINST_INSTALL_ROOT)/include -I $(TBB_INCLUDE_DIRS) \
	      -I $(LIBELF_INCLUDE_DIR) -I $(LIBDWARF_INCLUDE_DIR) \
	      -ldyninstAPI -linstructionAPI -ldw -lelf -lpatchAPI -lsymtabAPI -std=c++0x -lparseAPI -lcommon -lboost_system

CMOVReplace : CMOVReplace.cpp $(HEADERS)
	    c++ CMOVReplace.cpp -g -o CMOVReplace  \
	      -L $(DYNINST_INSTALL_ROOT)/lib -L $(LIBDWARF_LIBRARIES_DIR)/lib -L $(LIBELF_LIBRARIES) \
	      -I $(DYNINST_INSTALL_ROOT)/include -I $(TBB_INCLUDE_DIRS) \
	      -I $(LIBELF_INCLUDE_DIR) -I $(LIBDWARF_INCLUDE_DIR) \
	      -ldyninstAPI -linstructionAPI -ldw -lelf -lpatchAPI -lsymtabAPI -std=c++0x -lparseAPI -lcommon -lboost_system

dyninst-test: dyninst-test.c
	    gcc dyninst-test.c -O0 -o dyninst-test-O0
	    gcc dyninst-test.c -O1 -o dyninst-test-O1
	    gcc dyninst-test.c -O2 -o dyninst-test-O2
	    gcc dyninst-test.c -O3 -o dyninst-test-O3

small-cmov-eg: small-cmov-eg.S
	    gcc small-cmov-eg.S -o small-cmov-eg

small-setcc-eg: small-setcc-eg.S
	    gcc small-setcc-eg.S -o small-setcc-eg

clean:
		  rm -f ReplaceInsn CMOVReplace dyninst-test small-cmov-eg small-setcc-eg
