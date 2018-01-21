
if [ "$#" -ne 2 -a "$#" -ne 3 ]; then
  echo "Missing arguments"
  exit 0
fi

source experiment_config.sh

[ "$#" -eq 3 ] && [ $3 -eq 1 ] && { IS_DEBUG=true; echo "IS_DEBUG enabled"; }

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
GRAY='\033[0;90m'
ON_WHITE='\033[47m'
ERROR=$ON_WHITE$RED
ENDL='\033[0m'

# Paths & more
TOOL_ROOT=`pwd`
INDIR=`readlink -f $1`
OUTDIR=`readlink -f $2`
LUSTRE_MODEL=$INDIR/`ls $INDIR | grep "lus" | grep -v "obligations"`
BASENAME=`basename $LUSTRE_MODEL .lus`
IS_CLEAR_OUTDIR=$IS_MEASURE_OBC && $IS_GENERATE_TRACE
MASTER_SUITE_DIR=$OUTDIR/suite/splitted
MAX_PARALLEL=$MAX_CORES*3

HEADER="$PURPLE[config.sh]$ENDL"

function join_by() {
  local IFS="$1"
  shift
  echo "$*";
}

function get_config() {
  echo -e "  COMPILER: $(green $COMPILER) \n" \
    " COVERAGE_CRITERIA: $(green $(join_by , ${COVERAGE_CRITERIA[@]})) \n" \
    " ORACLE_KIND: $(green $ORACLE_KIND) \n" \
    " OBC_TYPES: $(green $(join_by , ${OBC_TYPES[@]})) \n" \
    " N_MUTANTS: $(green $N_MUTANTS) \n" \
    " N_TEST_SUITES: $(green $N_TEST_SUITES) \n" \
    " \n" \
    " IS_UNIVERSAL_SUITE: $(green $IS_UNIVERSAL_SUITE) \n" \
    " IS_GENERATE_TESTS: $(green $IS_GENERATE_TESTS) \n" \
    " IS_GENERATE_MUTANTS: $(green $IS_GENERATE_MUTANTS) \n" \
    " IS_CHECK_EQUIVALENCE: $(green $IS_CHECK_EQUIVALENCE) \n" \
    " IS_MEASURE_OBC: $(green $IS_MEASURE_OBC) \n" \
    " IS_GENERATE_TRACE: $(green $IS_GENERATE_TRACE) \n" \
    " \n" \
    " MAX_CORES: $(green $MAX_CORES) \n" \
    " JVM_MEM: $(green $JVM_MEM) \n" \
    " MC_TIMEOUT: $(green $MC_TIMEOUT) \n" \
    " IS_DEBUG: $(green $IS_DEBUG) \n"
}

function is_absolute_path() {
  if [ "$(echo "$1" | cut -c1)" == "/" ]; then return 0; else return -1; fi
}

function print_line {
  printf "%0.s-" {1..80}
  printf "\n"
}

function green {
  w=$1
  [ "$2" ] && w=$w$2
  [ "$3" ] && w=$w$3
  [ "$4" ] && w=$w$4
  [ "$5" ] && w=$w$5
  echo -e "$GREEN$w$ENDL"
}

function exception() {
  # $1: prefix (raised by)
  # $2: exception string
  if [ "$#" -ne 2 ]; then
    echo -e "\n$REDexception(): Illegal number of arguments$ENDL\n" 1>&2
  fi
  loc=$1; msg=$2; echo -e "${RED}ERROR at ${PURPLE}$loc: $ERROR$msg$ENDL" 1>&2
}

function make_and_get_dir() {
  # make a directory $1 if it doesn't exist, and echoes its absolute path.
  [ "$#" -ne 1 ] && { exception "make_and_get_dir()" "Illegal #args"; exit; }
  dir=$1
  if [ -e $dir ]; then
    if [ ! -d $dir ]; then
      exception "make_and_get_dir($dir):" "File exists but not a directory!";
      exit 1;
    fi
  else
    # file/dir does not exist
    mkdir $dir
  fi
  echo $dir
}

function get_lustre_model() {
  [ "$#" -ne 0 ] \
    && { exception "get_lustre_model()" "Illegal #args"; exit; } \
    || echo $INDIR/`ls $INDIR | grep "lus" | grep -v "obligations"`
}

