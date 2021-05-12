#include <iostream>
#include <string>
#include <vector>

#include "graph.h"
#include "readFromFile.hpp"
//#include "graph.h"

int main() {
    Graph graph("PA.txt");
    graph.printGraph();
/*     std::vector<int> result = graph.BFS();
    for (unsigned i = 0; i < result.size(); i++) {
        std::cout<<result[i] << " ";
    } */
    graph.colorGraph();
    return 0;
}