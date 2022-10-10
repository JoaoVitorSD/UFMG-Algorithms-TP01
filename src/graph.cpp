#include "graph.hpp"

Graph::Graph(int size)
{
    this->size = size;
    adj = new std::list<int>[size];
}
void Graph::addEdge(int pos, int w)
{
    // adiciona vértice w ao v
    for(int i : adj[pos]){
        if(i==w){
            return;
        }
    }
    adj[pos].push_back(w);
}

void Graph::printGraph()
{
    for (int i = 1; i < size; i++)
    {
        auto l_front = adj[i].begin();
        std::cout << i << " - ";
        for (int x : adj[i])
        {
            std::cout << x<<" ";
        }
        std::cout << "\n";
    }
}
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if (visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        std::list<int>::iterator i;

        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
            {

                return true;
            }
            else if (recStack[*i])
            {
                return true;
            }
        }
    }
    recStack[v] = false; // remove the vertex from recursion stack
    return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in
// https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[size];
    bool *recStack = new bool[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for (int i = 0; i < size; i++)
    {
        if (!visited[i] && isCyclicUtil(i, visited, recStack))
        {
            return true;
        }
    }
    return false;
}