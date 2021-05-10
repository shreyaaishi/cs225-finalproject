#include <map>
#include <string>
#include <vector>

class Graph {
    private:
    struct GraphEdge {
        int u, v, weight;

        GraphEdge(int u, int v, int weight) : u(u), v(v), weight(weight){}
    };
    public:
        Graph(const std::string & filename);
        //~Graph();
        void insertVertex(int key);
        void addEdge(int startVertex, int endVertex);
        void createGraph(std::vector<int> edges);
        void printGraph();
        void BFStraversal(int start);
    private:
        std::map<int, std::vector<GraphEdge*>> graph;
};
