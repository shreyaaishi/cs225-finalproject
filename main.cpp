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
/* 6353	0
6353	6354
6353	6364
6353	6386
6309	0
6309	6310
6309	6344
2	3
2	4
2	7
3	2
3	309
4	2
4	273
4	274
4	388 */