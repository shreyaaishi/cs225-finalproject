#include <map>
#include <string>
#include <vector>

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
        std::vector<GraphEdge> getIncidentEdges(int key);
        std::vector<int> getVertexList();
        void printGraph();
        std::vector<int> BFS();
        
    private:
        std::map<int, bool> visited;
        std::map<int, std::vector<GraphEdge>> graph;
        std::vector<int> BFSTraversal;
        void createGraph(std::vector<int> edges);
        void BFSUtil(int start);
};