INDS=("./microwave_auto" "./infusion")
OUTDS=("./microwave_auto-gcc" "./infusion-gcc")
CONFIG_ORIGINAL="exp_config_original.sh"
CONFIG="experiment_config.sh"

function init_test() {
  [ -f "../make-mutants.pl" -a -f "../ReplaceInsn" ] \
    || { echo "Make first."; exit; }
  cp ../make-mutants.pl .
  cp ../ReplaceInsn .
  for dir in ${OUTDS[@]}; do
    rm -r $dir/bin
    rm -r $dir/bintraces
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
  # test 3: microwave - gcc
  echo "COMPILER=clang" >> $CONFIG
  ./measureOobc ./microwave_auto ./microwave_auto-clang #2> error.log
}

if [ "$1" == "init" ]; then
  init_test
  exit
elif [ $1 -ge 1 -a $1 -le 3 ]; then
  init_test
  testcase${1}
else
  echo "Usage: $./run_test.sh {init, 1, 2}"
  echo "    1: the first test w/ Microwave example"
  echo "    2: the second test w/ Infusion Pump example"
  exit
fi

./show-segfault-cases.sh

