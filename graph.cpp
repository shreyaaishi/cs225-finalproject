#include <iostream>
#include <vector>
#include <map>

#include "graph.h"
#include "readFromFile.hpp"

//using namespace std;

Graph::Graph(const std::string & filename) {
    std::vector<std::string> result = file_to_vector(filename);
    createGraph(result);
    std::cout<<"object created successfully" << std::endl;
    
}
void Graph::insertVertex(int key) {
    // Only add vertex if it's not already a part of the graph
    std::map<int, std::vector<GraphEdge>>::iterator it = graph.find(key);
    if(it == graph.end()) {
        graph.at(key) = {};
    }
}
void Graph::addEdge(int startVertex, int endVertex) {
    //Add vertices if needed
    insertVertex(startVertex);
    insertVertex(endVertex);
    //Calculate weight
    int weight = 0;
    if ((graph[startVertex].size() + graph[endVertex].size() - 2) <= 0) {
       weight = -1;
    } else {
        weight = 1/(graph[startVertex].size() + graph[endVertex].size() - 2);
    }
    GraphEdge graphEdge(startVertex, endVertex, weight);
    //iterate through the list of start vertexes, checking if u = startVertex && v = endvertex || v = startVertex && u = endvertex
    //if so, return
    for(unsigned i = 0; i < graph[startVertex].size(); i++){
        if(graph[startVertex].at(i).u == startVertex && graph[startVertex].at(i).v == endVertex) {
            return;
        }
        if(graph[startVertex].at(i).u == endVertex && graph[startVertex].at(i).v == startVertex) {
            return;
        }
    }
    graph[startVertex].push_back(graphEdge);
    graph[endVertex].push_back(graphEdge);
}

void Graph::createGraph(std::vector<std::string> edges) {
    for(unsigned i = 0; i < edges.size(); i += 2) {
        addEdge(i, i+1);
    }
}
void Graph::printGraph() {

}

void Graph::BFStraversal(int start){
    /*std::vector<bool> visited;
    for(int i = 0; i < graph.size(); i++){
        visited[i] = false;
    } */

}