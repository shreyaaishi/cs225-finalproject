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
        void BFS(int start);
        
    private:
        std::map<int, bool> visited;
        void BFStraversal(int start);
        std::map<int, std::vector<GraphEdge*>> graph;
};
// class BFS{
//     public:
//     void BFStraversal(int start);
//     std::queue<int> queue;
//     int current;
//     private:
// }
