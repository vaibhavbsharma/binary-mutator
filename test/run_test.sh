INDS=("./microwave_auto" "./infusion")
OUTDS=("./microwave_auto-gcc" "./infusion-gcc")

function init_test() {
  for d in ${OUTD[@]}; do
    rm -r $d/bin
    rm -r $d/bintraces
  done
  [ -f "../make-mutants.pl" -a -f "../ReplaceInsn" ] \
    || { echo "Make first."; exit; }
  cp ../make-mutants.pl .
  cp ../ReplaceInsn .
}

if [ "$1" == "init" ]; then
  init_test
  exit
elif [ "$1" == "1" ]; then
  # test 1: microwave
  init_test
  ./measureOobc ./microwave_auto ./microwave_auto-gcc #2> error.log
elif [ "$1" == "2" ]; then
  # test 2: infusion pump
  init_test
  ./measureOobc ./infusion ./infusion-gcc #2> error.log
else
  echo "Usage: $./run_test.sh {init, 1, 2}"
  echo "    1: the first test w/ Microwave example"
  echo "    2: the second test w/ Infusion Pump example"
  exit
fi

./show-segfault-cases.sh

