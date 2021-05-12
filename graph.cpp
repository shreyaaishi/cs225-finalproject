#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <stack>

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
        if (i != graph.size()) {
            colorAssignment[key_val.first] = -1;
            i++;
            continue;
        }
        colorAssignment[key_val.first] = 0;
    }
    std::vector<bool> available;
    for (unsigned i = 0; i < graph.size(); i++) {
        available.push_back(true);
    }
    for (std::pair<const int, int> & key_val : colorAssignment) {
        if(key_val.second != -1) {continue;}
        std::vector<GraphEdge> edgeList = graph[key_val.first];
         std::map<int, double> adjList = getAdjacencyList(key_val.first);
        for (std::pair<const int, double> & adjVertex : adjList) {
            if(colorAssignment[adjVertex.first] != -1) {
                available[colorAssignment[adjVertex.first]] = false;
            }
        }
        int colorIndex = 0;
        while(colorIndex != (int) available.size()) {
            if(available[colorIndex]) {
                break;
            }
            colorIndex++;
        }
        colorAssignment[key_val.first] = colorIndex;
        for (std::pair<const int, double> & adjVertex : adjList) {
            if(colorAssignment[adjVertex.first] != -1) {
                available[colorAssignment[adjVertex.first]] = true;
            }
        }
    }
    // print the result
    for (std::pair<const int, int> & key_val : colorAssignment) {
        std::cout<< "Vertex " << key_val.first << " --> Color " 
            << key_val.second << std::endl;
    }
}

std::vector<int> Graph::dijkstra(int startNode, int endNode){
    typedef std::pair<double, int> pairDef;
    std::unordered_map<int, double> distance;
    for (std::pair<const int, std::vector<GraphEdge>> & key_val : graph) {
        distance[key_val.first] = INFINITY;
    }
    std::map<int, int> previousNode;
    previousNode[startNode] = -1;
    distance[startNode] = 0;
    std::priority_queue <pairDef, std::vector<pairDef>, std::greater<pairDef>> pqueue;
    pqueue.push(std::make_pair(0, startNode));
	while (pqueue.top().second != endNode){
        //std::cout<< pqueue.top().second << std::endl;
        int currNode = pqueue.top().second;
        pqueue.pop();
        std::map<int,double> adjList = getAdjacencyList(currNode);
        for (std::pair<const int, double> & key_val : adjList){
            if(distance[currNode] + key_val.second < distance[key_val.first]) {
                previousNode[key_val.first] = currNode;
                distance[key_val.first] = key_val.second + distance[currNode];
                pqueue.push(std::make_pair(key_val.second, key_val.first));
            }
        }
    }
    std::stack<int> reversePath;
    reversePath.push(endNode);
    int prevNode = previousNode[endNode];
    while(prevNode != startNode) {
        reversePath.push(prevNode);
        prevNode = previousNode[prevNode];
    }
    
    std::vector<int> path;
    while(!reversePath.empty()) {
        path.push_back(reversePath.top());
        reversePath.pop();
    }
    
    return path;
}