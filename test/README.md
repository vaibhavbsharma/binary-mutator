How to run
==========

1.  Run `$ ./run_test.sh`. Run `$ ./run_test.sh 1` to run the first test case,
    Run `$./run_test.sh 2` to run the second test case.

2.  A bunch of output will be produced initially from the binary mutator.

3.  After the mutation is done for `-O1` and `-Os`, the script will run a bunch
    of test cases on each of the binary mutant generated.

4.  Finally, run `./show-segfault-cases.sh` to see what's wrong.

Test cases
==========

> updated at 3pm on 1/20 by TJ

Test case 1
-----------

`Microwave` compiled with `GCC`.
Fixed on 1/20/18.

Test case 2
-----------

`Infusion Pump` compiled with `GCC`.
[The failing cases are listed here](infusion-gcc-failures.txt).

Test case 3
-----------

`Microwave` compiled with `Clang`.
[The failing cases are listed here](microwave-clang-failures.txt).


What you'd see
==============

Each run will produce an execution trace in
`./microwave_auto-gcc/bintraces/o{x}/{mutant-name}` directory. The *stdout* and
*stderr* of the execution should appear on screen in the following format:

```
0x400d8a-setCC-SET1 tc_0010.csv tc_0010_trace.csv
```

When a segfault is triggered, it will appear right next to the normal message
like:

```
0x400b3e-setCC-SET1 tc_0043.csv tc_0043_trace.csv
./measureOobc: line 66:  7614 Segmentation fault      (core dumped) ./$mut $tc $trace
0x4013a2-jCC-CT tc_0040.csv tc_0040_trace.csv
0x400cb3-cmovCC-NOP tc_0042.csv tc_0042_trace.csv
```

Which indicates which mutant has failed.

The result?
===========

I assume that any trace of size 0 is *wrong*. Run `./show-segfault-cases.sh` to
see which combination of optimization, mutant, and testcase produce empty
trace, which likely indicates segfault.

