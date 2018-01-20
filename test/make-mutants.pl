#!/usr/bin/perl

use strict;

die "Usage: make-mutants.pl <absolute path to binary> [<function name>] [<debug>]"
  unless @ARGV >= 1;
my ($binary,$fn_name,$debug);
my $length = @ARGV;
$fn_name = "";

my $output;
while(1) {
  if($length == 1) { 
      ($binary) = @ARGV; 
      $output = `./ReplaceInsn $binary`;
  } elsif($length == 2) {
      ($binary, $fn_name) = @ARGV;
      $output = `./ReplaceInsn $binary $fn_name`;
  } elsif($length == 3) {
      ($binary, $fn_name, $debug) = @ARGV; 
      $output = `./ReplaceInsn $binary $fn_name $debug`;
  }
  print $output;
  if(index($output, "No mutations found") != -1) { last; }
}
