#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "../graph.h"

//See README.MD for more details about test cases

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

// Graph Coloring Tests
TEST_CASE("No two adjacent nodes have the same color -- small dataset") {
    Graph graph("tests/smallGraph3.txt");
    std::unordered_map<int, int> result = graph.colorGraph();
    std::unordered_map<int, int>::iterator it;
    for (it = result.begin(); it != result.end(); it++) {
        int key = it->first;
        int color = it->second;
        std::vector<int> resultkeys;
        std::map<int, double> adjList = graph.getAdjacencyList(key);
        for(std::pair<const int, double> & key_val : adjList) {
            resultkeys.push_back(key_val.first);
        }
        for(int k = 0; k < (int) resultkeys.size(); k++){
            int color2 = result[resultkeys[k]];
            REQUIRE(color2 != color);
        }
    }
}

TEST_CASE("No two adjacent nodes have the same color -- large dataset") {
    Graph graph("tests/largeGraph.txt");
    std::unordered_map<int, int> result = graph.colorGraph();
    std::unordered_map<int, int>::iterator it;
    for (it = result.begin(); it != result.end(); it++) {
        int key = it->first;
        int color = it->second;
        std::vector<int> resultkeys;
        std::map<int, double> adjList = graph.getAdjacencyList(key);
        for(std::pair<const int, double> & key_val : adjList) {
            resultkeys.push_back(key_val.first);
        }
        for(int k = 0; k < (int) resultkeys.size(); k++){
            int color2 = result[resultkeys[k]];
            REQUIRE(color2 != color);
        }
    }
}

TEST_CASE("Graph produces all possible colors") {
    Graph graph("tests/smallGraph4.txt");
    std::vector<int> possibleColors;
    std::unordered_map<int, int> result = graph.colorGraph();
    std::unordered_map<int, int>::iterator it;
    for (it = result.begin(); it != result.end(); it++) {
        int color = it->second;
        possibleColors.push_back(color);
    }
    std::vector<int> vertexList = graph.getVertexList();
    REQUIRE(possibleColors.size() == vertexList.size());
}

// Dijkstra's Tests
TEST_CASE("Dijkstra correctly calculates shortest path - small") {
    std::vector<int> solution = {0,1,3,4,5,7};
    Graph graph("tests/smallGraph3.txt");
    std::vector<int> result = graph.dijkstra(0,7);
    for (unsigned i = 0; i<result.size(); i++) {
         REQUIRE(solution[i] == result[i]);
    }
}

TEST_CASE("Dijkstra correctly calculates shortest path - large") {
    std::vector<int> solution = {2, 7, 16, 18, 24, 23};
    Graph graph("tests/largeGraph.txt");
    std::vector<int> result = graph.dijkstra(2,23);
    for (unsigned i = 0; i<result.size(); i++) {
         REQUIRE(solution[i] == result[i]);
    }
}
