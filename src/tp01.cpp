#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "graph.hpp"

int main()
{
  int followers;
  int proposals;
  int *opinion = new int[4];
  int countedOpinion;
  while (std::cin)
  {
    std::cin >> followers;
    std::cin >> proposals;
    if (followers == 0 && proposals == 0)
    {
      break;
    }
    Graph *graph = new Graph(proposals*2+1);
    for (int i = 0; i < followers; i++)
    {
      std::cin>>opinion[0];
      std::cin>>opinion[1];
      std::cin>>opinion[2];
      std::cin>>opinion[3];
      for( int i = 0;i<4;i++){
      }
      if(opinion[0]==0){
        graph->addEdge(opinion[1],opinion[1]+proposals);
      }
      else if (opinion[1] == 0)
      {
        graph->addEdge(opinion[0], opinion[0] + proposals);
      }else{
        // A ou B é equivalente, ao somar com proposals, é equivalente a negação
        graph->addEdge(opinion[0]+proposals, opinion[1]);
        graph->addEdge(opinion[1]+proposals, opinion[0]);
      }
      if(opinion[2]==0){
        graph->addEdge(opinion[3],opinion[3]+proposals);
      }
      else if (opinion[3] == 0)
      {
        graph->addEdge(opinion[2], opinion[2] + proposals);
      }else
      {
        // A ou B é equivalente, ao somar com proposals, é equivalente a negação
        graph->addEdge(opinion[2] , opinion[3]+proposals);
        graph->addEdge(opinion[3] , opinion[2]+ proposals);
      }
    }
    graph->tranporGraph();
    // graph->printGraph();
    if(graph->isCyclic()){
      std::cout<<"não\n";
    }else{
      std::cout<<"sim\n";
    }
  }
}
