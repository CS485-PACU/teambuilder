#############################################################################
# File name:  Makefile
# Author:     chadd williams
# Date:       Sept 1, 2021
# Class:      CS360
# Assignment: 
# Purpose:    
#############################################################################

all: bin bin/main

ENSCRIPT_FLAGS=-C -T 2 -p - -M Letter -Ecpp --color -fCourier8
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all 

compiler=clang++-16
#compiler=g++

# clang
# https://clang.llvm.org/cxx_status.html
# clang 16 still uses c++2b to represent c++23
CPP_VERSION=c++2b
CFLAGS=-fstandalone-debug -g -Wall

# g++ (Linux)
# Version 10 or later
# CPP_VERSION=c++20
# Version 9 or earlier (Codespaces)
# Enable C++23 support
# CPP_VERSION=c++2b

bin:
	mkdir -p bin

bin/main: bin src/*.cpp include/*.h
	${compiler} -std=${CPP_VERSION} -o bin/main ${CFLAGS} src/*.cpp

valgrind: bin/main
	valgrind ${VALGRIND_FLAGS} bin/main

printAll:
	enscript ${ENSCRIPT_FLAGS}  include/*.h src/*.cpp test/*.cpp | ps2pdf - bin/src.pdf

runMe: bin/main
	bin/main
	
clean:
	rm -rf bin/main bin/*.o bin/*.pdf
