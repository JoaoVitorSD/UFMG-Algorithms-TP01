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
	$(EXE) < casoTeste01.txt;
tp01.out: $(OBJS)
	$(CC)  -o tp01.out $(OBJS) $(LIBS)
$(OBJ)/tp01.o: $(HDRS) $(SRC)/tp01.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp01.o $(SRC)/tp01.cpp
$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.cpp

clean:
	rm obj/*