function get_master_suite() {
  [ "$#" -ne 0 ] && { exception "get_master_suite()" "Illegal #args"; exit 1; }
  get_test_suite_path "obc"
}

function get_test_suite_path() {
  # $1: coverage criterion {branch, condition, decision, mcdc, random, obc}
  [ "$#" -ne 1 ] \
    && { exception "get_test_input_file()" "Illegal #args"; exit; } \
    || { crit=$1; echo "$OUTDIR/suites/$BASENAME.${crit}_tests.csv"; }
}

function get_obligation_path() {
  # $1: coverage criterion {branch, condition, decision, mcdc, random, obc}
  if [ "$#" -ne 1 ]; then
    exception "get_obligation_path()" "Illegal #args"
    exit
  fi
  crit=$1
  echo "$INDIR/obligations/${BASENAME}.${crit}_obligations.lus"
}

function get_obligation_trace_path() {
  # $1: coverage criterion {branch, condition, decision, mcdc, random, obc}
  if [ "$#" -ne 1 ]; then
    exception "get_obligation_trace_path()" "Illegal #args"
    exit
  fi
  crit=$1
  suitename=`basename $(get_test_suite_path $crit)`
  echo "$OUTDIR/traces/$suitename/obligationCoverage/${BASENAME}.${crit}_obligations_trace.csv"
}

function get_obligation_oracle_path() {
  # $1: coverage criterion {branch, condition, decision, mcdc, random, obc}
  if [ "$#" -ne 1 ]; then
    exception "get_obligation_oracle_path()" "Illegal #args"
    exit
  fi
  crit=$1
  echo "$INDIR/obligations/${BASENAME}.${crit}_obligations.lus.oracle.csv"
}

function get_oracle() {
  [ "$#" -ne 1 ] && { exception "get_oracle()" "Illegal #args"; exit; }
  okind=$1; echo $INDIR/${BASENAME}.${okind}_oracle.csv
}

function get_trace_dir() {
  [ "$#" -ne 1 ] && { exception "get_trace_dir()" "Illegal #args"; exit; }
  crit=$1; make_and_get_dir "$OUTDIR/traces/${BASENAME}.${crit}_tests.csv/"
}

function get_traces() {
  [ "$#" -ne 1 ] && { exception "get_traces()" "Illegal #args"; exit; }
  crit=$1
  tdir=$(get_trace_dir $crit)
  if [ $(ls $tdir | wc -w) -eq 0 ]; then
    exception "get_traces()" "No trace in $tdir"
    exit 1
  else
    echo `ls $tdir`
  fi
}

function get_coverage_matrix_path() {
  # $1: coverage criterion {branch, condition, decision, mcdc, random, obc}
  [ "$#" -ne 1 ] \
    && { exception "get_coverage_matrix_path()" "Illegal #args"; exit; }
  crit=$1; echo "$INDIR/obligations/${BASENAME}.${crit}_obligations_coverage.csv";
}

function get_oobc_coverage_matrix() { #TODO:test @ 12/13/17
  [ "$#" -ne 1 ] \
    && { exception "get_oobc_coverage_matrix()" "Illegal #args"; exit; }
  bin=$1; echo "$(get_bintrace_dir $bin)/coverage.csv"

}

function get_mutant_list() {
  # $1: coverage criterion {branch, condition, decision, mcdc, random, obc}
  if [ "$#" -ne 1 ]; then
    exception "get_mutant_list()" "Illegal #args"
    exit 1
  else
    cov=$1; base=${BASENAME}
    echo "$OUTDIR/traces/$base.${cov}_tests.csv/$base.${cov}.mutants.csv"
  fi
}

function get_splitted_test_cases() {
  [ "$#" -ne 0 ] \
    && { exception "get_splitted_test_cases()" "Illegal #args"; exit 1; }
  tests=`ls $OUTDIR/suites/splitted/*.csv | grep -v "universal"`
  if [ $(echo $tests | wc -w) -eq 0 ]; then
    exception "get_splitted_test_cases()" "No splitted test cases!"
    exit 1
  else
    echo $tests
  fi
}

function get_binaries() {
  [ "$#" -ne 0 ] && { exception "get_binaries()" "Illegal #args"; exit 1; }
  bs=$(ls $(get_bin_dir) | grep -v "\." | grep -v "make" | grep -v "mutants" | grep -v "lst")
  if [ $(echo $bs | wc -w) -gt 0 ]; then echo $bs
  else exception "get_binaries() " "No binaries!"; exit 1;
  fi
  return
}

