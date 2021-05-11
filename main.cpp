#include <iostream>
#include <string>
#include <vector>

#include "graph.h"
#include "readFromFile.hpp"
//#include "graph.h"

int main() {
    
/*     std::vector<int> res = file_to_vector("PA.txt");
    for (unsigned i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    } */
    Graph graph("PA.txt");
    graph.printGraph();
    std::vector<int> result = graph.BFS();
    for (unsigned i = 0; i < result.size(); i++) {
        std::cout<<result[i] << " ";
    }
    return 0;
}