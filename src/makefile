# Makefile for compilation
INC = -I "../includes"
CC = gcc
LIBS = 
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = 
OBJ = main.o flags.o hash.o

tmcast: ${OBJ}
     ${CC} $^ ${LIBS} ${INC} ${CFLAGS} ${LDFLAGS} -o $@
     
main.o flags.o: input.h
     ${CC} -c $< ${CFLAGS} ${INC} -o $@

hash.o: hash.h
     ${CC} -c $< ${CFLAGS} ${INC} -o $@

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
