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
CFLAGS = -I ${IDIR} -I ${LDIR_INC} -Wall -Wextra -Werror
LDFLAGS = 

# Name binary executable
EXE = ${ODIR}/binary

# Build object file list
_OBJ = main.o flags.o
OBJ = $(patsubst %,${ODIR}/%,${_OBJ})

# Build local library list
_LLIB = hash.o
LLIB = $(patsubst %,${ODIR_LIB}/%,${_LLIB})

# Build dependencies list
_DEPS = input.h
DEPS=$(patsubst %,${IDIR}/%,${_DEPS})

# Catch for make all
.PHONY: all
all: ${EXE}

# Final link for executable
${EXE}: ${OBJ} ${LLIB}
	${CC} $^ ${LIBS} ${CFLAGS} ${LDFLAGS} -o $@

# Compile object files
${ODIR}/%.o: ${SDIR}/%.c ${DEPS}
	mkdir -p ${ODIR}
	${CC} -c $< ${CFLAGS} -o $@

# Compile local libraries
${ODIR_LIB}/%.o: ${LDIR}/%.c ${LDIR_INC}/%.h
	mkdir -p ${ODIR_LIB}
	${CC} -c $< ${CFLAGS} -o $@

# Install program on in $PATH user binary folder
.PHONY: install
install: all
	@echo "You must be root to install."
	chmod +x ${EXE}
	cp ${EXE} /usr/local/bin/tmcast

# Clean up build files and folders
.PHONY: clean
clean:
	-rm -f ${EXE} ${ODIR}/*.o ${ODIR_LIB}/.o *~ core ${IDIR}/*~ ${LDIR}/*~ ${LDIR_INC}/*~
	-rm -rf ${ODIR}
