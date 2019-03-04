# binary-mutator
This is a Dyninst-based binary mutator that mutates every flag-use instruction in a given X64 binary. 

You can run this tool using make-mutants.pl as follows:

    perl make-mutants.pl binary1
    
This will create a new binary file for every flag-use instruction in binary1. The new binaries will be named as binary1-<flag-use-insn-address>-<jCC/setCC/cmovCC>-<condition> where condition will be CT (Condition Taken) or CNT (Condition Not Taken) for jCC instructions, NOP or MOV for cmovCC instructions and SET0 or SET1 for setCC instructions.

    perl make-mutants.pl binary1 function1 1/0-to-control-debugging-output

This will create new binary files for every flag-use instruction in function1 in binary1 as explained before.

I ran the tool on the "cruise-o3" binary in the component-based-assurance repository and it generated 483 mutants. I've also manually verified mutants generated for a few jCC, setCC, cmovCC instructions and found them to be correct.

Please note that make-mutants.pl runs a binary named ReplaceInsn which requires dyninst to be installed and dyninst installation paths updated in the Makefile (which is quite basic for now). I have checked in my current version of ReplaceInsn for you to have something to run now.

In order to compile ReplaceInsn, you will need to specify the directory in which your dyninst copy was installed in the DYNINST_INSTALL_ROOT variable in the Makefile.
