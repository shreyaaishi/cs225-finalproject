#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>


#include "graph.h"
#include "readFromFile.hpp"
//#include "graph.h"

int main() {
    // Note: Include an extra line break after the list of edges
    Graph graph("PA.txt");
    //graph.printGraph();
/*     std::vector<int> result = graph.dijkstra(2, 24);
    for(unsigned i = 0; i < result.size(); i++) {
        std::cout<<result[i] << std::endl;
    } */
/*     graph.printGraph();
    std::vector<int> result = graph.BFS();
    for (unsigned i = 0; i < result.size(); i++) {
        std::cout<<result[i] << " ";
    }
    std::cout<<std::endl;
    graph.colorGraph(); */
/*     typedef std::pair<int, double> pairDef;
    std::priority_queue <pairDef, std::vector<pairDef>, std::greater<pairDef>> pqueue;
    pqueue.push(std::make_pair(0,0));
    pqueue.push(std::make_pair(5,0.5));
    pqueue.push(std::make_pair(90, 0.1));
    pqueue.push(std::make_pair(1, 0.9));
    while(!pqueue.empty()) {
        std::cout<<pqueue.top().first << " " << pqueue.top().second << std::endl;
        pqueue.pop();
    } */
    graph.colorGraph();
    return 0;
}