function get_mutants() {
  [ "$#" -ne 0 ] && { exception "get_mutants()" "Illegal #args"; exit 1; }
  ms=$(ls $INDIR/mutants/)
  [ "$(echo $ms | wc -w)" -eq "0" ] \
    && { exception "get_mutants()" "no mutants!"; exit 1; }
  echo $ms
}

function get_binary_mutants() {
  [ "$#" -ne 1 ] && { \
    exception "get_binary_mutants()" "Illegal #args"; exit 1; }
  bin=$1; echo $(ls $(get_binary_mutants_dir $bin))
}

function get_binary_mutants_dir() {
  [ "$#" -ne 1 ] && { \
    exception "get_binary_mutants_dir()" "Illegal #args"; exit 1; }
  bin=$1; echo "$(get_bin_dir)/${bin}-mutants"
}

function get_csrc() {
  [ "$#" -ne 0 ] && { exception "get_csrc()" "Illegal #args"; exit 1; }
  c="$OUTDIR/bin/$BASENAME.c"
  [ -f $c ] && echo $c || { exception "get_csrc()" "$c doesn't exist"; exit 1; }
}

function get_flist() {
  [ "$#" -ne 0 ] && { exception "get_flist()" "Illegal #args"; exit 1; }
  c="$OUTDIR/bin/$BASENAME.flist"
  [ -f $c ] && echo $c || { exception "get_flist()" "$c doesn't exist"; exit 1; }
}

function get_olist() {
  [ "$#" -ne 0 ] && { exception "get_olist()" "Illegal #args"; exit 1; }
  c="$OUTDIR/bin/$BASENAME.olist"
  [ -f $c ] && echo $c || { exception "get_olist()" "$c doesn't exist"; exit 1; }
}

function get_mutant_cnt() {
  [ "$#" -ne 0 ] && { exception "get_mutants_cnt()" "Illegal #args"; exit 1; }
  echo $(get_mutants) | wc -w
}

function get_test_suites() {
  [ "$#" -ne 0 ] && { exception "get_test_suites()" "Illegal #args"; exit 1; }
  echo `ls $OUTDIR/suites/` | grep "csv"
}

function relpath() {
  [ "$#" -ne 1 ] && { exception "relpath()" "Illegal #args"; exit 1; }
  ret=$(readlink -f $1 --relative-to=.)
  [ $? != 0 ] && exception "relpath()" "relpath failed with $1" \
    || { echo $ret; exit 1; }
}

