# Makefile for compilation
# Set directories
IDIR = ./inc
SDIR = ./src
ODIR = ./build
LDIR = ./lib
ODIR_LIB = ${ODIR}/lib
LDIR_INC = ${LDIR}/inc

# Set compiler settings
CC = gcc
LIBS = 
CFLAGS = -I${IDIR} -Wall -Wextra -Werror
LDFLAGS = 

# Build object file list
_OBJ = main.o flags.o
OBJ = $(patsubst %,${ODIR}/%,${_OBJ})

# Build local library list
_LLIB = hash.o
LLIB = $(patsubst %,${ODIR_LIB}/%,${_LLIB})

# Build dependencies list
_DEPS = input.h
DEPS = $(patsubst %,${IDIR}/%,${_DEPS})

# Final link for executable
tmcast: ${OBJ} ${LLIB}
     ${CC} $^ ${LIBS} ${CFLAGS} ${LDFLAGS} -o $@

# Compile object files
${ODIR}/%.o: ${SDIR}/%.c ${DEPS}
     mkdir -p ${ODIR}
     ${CC} -c $< ${CFLAGS} -o $@

# Compile local libraries
${ODIR_LIB}/%.o: ${LDIR}/%.c ${LDIR_INC}/%.h
     mkdir -p ${ODIR_INC}
     ${CC} -c $< ${CFLAGS} -o $@

# Catch for make all
.PHONY: all
all: tmcast

# Install program on in $PATH user binary folder
.PHONY: install
install: all
     @echo "You must be root to install."
     chmod +x tmcast
     mv tmcast /usr/local/bin/tmcast

# Clean up build files and folders
.PHONY: clean
clean:
     -rm -f tmcast ${ODIR}/*.o ${ODIR_LIB}/.o *~ core ${IDIR}/*~ ${LDIR}/*~ ${LDIR_INC}/*~
     -rm -rf ${ODIR}
