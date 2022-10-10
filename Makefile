CC = g++
SRC = src
OBJ = obj
INC = include
OBJS = $(OBJ)/tp.o $(OBJ)/graph.o
HDRS =  $(INC)/graph.hpp
CFLAGS = -I$(INC)
INP = input

EXE = ./tp01
all: $(EXE)
	$(EXE) < input.txt
		
tp01: $(OBJS)
	$(CC) -o tp01 $(OBJS) 
$(OBJ)/tp01.o: $(HDRS) $(SRC)/tp01.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp01.o $(SRC)/tp01.cpp
$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.cpp

compare:
	for number in 1 2 3 4 5 6 7 8; do \
	$(EXE) < input/entrada_$$number.txt > $(SRC)/saida.txt; \
	echo "comparing $$number"; \
	diff --color $(SRC)/saida.txt output/saida_$$number.txt; \
	done