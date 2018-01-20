IND=./microwave_auto
OUTD=./microwave_auto-gcc

function init_test() {
  rm make-mutants.pl
  rm ReplaceInsn
  rm -r $OUTD/bin
  rm -r $OUTD/bintraces
}

[ "$1" == "init" ] && { init_test; exit; }
[ -f "../make-mutants.pl" -a -f "../ReplaceInsn" ] || { echo "Make first."; exit; }

init_test
cp ../make-mutants.pl .
cp ../ReplaceInsn .
./measureOobc ./microwave_auto ./microwave_auto-gcc #2> error.log
./show-segfault-cases.sh

