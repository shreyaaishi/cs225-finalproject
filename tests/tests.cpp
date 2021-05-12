#include <map>
#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "../graph.h"

// Graph constructor tests
TEST_CASE("All vertices added to graph only once - small") {
    Graph graph("tests/smallGraph1.txt");
    std::vector<int> vertices = graph.getVertexList();
    REQUIRE(vertices.size() == 4);
}
TEST_CASE("All vertices added to graph only once -- large") {
    Graph graph("tests/largeGraph.txt");
    std::vector<int> vertices = graph.getVertexList();
    REQUIRE(vertices.size() == 223);
}
TEST_CASE("addEdge adds the edge to both vertices") {
    Graph graph("tests/smallGraph1.txt");
    std::vector<int> zeroSol = {1, 2, 3};
    std::vector<int> threeSol = {0, 2};
    graph.addEdge(0, 3);
    int i = 0;
    for (std::pair<const int, double> & key_val : graph.getAdjacencyList(0)) {
        REQUIRE(key_val.first == zeroSol[i]);
        i++;
    }
    i = 0;
    for (std::pair<const int, double> & key_val : graph.getAdjacencyList(3)) {
        REQUIRE(key_val.first == threeSol[i]);
        i++;
    }
}
TEST_CASE("Multi-edges aren't added") {
    Graph graph("tests/smallGraph1.txt");
    std::map<int, double> prevAdjList0 = graph.getAdjacencyList(0);
    std::map<int, double> prevAdjList2 = graph.getAdjacencyList(2);
    graph.addEdge(2,0);
    REQUIRE(prevAdjList0.size() == graph.getAdjacencyList(0).size());
    REQUIRE(prevAdjList2.size() == graph.getAdjacencyList(2).size());
}
TEST_CASE("Self-cycles aren't created") {
    Graph graph("tests/smallGraph1.txt");
    std::map<int, double> prevAdjList = graph.getAdjacencyList(3);
    graph.addEdge(3,3);
    REQUIRE(prevAdjList.size() == graph.getAdjacencyList(3).size());
}

// BFS traversal tests
TEST_CASE("BFS traversal reaches every node in BFS order") {
    std::vector<int> solution = {0,1,2,3};
    Graph graph("tests/smallGraph1.txt");
    std::vector<int> result = graph.BFS();
    for (unsigned i = 0; i<result.size(); i++) {
        REQUIRE(solution[i] == result[i]);
    }
}
TEST_CASE("BFS traversal reaches every node in a disconnected graph while maintaining BFS order") {
    std::vector<int> solution = {0, 4, 1, 2, 3};
    Graph graph("tests/smallGraph2.txt");
    std::vector<int> result = graph.BFS();
    for (unsigned i = 0; i<result.size(); i++) {
        REQUIRE(solution[i] == result[i]);
    }
}

//graph coloring tests
// no adjacent nodes have same color


// dijkstra's tests
// shortest path really is shortest path
// prioritize inner paths
// weights on the edges prioritizes a non-obvious path (EX: A->C has weight 10, A->B->C has total weight 8) 

