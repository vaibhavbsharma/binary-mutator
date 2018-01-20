CC=gcc
DBG=0
ifeq ($(CC), ccomp)
	CFLAGS=-DDEBUG=$(DBG) -w
else
	CFLAGS=-DDEBUG=$(DBG) -w -std=c11 -fno-inline
endif
SRC=microwaveCollated.c

define _dump
	objdump -d $(1) -M intel-mnemonic > $(1).dump
endef

define dump
	touch makefile
endef

all: o1 o3

o0: $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o o0 -O0
	$(call dump, o0)

o1: $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o o1 -O1
	$(call dump, o1)

o2: $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o o2 -O2
	$(call dump, o2)

o3: $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o o3 -O3
	$(call dump, o3)

os: $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o os -Os
	$(call dump, os)

oi: $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o oi -finline-small-functions
	$(call dump, oi)

clean:
	rm o0 o1 o2 o3 os oi *.dump *.cov *.pincov

