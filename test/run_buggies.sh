BLUE='\033[0;34m'
GREEN='\033[0;32m'
ENDL='\033[0m'
tmp_out="tmp.txt"
BUGGIES="$(pwd)/buggies"

function is_tarfile() {
  [ $(echo $1 | rev | cut -c-6 | rev) == "tar.gz" ] && echo 0 || echo -1
}

# untar all
cd $BUGGIES
for f in $(ls $BUGGIES); do
  if $(is_tarfile $f); then
    tar -xzf "$BUGGIES/$f"
  fi
done
cd ../

for crash_kind in $(ls $BUGGIES); do
  if $(is_tarfile $BUGGIES/$crash_kind); then
    continue
  fi
  dir="$BUGGIES/$crash_kind"
  test="$dir/tc.csv"
  echo -e "${BLUE}Running crashing mutants in setting $GREEN$crash_kind$ENDL"
  for f in $(ls $dir); do
    if [ "$(echo $f | cut -c-2)" == "0x" ]; then
      echo -e "\t$dir/$f $test $tmp_out"
      $dir/$f $test $tmp_out
    fi
  done
done

[ -f $tmp_out ] && rm $tmp_out
