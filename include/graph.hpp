#include <list>
#include <stdio.h>
#include <iostream>
class Graph
{
    int size;                                              // No. of vertices
    std::list<int> *adj;                                   // Pointer to an array containing adjacency lists
    bool DFS(int size); // used by isCyclic()
    bool checkInsatifability(int vertex, std::list<int> *added);
    void restartVectors();
    int opositValue(int value);
    bool *visited ;
    bool *recStack;

public:
    Graph(int size); // Constructor
    void transposeGraph();
    void addEdge(int size, int w); // to add an edge to graph
    bool isCyclic();
    void printGraph(); // returns true if there is a cycle in this graph
};
