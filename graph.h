#include <map>
#include <string>
#include <vector>

class Graph {
    private:
    struct graphEdge {
        int startVertex, endVertex, weight;
    };
    public:
        Graph(const std::string & filename);
        void addVertex(int key);
        void addEdge(int startVertex, int endVertex, int weight);
        void createGraph(std::vector<std::string> edges);
        void printGraph();
    private:
        std::map<int, std::vector<graphEdge>> graph;
};