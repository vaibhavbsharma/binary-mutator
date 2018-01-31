BLUE='\033[0;34m'
GREEN='\033[0;32m'
ENDL='\033[0m'
tmp_out="tmp.txt"

for crash_kind in $(ls "buggies"); do
  dir="$(pwd)/buggies/$crash_kind/"
  test="$dir/tc.csv"
  echo -e "${BLUE}Running crashing mutants in setting $GREEN$crash_kind$ENDL"
  for f in $(ls $dir); do
    if [ "$(echo $f | cut -c-2)" == "0x" ]; then
      echo -e "\t$dir/$f $test $tmp_out"
      $dir/$f $test $tmp_out
    fi
  done
done

rm $tmp_out
