# TP  - Algoritmos

Aluno: João Vitor Santana Depollo
Matrícula: 2021039751

Este trabalho prático tem como finalidade determinar a satisfabilidade de propostas eleitorais de um candidato hipotético que deve acatar pelo menos uma proposta que agrada seus eleitores e remover pelo menos uma que seus eleitores reprovam, sem deixar de satisfazer todos seus eleitores. Neste contexto, ele pode acatar 2 proposts e remover 2, o sistema deve determinar se esse problema é satisfazível ou não. implementado com a utilização do  algoritmo DFS, que é utilizado para realizar busca em profundidade com grafos. 


### Detalhes de implementação
Este trabalho foi implemtado com a linguagem C++, em um sistema WSl com a IDE Visual Studio Code

## Esturuta de dados

Neste trabalho, foi criado um TAD *Graph*, que possui uma lista de adjacência e alguns métodos auxiliares para determinar se o sistema é satisfazível ou não.

```cpp
class Graph{

    int size;     // No. of vertices
    std::list<int> *adj;    // Pointer to an array containing adjacency lists
	bool isCyclicUtil(int size, bool visited[], bool *rs);  // used by isCyclic()
    bool checkInsatifability(int vertex, std::list<int>* added);
    int opositValue(int value);
    public : Graph(int size); // Constructor
    void tranporGraph ();
    void addEdge(int size, int w);   // to add an edge to graph
    bool isCyclic();
    void printGraph(); // returns true if there is a cycle in this graph
};
```
O atributo *adj* representa a lista de adjancência em si. Como percorremos um vetor de listar, foi necessário transformar os valores negados em representações arbitrárias das afirmações. Por exemplo, temos 4 propostas ao todo. As propostas são representadas do 1 ao 4, já suas negações do 5 ao 8, em que -1 é:
> quantidade de propostas+valor da afirmativa = 5
> -2 = 6
> -3 = 7
> -4 = 8

