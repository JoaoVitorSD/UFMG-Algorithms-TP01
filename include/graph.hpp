#include <list>
#include <stdio.h>
#include <iostream>
class Graph
{
    int size;                                             
    std::list<int> *vertexes;                                  
    bool DFS(int size); 
    bool checkUnsatisfiable(int vertex, std::list<int> *added);
    void restartVectors();
    int opositValue(int value);
    bool *visited ;
    bool *recStack;

public:
    Graph(int size); 
    void transposeGraph();
    void addEdge(int size, int w);
    bool isUnsatisfiable();
    void printGraph(); 
};
