#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "graph.hpp"

int main() {
    int followers;
    int proposals;
    int opinion;
  while(true){
    std::cin >> followers;
    std::cin >> proposals;
    if(followers==0&& proposals==0){
      //condição de parada
      break;
    }
    Graph * graph = new Graph(followers);
    for( int i = 0;i<followers;i++){
      for( int j = 0;j<proposals;j++){
          std::cin >> opinion;
          graph->addEdge(i,opinion);
      }
    }
  graph->printGraph();
  std::cout<<"-------------------------\n";
  }
  
}
