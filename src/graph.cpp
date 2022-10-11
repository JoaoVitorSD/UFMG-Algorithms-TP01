#include "graph.hpp"

Graph::Graph(int size)
{
    this->size = size;
    vertexes = new std::list<int>[size];
    visited = new bool[size];
    recStack = new bool[size];
}
void Graph::addEdge(int pos, int w)
{
    // adiciona vértice w ao pos
    for(int i : vertexes[pos]){
        if(i==w){
            return;
        }
    }
    vertexes[pos].push_back(w);
}

void Graph::printGraph()
{
    //usado para teste, printa o grafo
    for (int i = 1; i < size; i++)
    {
        auto l_front = vertexes[i].begin();
        std::cout << i << " - ";
        for (int x : vertexes[i])
        {
            std::cout << x<<" ";
        }
        std::cout << "\n";
    }
}
int Graph::opositValue(int number){
    //negative or oposite value of sentence
    int valueAux = number;
    if(number>=(size/2)){
        valueAux -= (size/2);
    }else{
    valueAux += (size/2);
    }
    return valueAux;
}

void Graph::transposeGraph()
{
    std::list<int> * auxGraph = new std::list<int>[size];
    for(int i =0;i<size;i++){
        for(int x : vertexes[i]){
        auxGraph[x].push_back(i);
        }
    }
    vertexes = auxGraph;
}
bool contains(std::list<int> list, int value){
    for(int x : list){
        if(x==value){
            return true;
        }
    }
    return false;
}
bool Graph::checkUnsatisfiable(int vertex, std::list<int> * added)
{
    for (int x : vertexes[vertex])
    {
       if(contains(*added,opositValue(x))){
            return true;
       }else if(contains(*added,x)){
            return false;
       }else{
        added->push_back(x);
        return checkUnsatisfiable(x,added);
       }
    }
}
bool Graph::DFS(int v)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
        for (int i : vertexes[v])
        {
            if (!visited[i] && DFS(i))
            {
                    return true;
            }
            else if (recStack[i])
            {
                    return true;
                }
        }
    }
    recStack[v] = false;
    return false;
}
void Graph::restartVectors(){
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
}
bool Graph::isUnsatisfiable()
{
   transposeGraph();
   restartVectors();
    for (int i = 1; i < size; i++)
    {
        if (!visited[i] && DFS(i))
        {
            if(checkUnsatisfiable(i,new std::list<int>[size])){
            return true;
            }
        }
    }
    return false;
}