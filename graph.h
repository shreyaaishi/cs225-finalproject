#include <unordered_map>
#include <map>
#include <string>
#include <vector>

#pragma once

class Graph {
    private:
    struct GraphEdge {
        int u, v;
        double weight;

        GraphEdge(int u, int v, double weight) : u(u), v(v), weight(weight){}
    };
    public:
        Graph(const std::string & filename);
        void insertVertex(int key);
        void addEdge(int startVertex, int endVertex);
        std::map<int, double> getAdjacencyList(int key);
        std::vector<int> getVertexList();
        void printGraph();
        std::vector<int> BFS();
        void colorGraph();
        void dijkstra(int startNode, int endNode);
        
    private:
        std::unordered_map<int, bool> visited;
        std::unordered_map<int, std::vector<GraphEdge>> graph;
        std::vector<int> BFSTraversal;
        void createGraph(std::vector<int> edges);
        void BFSUtil(int start);
};