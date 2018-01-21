OUTDS=("./microwave_auto-gcc" "./infusion-gcc" "./microwave_auto-clang")
COMPILED_OUTDS=("./microwave_auto-clang2")
CONFIG_ORIGINAL="exp_config_original.sh"
CONFIG="experiment_config.sh"

function init_test() {
  [ -f "../make-mutants.pl" -a -f "../ReplaceInsn" ] \
    || { echo "Make first."; exit; }
  cp ../make-mutants.pl .
  cp ../ReplaceInsn .
  for dir in ${COMPILED_OUTDS[@]}; do
    rm -r $dir/bintraces 2> /dev/null
  done
  for dir in ${OUTDS[@]}; do
    rm -r $dir/bin 2> /dev/null
    rm -r $dir/bintraces 2> /dev/null
  done
  # set up a new configuration file
  cp $CONFIG_ORIGINAL $CONFIG
}

function testcase1() {
  # test 1: microwave - gcc
  echo "COMPILER=gcc" >> $CONFIG
  ./measureOobc ./microwave_auto ./microwave_auto-gcc #2> error.log
}

function testcase2() {
  # test 2: infusion - gcc
  echo "COMPILER=gcc" >> $CONFIG
  ./measureOobc ./infusion ./infusion-gcc #2> error.log
}

function testcase3() {
  # test 3: microwave - clang
  echo "COMPILER=clang" >> $CONFIG
  ./measureOobc ./microwave_auto ./microwave_auto-clang #2> error.log
}

function testcase4() {
  # test 4: microwave - clang with bin mutants generated from TJ's machine
  echo "COMPILER=clang" >> $CONFIG
  ./measureOobc ./microwave_auto ./microwave_auto-clang2 #2> error.log
}

if [ "$1" == "init" ]; then
  init_test
  echo "Initialized."
  exit
elif [ $1 -ge 1 -a $1 -le 4 ]; then
  testcase${1}
else
  echo "Usage: $./run_test.sh {init, 1, 2}"
  echo "    init: Initialize the test directory. Remove the clutter"
  echo "    1   : Run the first test Microwave - GCC"
  echo "    2   : Run the second test of Infusion Pump - GCC"
  echo "    3   : Run the third test of Microwave - Clang"
  exit
fi

./show-segfault-cases.sh

