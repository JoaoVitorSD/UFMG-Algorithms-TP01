CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/tp01.o $(OBJ)/graph.o
HDRS =  $(INC)/graph.hpp
CFLAGS = -g -Wall -c -I$(INC)
INP = input

EXE = ./tp01.out
all: $(EXE)
	$(EXE) < test/in.txt > test/try.txt
		
$(BIN)/tp01: $(OBJS)
	$(CC) -pg -o $(BIN)/tp01 $(OBJS) $(LIBS)
$(OBJ)/tp01.o: $(HDRS) $(SRC)/tp01.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp01.o $(SRC)/tp01.cpp
$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.cpp

compare:
	for number in 1 2 3 4 5 6 7 8; do \
	$(EXE) < input/entrada_$$number.txt > $(SRC)/saida.txt; \
	echo "comparing $$number"; \
	diff --color $(SRC)/saida.txt outp01ut/saida_$$number.txt; \
	done