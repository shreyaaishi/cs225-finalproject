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

std::unordered_map<int, int> Graph::colorGraph() {
    /* Intialize an unordered map to store the results of graph coloring in which
     * each item represents a graph node and the its corresponding assigned color */ 
    std::unordered_map<int, int> colorAssignment;
    for (std::pair<const int, std::vector<GraphEdge>> & key_val : graph) {
        colorAssignment[key_val.first] = -1;
    }
    colorAssignment[graph.size()-1];
    /* Initialize a vector of boolean to store whether a color is available or not. */
    std::vector<bool> available;
    for (unsigned i = 0; i < graph.size(); i++) {
        available.push_back(true);
    }
    for (std::pair<const int, int> & key_val : colorAssignment) {
        /* If a node is already assigned a color, it does not need to be processed again */
        if(key_val.second != -1) {continue;}
        /* Iterate through its neighbors using the adjacency list and make note of any
         * colors that have already been used and flag them as unavailable */
        std::map<int, double> adjList = getAdjacencyList(key_val.first);
        for (std::pair<const int, double> & adjVertex : adjList) {
            if(colorAssignment[adjVertex.first] != -1) {
                available[colorAssignment[adjVertex.first]] = false;
            }
        }
        /* Iterate through the list assign the node the first available color*/
        int colorIndex = 0;
        while(colorIndex != (int) available.size()) {
            if(available[colorIndex]) {
                break;
            }
            colorIndex++;
        }
        /* Reset array to mark every color as available again for the next iteration */
        colorAssignment[key_val.first] = colorIndex;
        for (std::pair<const int, double> & adjVertex : adjList) {
            if(colorAssignment[adjVertex.first] != -1) {
                available[colorAssignment[adjVertex.first]] = true;
            }
        }
    }
    // Print the result
    for (std::pair<const int, int> & key_val : colorAssignment) {
        std::cout<< "Vertex " << key_val.first << " --> Color " 
            << key_val.second << std::endl;
    }
    return colorAssignment;
}

std::vector<int> Graph::dijkstra(int startNode, int endNode){
    typedef std::pair<double, int> pairDef;
    /* Intialize an unordered map representing distance from source node.
     * Since none of the vertices have been explored yet, every node other than the 
     * startNode has an unknown distance and set to a value of infinity instead. */
    std::unordered_map<int, double> distance;
    for (std::pair<const int, std::vector<GraphEdge>> & key_val : graph) {
        distance[key_val.first] = INFINITY;
    }
    distance[startNode] = 0;
    /* Initialize map storing the direct predecessor of each node */
    std::map<int, int> previousNode;
    /* Intialize a minHeap using the priority queue data structure included in the 
     * standard library. Each item in the queue contains both the node and its
     * corresponding tentative distance value. Intially includes only the sourceNode. */
    std::priority_queue <pairDef, std::vector<pairDef>, std::greater<pairDef>> pqueue;
    pqueue.push(std::make_pair(0, startNode));
	while (pqueue.top().second != endNode){
        /* Store and then remove node with the lowest tentative distance */
        int currNode = pqueue.top().second;
        pqueue.pop();
        /* Iterate through the node's neigbors using its adjacency list*/
        std::map<int,double> adjList = getAdjacencyList(currNode);
        for (std::pair<const int, double> & key_val : adjList){
            /* If a closer path to the neighbor is found, update its tentative distance
             * value and place/update it as a an item on the priority queue. Also store the
             * current node as the predecessor to its neighbor*/
            if(distance[currNode] + key_val.second < distance[key_val.first]) {
                previousNode[key_val.first] = currNode;
                distance[key_val.first] = key_val.second + distance[currNode];
                pqueue.push(std::make_pair(key_val.second, key_val.first));
            }
        }
    }
    /* Backtracing with the previousNodes map, store the nodes that form the shortest 
     * path from the startNode and endNode as items in a stack data structure. */
    std::stack<int> reversePath;
    reversePath.push(endNode);
    int prevNode = previousNode[endNode];
    while(prevNode != startNode) {
        reversePath.push(prevNode);
        prevNode = previousNode[prevNode];
    }
    reversePath.push(startNode);
    /* Pop from the stack and push into a vector to get the shortest path in the 
     * correct order */
    std::vector<int> path;
    while(!reversePath.empty()) {
        path.push_back(reversePath.top());
        reversePath.pop();
    }
    
    return path;
}