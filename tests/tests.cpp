#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "../graph.h"

// createGraph tests
TEST_CASE("All vertices added to graph") {
    Graph graph("tests/sampleGraph1.txt");
    std::vector<int> vertices = graph.getVertexList();
    REQUIRE(vertices.size() == 4);
}

//Test Cases Remaining:
//No multi-edges added
//No self-cycles added
//All edges added
//No repeat vertices added

// BFS traversal tests
TEST_CASE("BFS traversal reaches every node in BFS order") {
    std::vector<int> solution = {0,1,2,3};
    Graph graph("tests/sampleGraph1.txt");
    std::vector<int> result = graph.BFS();
    for (unsigned i = 0; i<result.size(); i++) {
        REQUIRE(solution[i] == result[i]);
    }
}
TEST_CASE("BFS traversal reaches every node in a disconnected graph while maintaining BFS order") {
    std::vector<int> solution = {0, 4, 1, 2, 3};
    Graph graph("tests/sampleGraph2.txt");
    std::vector<int> result = graph.BFS();
    for (unsigned i = 0; i<result.size(); i++) {
        REQUIRE(solution[i] == result[i]);
    }
}
//BFS traversal reaches every edge for connected graph
//BFS traversal reaches every edge for a disconnected graph