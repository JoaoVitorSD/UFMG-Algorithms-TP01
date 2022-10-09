#include "graph.hpp"


Graph::Graph(int size)
{
    this->size = size;
    adj = new std::list<int>[size];
}
void Graph::addEdge(int size, int w){
    //adiciona vértice w ao v
    adj[size].push_back(w);
}

void Graph::printGraph(){
    for(int i = 0;i<size;i++){
        auto l_front = adj[i].begin();
        for( int j = 0;j<adj[i].size();j++){
            std::cout << *l_front<<" ";
            std::advance(l_front, 1);
        }
        std::cout<<"\n";
    }
}