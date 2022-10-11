# TP  - Algoritmos

  

Aluno: João Vitor Santana Depollo

Matrícula: 2021039751

  

Este trabalho prático tem como finalidade determinar a satisfabilidade de propostas eleitorais de um candidato hipotético que deve acatar pelo menos uma proposta que agrada seus eleitores e remover pelo menos uma que seus eleitores reprovam, sem deixar de satisfazer todos seus eleitores. Neste contexto, ele pode acatar 2 propostas e remover 2, o sistema deve determinar se esse problema é satisfazível ou não. implementado com a utilização do algoritmo DFS, que é utilizado para realizar busca em profundidade com grafos.

  
  

### Detalhes de implementação

Este trabalho foi implementado com a linguagem C++, em um sistema WSL com a IDE Visual Studio Code

  

## Esturuta de dados

  

Neste trabalho, foi criado um TAD *Graph*, que possui uma lista de adjacência e alguns métodos auxiliares para determinar se o sistema é satisfazível ou não.

  

```cpp

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

```

O atributo **vertexes** representa a lista de adjacência em si. Como percorremos um vetor de listas, foi necessário transformar os valores negados em representações arbitrárias das afirmações. Por exemplo, temos 4 propostas ao todo. As propostas são representadas do 1 ao 4, já suas negações do 5 ao 8, em que -1 é:

  

quantidade de propostas + valor da afirmativa = 5

  

-2 -> 6

  

-3 -> 7

  

-4 -> 8

  

## Descrição dos métodos da classe Graph

  

### transposeGraph()

  

Transpõem o grafo, invertendo a direção de todas as arestas.

  

### opositValue()

  

Retorna a negação do valor, exemplo para 4 propostas:

  

```c++

opositValue(2)

6

opositValue(6)

2

```

### restartVectors()

  

Zera os valores dos vetores de visitados e os da pilha de recursão.

  

### addEdget()

  

Direciona um vértice a outro

  

### checkUnsatisfiable()

  

Checa se um mesmo elemento possui sua negação em um CFC. Para isso ele adiciona elementos que foram lidos na lista, e  para cada elemento da lista de adjacência, se existir a negação dele no ciclo, retorna true.

  

### DFS(int size)

Identifica ciclos e chama **checkUnsatisfiable** para analisar a CFC

  

### isUnsatisfiable()

Chama **transposeGraph()** e chama a função DFS para todos os vértices que foram adicionados.

  

# Compilação
Na pasta raiz do projeto com o arquivo de entrada **casoTeste01.txt**, basta executar o comando make que sairá o output.