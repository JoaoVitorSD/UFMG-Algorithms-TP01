CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/tp.o $(OBJ)/graph.o
HDRS =  $(INC)/graph.hpp
CFLAGS = -g -Wall -c -I$(INC)
INP = input

EXE = ./$(BIN)/tp
all: $(EXE)
	$(EXE)
		
$(BIN)/tp: $(OBJS)
	$(CC) -pg -o $(BIN)/tp $(OBJS) $(LIBS)
$(OBJ)/tp.o: $(HDRS) $(SRC)/tp.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp.o $(SRC)/tp.cpp
$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.cpp

compare:
	for number in 1 2 3 4 5 6 7 8; do \
	$(EXE) < input/entrada_$$number.txt > $(SRC)/saida.txt; \
	echo "comparing $$number"; \
	diff --color $(SRC)/saida.txt output/saida_$$number.txt; \
	done