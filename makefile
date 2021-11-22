# Makefile for compilation
IDIR = ./inc
SDIR = ./src
ODIR = ./build
LDIR = ./lib
LDIR_INC = ${LDIR}/inc

CC = gcc
LIBS = 
CFLAGS = -I${IDIR} -Wall -Wextra -Werror
LDFLAGS = 

#_SRC = main.c flags.c hash.c
#SRC = $(patsubst %,${SDIR}/%,${_SRC})

_OBJ = main.o flags.o hash.o
OBJ = $(patsubst %,${ODIR}/%,${_OBJ})

_INPUT_OBJ = main.o flags.o
INPUT_OBJ = $(patsubst %,${ODIR}/%,${_INPUT_OBJ})

_INPUT_DEPS = input.h
INPUT_DEPS = $(patsubst %,${IDIR}/%,${_INPUT_DEPS})

LIB_OBJ = hash.o
_LIB_DEPS = hash.h
LIB_DEPS = $(patsubst %,${LDIR_INC}/%,${_LIB_DEPS})

tmcast: ${OBJ}
     ${CC} $^ ${LIBS} ${CFLAGS} ${LDFLAGS} -o $@

#${ODIR}/%.o: ${SDIR}/%.c ${DEPS}
     #${CC} -c $< ${CFLAGS} -o $@

${INPUT_OBJ}: %.c ${INPUT_DEPS}
     ${CC} -c $< ${CFLAGS} -o $@

${LIB_OBJ}: %.c ${LIB_DEPS}
     ${CC} -c $< ${CFLAGS} -o $@

.PHONY: all
all: tmcast

.PHONY: install
install: all
     @echo "You must be root to install."
     chmod +x tmcast
     mv tmcast /usr/local/bin/tmcast

.PHONY: clean
clean:
     -rm -f tmcast ${ODIR}/*.o *~ core ${IDIR}/*~ ${LDIR}/*~ ${LDIR_INC}/*~
