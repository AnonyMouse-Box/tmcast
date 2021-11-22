# Makefile for compilation
IDIR = ./inc
SDIR = ./src
ODIR = ./build
LDIR = ./lib

CC = gcc
LIBS = 
CFLAGS = -I${IDIR} -Wall -Wextra -Werror
LDFLAGS = 

_SRC = main.c flags.c hash.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ = main.o flags.o hash.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

INPUT_OBJ = main.o flags.o
_INPUT_DEPS = input.h
INPUT_DEPS = $(patsubst %,$(IDIR)/%,$(_INPUT_DEPS))

HASH_OBJ = hash.o
_HASH_DEPS = hash.h
HASH_DEPS = $(patsubst %,$(LDIR)/inc/%,$(_HASH_DEPS))

tmcast: ${OBJ}
     ${CC} $^ ${LIBS} ${CFLAGS} ${LDFLAGS} -o $@

#${ODIR}/%.o: ${SDIR}/%.c ${DEPS}
     #${CC} -c $< ${CFLAGS} -o $@

${INPUT_OBJ}: %.c ${INPUT_DEPS}
     ${CC} -c $< ${CFLAGS} -o $@

${HASH_OBJ}: %.c ${HASH_DEPS}
     ${CC} -c $< ${CFLAGS} -o $@

.PHONY: all
all: tmcast

.PHONY: install
install: all
     @echo "You must be root to install."
     chmod +x hello
     mv tmcast /usr/local/bin/tmcast

.PHONY: clean
clean:
     -rm -f tmcast *.o *~ core
