#include <iostream>
#include <vector>

#include "graph.h"
#include "readFromFile.hpp"

Graph::Graph(const std::string & filename) {
    std::vector<std::string> result = file_to_vector(filename);
    createGraph(result);
    std::cout<<"object created successfully" << std::endl;
    
}
void Graph::addVertex(int key) {

}
void Graph::addEdge(int startVertex, int endVertex, int weight) {

}
void Graph::createGraph(std::vector<std::string> edges) {

}
void Graph::printGraph() {

}