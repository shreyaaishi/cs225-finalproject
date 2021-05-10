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
    return 0;
}
