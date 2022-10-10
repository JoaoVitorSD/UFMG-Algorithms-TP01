#include<bits/stdc++.h>
class Graph{
    int size;     // No. of vertices
    std::list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int size, bool visited[], bool *rs);  // used by isCyclic()
    bool checkInsatifability(int vertex, std::list<int>* added);
    int opositValue(int value);
    public : Graph(int size); // Constructor
    void tranporGraph ();
    void addEdge(int size, int w);   // to add an edge to graph
    bool isCyclic();
    void printGraph(); // returns true if there is a cycle in this graph
};
 