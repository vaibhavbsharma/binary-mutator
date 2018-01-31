#!/usr/bin/env python

import subprocess, sys, os

#TODO
# exec find -size 0
# show the set of mutants that crashed


def direxists(mydir):
    return os.path.isdir(os.path.join(os.getcwd(), mydir))

def extract_bin_mutant_pair(line):
    splitted = line.strip().split('/')
    binname = splitted[-3]
    mutant = splitted[-2]
    return binname, mutant

def get_faulty_mutants(outdir):
    assert direxists(outdir)
    faulty_mutants = {}
    CMD = 'find %s -size 0' % outdir
    p = subprocess.Popen(CMD, stdout=subprocess.PIPE, shell=True,
            executable='/bin/bash')
    while True:
        line = p.stdout.readline()
        if line != '':
            #the real code does filtering here
            binname, mutant = extract_bin_mutant_pair(line)
            if binname not in faulty_mutants:
                faulty_mutants[binname] = set()
            faulty_mutants[binname].add(mutant)
        else:
            break
    return faulty_mutants

def print_mutants(faulties):
# dictionary of sets indexed by string
    for binary in faulties:
        print '-----*| ' + binary + ' |*-----'
        for f in faulties[binary]:
            print f
        print ''

def main():
    if len(sys.argv) != 2:
        print "invalid #args"
        return

    outdir = sys.argv[1]
    if not direxists(outdir):
        print "directory %s doesn't exist" % outdir
        return

    faulties = get_faulty_mutants(outdir)
    print_mutants(faulties)


if __name__ == '__main__':
    main()

