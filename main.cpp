#include <iostream>
#include <string>
#include <vector>

#include "graph.h"
#include "readFromFile.hpp"
//#include "graph.h"

int main() {
    
    std::vector<std::string> res = file_to_vector("smallSample.txt");
    for (unsigned i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }
    Graph graph("smallSample.txt");
	
}