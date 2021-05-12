#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "graph.h"
#include "readFromFile.hpp"
//#include "graph.h"

int main() {
    // Note: Include an extra line break after the list of edges
    Graph graph("PA.txt");
    //graph.printGraph();
     std::vector<int> result = graph.BFS();
    for (unsigned i = 0; i < result.size(); i++) {
        std::cout<<result[i] << " ";
    }
    std::cout<<std::endl;
    graph.colorGraph();
    return 0;
}