function get_covs() {
  # get coverage files for a given binary & criterion
  [ "$#" -ne 2 ] && { exception "get_covs()" "Illegal #args"; exit 1; }
  bin=$1; crit=$2
  covdir=$(get_cov_dir $crit)
  files=$(ls $covdir/$bin/*)
  [ `echo $files | wc -w` -gt 0 ] && echo $files || {\
    exception "get_covs()" "No coverage files in $covdir"; exit 1; }
}

function get_criteria() {
  [ "$#" -ne 0 ] && { exception "get_criteria()" "Illegal #args"; exit 1; }
  criteria=""
  for cov in ${COVERAGE_CRITERIA[@]}; do
    criteria+=$cov" "
  done
  echo ${criteria%" "}
}

function get_cov() {
  # get coverage (info) file (.cov) for a given criterion, binary and test case
  [ "$#" -ne 3 ] && { exception "get_cov()" "Illegal #args"; exit 1; }
  crit=$1; bin=$2; tc=$3; echo "$OUTDIR/cov/$crit/$bin/`basename $tc .csv`.cov"
}

function get_binary() {
  [ "$#" -ne 1 ] && { exception "get_binary()" "Illegal #args"; exit 1; }
  bin=$1; p=$OUTDIR/bin/$bin
  [ -f $p ] && echo $p || { \
    exception "get_binary()" "Binary $p doesn't exist"; exit 1; }
}

function get_reduced_suite() {
  # $1: coverage criterion {branch, condition, decision, mcdc, random, obc}
  [ "$#" -ne 1 ] \
    && { exception "get_reduced_suite()" "Illegal #args"; return -1; } \
    || { crit=$1; echo "$OUTDIR/suites/reduced/${crit}.csv"; }
}

function get_figures_dir() {
  [ "$#" -ne 0 ] && { exception "get_figures_dir()" "Illegal #args"; exit 1; }
  make_and_get_dir "$OUTDIR/results/figures"
}

function get_report_dir() {
  [ "$#" -ne 0 ] && { exception "get_report_dir()" "Illegal #args"; exit 1; }
  make_and_get_dir "$OUTDIR/results/scores"
}

function get_report() {
  [ "$#" -ne 1 ] && { exception "get_report()" "Illegal #args"; exit 1; }
  cov=$1; dir=$(get_report_dir); echo "$dir/$cov.csv"
}

function get_bintrace() {
  # get bintrace file for a given binary, mutant, and test suite
  [ "$#" -ne 3 ] && { exception "get_bintrace()" "Illegal #args"; exit 1; }
  bin=$1; binmutant=$2; tc=$3
  echo "$(get_bintrace_dir $bin $binmutant)/$(basename $tc ".csv")_trace.csv"
}

function get_bintrace_fast() {
  # get bintrace file for a given binary, mutant, and test suite
  [ "$#" -ne 3 ] && { exception "get_bintrace_fast()" "Illegal #args"; exit 1; }
  bin=$1; binmutant=$2; tc=$3
  echo "$OUTDIR/bintraces/$bin/$binmutant/$(basename $tc ".csv")_trace.csv"
}

function get_bintrace_dir() {
  if [ "$#" -eq 0 ]; then
    make_and_get_dir $OUTDIR/bintraces
  elif [ "$#" -eq 1 ]; then
    bin=$1; make_and_get_dir $(get_bintrace_dir)/$bin
  elif [ "$#" -eq 2 ]; then
    bin=$1; mutant=$2; make_and_get_dir "$(get_bintrace_dir $bin)/$mutant"
  else
    exception "get_bintrace_dir()" "Illegal #args: either 0 or 1"; exit 1;
  fi
}

function get_bin_dir() {
  [ "$#" -ne 0 ] && { exception "get_bin_dir()" "Illegal #args"; exit 1; }
  make_and_get_dir $OUTDIR/bin
}

function get_cov_dir() {
  if [ "$#" -eq 0 ]; then
    make_and_get_dir $OUTDIR/cov
  elif [ "$#" -eq 1 ]; then
    crit=$1; make_and_get_dir $OUTDIR/cov/$crit
  else
    exception "get_cov_dir()" "Illegal #args: either 0 or 1 (criterion)"
    exit 1
  fi
}

function make_binaries() {
  [ "$#" -ne 0 ] && { exception "make_binaries()" "Illegal #args"; exit 1; }
  bindir=$(get_bin_dir)
  # return if file exists in the $bindir.
  [ $(ls $bindir | wc -w) -gt 0 ] && return
  # copy the source and makefile
  echo -e "$HEADER ${BLUE}Copying sources from$1"
  cp $INDIR/$BASENAME.{c,olist,flist} $INDIR/makefile $bindir
  # make run, and cov for each bin & each test
  cd $bindir
  $IS_DEBUG && enable_debug=1 || enable_debug=0
  make all SRC=$(get_csrc) DBG=$enable_debug CC=$COMPILER
  cd $TOOL_ROOT
}

function print_parallel_progress() {
  current=$1; total=$2; what=$3
  [ "$#" -ne 3 ] && { exception "print_progress()" "Illegal #args"; exit 1; }
  while [ `jobs | wc -l` -gt $MAX_PARALLEL ]; do
    #printf "\r\tCompleted $GREEN%3d$ENDL out of $GREEN%3d$ENDL %s" $current $total $what
    sleep 0.1
  done
}

function get_static_info() {
  bin=$1;
  [ "$#" -ne 1 ] && { exception "get_static_info()" "Illegal #args"; exit 1; }
  echo "$(get_bin_dir)/${bin}_static.json"
}

function is_obc_measured() {
  [ "$#" -ne 0 ] && { exception "is_obc_measured()" "Illegal #args"; exit 1; }
  n_covs=$(ls "$(get_cov_dir "obc")"/* | wc -w)
  n_test_cases=$(echo "$(get_splitted_test_cases)" | wc -w)
  [ $n_covs -ge $((n_test_cases * 4)) ] && return 0 || return -1
}
