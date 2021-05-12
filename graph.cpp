#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <queue>
#include <set>
#include <map>

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
    std::unordered_map<int, std::vector<GraphEdge>>::iterator it = graph.find(key);
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
    if (uTotalEdges + vTotalEdges > 0) {
        edgeWeight = 1/(uTotalEdges + vTotalEdges);
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

/*     // Update edge weights for all adjacent edges of each vertex
    for (unsigned i = 0; i < graph[startVertex].size(); i++) {
        graph[startVertex].at(i).weight = edgeWeight;
    }
    for (unsigned i = 0; i < graph[endVertex].size(); i++) {
        graph[endVertex].at(i).weight = edgeWeight;
    } */
    // Add the newly created edge to the corresponding adjacency list of each vertex
    graph[startVertex].push_back(graphEdge);
    graph[endVertex].push_back(graphEdge);
}

std::map<int,double> Graph::getAdjacencyList(int key) {
    std::map<int,double> adjacencyList;
    std::vector<GraphEdge> edgeList = graph[key];
    for (unsigned i = 0; i < edgeList.size(); i++) {
        if (edgeList[i].u == key) {
            adjacencyList[edgeList[i].v] = edgeList[i].weight;
        } else {
            adjacencyList[edgeList[i].u] = edgeList[i].weight;
        }
    }
    return adjacencyList;
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

void Graph::colorGraph() {
    std::unordered_map<int, int> colorAssignment;
    unsigned i=1;
    for (std::pair<const int, std::vector<GraphEdge>> & key_val : graph) {
        //std::cout<<i<<std::endl;
        if (i!= graph.size()) {
            //std::cout<<"entered"<<std::endl;
            colorAssignment[key_val.first] = -1;
            i++;
            continue;
        }
        colorAssignment[key_val.first] = 0;
    }
    std::vector<bool> available;
    for (unsigned i = 0; i < graph.size(); i++) {
        available.push_back(false);
    }
/*     for (unsigned i = 1; i<colorAssignment.size(); i++) {
        // Process all adjacent vertices and flag their colors as unavailable
        std::vector<int> adjList = getAdjacentVertices(i);
        for (unsigned j = 0; j < adjList.size(); j++) {
            if (colorAssignment[j] != -1) {
                available[colorAssignment[j]] = true;
            }
        }
        unsigned toAssign;
        for (toAssign = 0; toAssign < available.size(); i++) {
            if (available[toAssign] == false) {
                break;
            }
        }
        colorAssignment[i] = toAssign;
        for (unsigned j = 0; j < adjList.size(); j++) {
            if (colorAssignment[j] != -1) {
                available[colorAssignment[j]] = false;
            }
        }  
    } */
    // print the result
    for (std::pair<const int, int> & key_val : colorAssignment) {
        std::cout<< "Vertex " << key_val.first << " --> Color " 
            << key_val.second << std::endl;
    }
}

void Graph::dijkstra(int startNode, int endNode){
    std::unordered_map<int, double> distance;
    unsigned i=1;
    for (std::pair<const int, std::vector<GraphEdge>> & key_val : graph) {
        if (i!= graph.size()) {
            distance[key_val.first] = INFINITY;
            i++;
            continue;
        }
        distance[key_val.first] = 0;
    }
    std::set<int> visitedDij;
    std::priority_queue <int, std::vector<int>, std::greater<int>> pqueue;

	while(pqueue.top() != endNode){
        int currNode = pqueue.top();
        std::map<int,double> adjList = getAdjacencyList(currNode);
        for (std::pair<const int, double> & key_val : adjList){
            if(visitedDij.find(key_val.first) == visitedDij.end()){
               visitedDij.insert(key_val.first);
               pqueue.push(key_val.first);
               distance[key_val.first] = distance[currNode] + key_val.second;
               continue;
            }
            if(distance[key_val.first] > key_val.second) {
                distance[key_val.first] = key_val.second;
            }
        }
    }
    // Update the neighbor's tentative distance value if we found a lcoser path
	// Put the neighbor into the priority queue
	// Put the current node into the visited set
}

