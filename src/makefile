# Makefile for compilation
tmcast: main.c flags.c hash.c
     gcc -o tmcast main.c flags.c hash.c -I../includes

.PHONY: all
all: tmcast

.PHONY: install
install: all
     chmod +x tmcast
     mv tmcast /usr/local/bin/tmcast

.PHONY clean
clean:
     rm *.o tmcast
