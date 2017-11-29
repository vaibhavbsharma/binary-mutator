#!/usr/bin/perl

use strict;

die "Usage: make-mutants.pl <absolute path to binary> [<function name>] [<debug>]"
  unless @ARGV >= 1;
my ($binary,$fn_name,$debug);
my $length = @ARGV;
$fn_name = "";
if($length == 2) {
    ($binary, $fn_name) = @ARGV;
} elsif($length == 3) {
    ($binary, $fn_name, $debug) = @ARGV; 
}
my $output;
while(1) {
  if($debug==1 || $debug=="true") {
    $output = `REPLACEINSN_DEBUG=1 ./ReplaceInsn $binary $fn_name`;
  } else {
      $output = `./ReplaceInsn $binary $fn_name`;
  }
  print $output;
  if(index($output, "No mutations found") != -1) { last; }
}
