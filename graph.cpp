#include <iostream>
#include<stdio.h>
#include <vector>
#include <map>
#include <queue>

#include "graph.h"
#include "readFromFile.hpp"

//using namespace std;

Graph::Graph(const std::string & filename) {
    std::vector<int> result = file_to_vector(filename);
    createGraph(result);
}

void Graph::createGraph(std::vector<int> edges) {
    for(unsigned i = 0; i < edges.size()-1; i += 2) {
        addEdge(edges[i], edges[i+1]);
        
    }
}

void Graph::insertVertex(int key) {
    // Only add vertex if it's not already a part of the graph
    std::map<int, std::vector<GraphEdge>>::iterator it = graph.find(key);
    if(it == graph.end()) {
        graph[key] = {};
    }
}
void Graph::addEdge(int startVertex, int endVertex) {
    // Prevent self-cycles from being created
    if (startVertex == endVertex) {
        return;
    }
    // Add vertices to graph
    insertVertex(startVertex);
    insertVertex(endVertex);

    // Calculate edge weight based on the node with the highest number of adjacent nodes
    // If this is the first connection for both nodes, it will have automatically 
    // the highest possible edge weight of 2
    double edgeWeight = 2;
    double uTotalEdges = (double) graph[startVertex].size();
    double vTotalEdges = (double) graph[endVertex].size();
    if (uTotalEdges >= vTotalEdges && uTotalEdges > 0) {
        edgeWeight = 1/uTotalEdges;
    }
    if (vTotalEdges > uTotalEdges && vTotalEdges > 0) {
        edgeWeight = 1/vTotalEdges;
    }
    GraphEdge graphEdge(startVertex, endVertex, edgeWeight);

    // Prevent multi-edges from occuring by iterating through the adjacency list of 
    // one of the vertices
    for(unsigned i = 0; i < graph[startVertex].size(); i++){
        if(graph[startVertex].at(i).u == startVertex && graph[startVertex].at(i).v == endVertex) {
            return;
        }
        if(graph[startVertex].at(i).u == endVertex && graph[startVertex].at(i).v == startVertex) {
            return;
        }
    }

    // Update edge weights for all adjacent edges of each vertex
    for (unsigned i = 0; i < graph[startVertex].size(); i++) {
        graph[startVertex].at(i).weight = edgeWeight;
    }
    for (unsigned i = 0; i < graph[endVertex].size(); i++) {
        graph[endVertex].at(i).weight = edgeWeight;
    }
    // Add the newly created edge to the corresponding adjacency list of each vertex
    graph[startVertex].push_back(graphEdge);
    graph[endVertex].push_back(graphEdge);
}

std::vector<Graph::GraphEdge> Graph::getIncidentEdges(int key) {
    return graph[key];
}

std::vector<int> Graph::getVertexList() {
    std::vector<int> vertexList;
    for (std::pair<const int, std::vector<GraphEdge>> & key_val : graph) {
        vertexList.push_back(key_val.first);
    }
    return vertexList;
}

void Graph::printGraph() {
    for (std::pair<const int, std::vector<GraphEdge>> & key_val : graph){
        std::cout << "Vertex: " << key_val.first << std::endl;
        std::cout << " U " << " V " << " weight " << std::endl; 
        for(unsigned i = 0; i<key_val.second.size(); i++) {
            std::cout << key_val.second[i].u << " " << key_val.second[i].v << " " <<key_val.second[i].weight << std::endl;
        }
    }
}

std::vector<int> Graph::BFS() {
    for (std::pair<const int, std::vector<GraphEdge>> & key_val : graph) {
        visited[key_val.first] = false;
    }
    for (std::pair<const int, bool> & key_val: visited) {
        if(!visited[key_val.first]) {
            BFSUtil(key_val.first);
        }
    }
    return BFSTraversal;
}

void Graph::BFSUtil(int start){ 
    std::queue<int> queue;
    queue.push(start);
    visited[start] = true;

    while(!(queue.empty())){
        int temp = queue.front();
        BFSTraversal.push_back(temp);
        queue.pop();
        for(unsigned i =0; i< graph[temp].size(); i++ ) {
            int one = graph[temp].at(i).u;
            int two = graph[temp].at(i).v;
            if (one != temp && !visited[one]) {
                visited[one] = true;
                queue.push(one);
            }
            if (two != temp && !visited[two]) {
                visited[two] = true;
                queue.push(two);
            }       
        }
        
    }
}