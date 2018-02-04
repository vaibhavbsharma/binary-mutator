# -*- coding: utf8 -*-
import sys
from os import listdir
from os.path import isfile, join

if len(sys.argv) < 3:
    print "Usage: python rewrite-binary.py <binary-with-absolute-path> <original/mutated>"
    sys.exit()

filename = sys.argv[1]
corrected = 0
new_filename = filename + "-fixed"
with open(filename, 'rb') as f:
    data = f.read()
with open(filename, 'wb') as f:
    if '\xe8\x00\x00\x00\x00\x81' in data and sys.argv[2] == "mutated": #fixes weird callq in mutant binary
        corrected = 1
        print "position of weird-callq: ",data.find('\xe8\x00\x00\x00\x00\x81')
        f.write(data.replace(b'\xe8\x00\x00\x00\x00\x81', b'\x90\x90\x90\x90\x90\x81'))
    elif '\xe9\x00\x00\x00\x00' in data and sys.argv[2] == "original": #fixes jmp-to-next-insn in original binary
        corrected = 1
        print "position of jmp-to-next: ",data.find('\xe9\x00\x00\x00\x00')
        f.write(data.replace(b'\xe9\x00\x00\x00\x00', b'\x90\x90\x90\x90\x90'))
    elif '\x4d\x89\x10' in data and sys.argv[2] == "mutated": #fixes 8-byte setCC mutation writes in mutant binary
        corrected = 1
        print "position of setCC-8-byte-write: ", data.find('\x4d\x89\x10')
        f.write(data.replace(b'\x4d\x89\x10', b'\x4d\x88\x10'))
    # elif '\x4d\x8b\xd3' in data: #converts mov r11 to r10 into a noop
    #     corrected = 1
    #     f.write(data.replace(b'\x4d\x8b\xd3', b'\x90\x90\x90'))
    if corrected == 1:
        print "rewrote ",filename
    else: 
        f.write(data)
f.close()
