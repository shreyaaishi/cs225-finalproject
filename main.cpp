#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>


#include "graph.h"
#include "readFromFile.hpp"
//#include "graph.h"

int main() {
    // Note: Include an extra line break in text after the listing edges
    Graph graph1("roadNet-PA.txt");
    graph1.printGraph();
     std::vector<int> traversal1 = graph1.BFS();
    for(unsigned i = 0; i < traversal1.size(); i++) {
        std::cout<< traversal1[i] << " ";
    }
    graph1.colorGraph();
    std::vector<int> shortestPath1 = graph1.dijkstra(2, 7600);
    for(unsigned i = 0; i < shortestPath1.size(); i++) {
        std::cout<<shortestPath1[i]<<std::endl;
    }
    Graph graph2("PA.txt");
    graph2.printGraph();
     std::vector<int> traversal2 = graph2.BFS();
    for(unsigned i = 0; i < traversal2.size(); i++) {
        std::cout<< traversal2[i] << " ";
    }
    graph2.colorGraph();
    std::vector<int> shortestPath2 = graph2.dijkstra(2, 24);
    for(unsigned i = 0; i < shortestPath2.size(); i++) {
        std::cout<<shortestPath2[i]<<std::endl;
    }
    return 0;
}