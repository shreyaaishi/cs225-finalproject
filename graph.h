#include <map>
#include <string>
#include <vector>

class Graph {
    private:
    struct GraphEdge {
        int u, v, weight;

        GraphEdge(int u, int v, int weight) : u(u), v(v), weight(weight){}
    };
/*         struct KDTreeNode
    {
      Point<Dim> point;
      KDTreeNode *left, *right;

      KDTreeNode() : point(), left(NULL), right(NULL) {}
      KDTreeNode(const Point<Dim> &point) : point(point), left(NULL), right(NULL) {}
    }; */
    public:
        Graph(const std::string & filename);
        //~Graph();
        void insertVertex(int key);
        void addEdge(int startVertex, int endVertex);
        void createGraph(std::vector<std::string> edges);
        void printGraph();
        void BFStraversal(int start);
    private:
        std::map<int, std::vector<GraphEdge>> graph;
};
