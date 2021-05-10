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
    std::cout<<"object created successfully" << std::endl;
    
}
void Graph::insertVertex(int key) {
    // Only add vertex if it's not already a part of the graph
    std::map<int, std::vector<GraphEdge*>>::iterator it = graph.find(key);
    if(it == graph.end()) {
        graph[key] = {};
    }
}
void Graph::addEdge(int startVertex, int endVertex) {
    //Add vertices if needed
    insertVertex(startVertex);
    insertVertex(endVertex);

    //Calculate weight
    int edgeWeight = 0;
    //std::cout<< startVertex << " " << graph[startVertex].size() << std::endl;
    if ((graph[startVertex].size() + graph[endVertex].size()) <= 0) {
       edgeWeight = -1;
    } else {
        edgeWeight = 1/(graph[startVertex].size() + graph[endVertex].size());
    }
    GraphEdge* graphEdge = new GraphEdge(startVertex, endVertex, edgeWeight);

    //Iterate through edgeList and ensure duplicate edge isn't being added to the vertex
    for(unsigned i = 0; i < graph[startVertex].size(); i++){
        if(graph[startVertex].at(i)->u == startVertex && graph[startVertex].at(i)->v == endVertex) {
            return;
        }
        if(graph[startVertex].at(i)->u == endVertex && graph[startVertex].at(i)->v == startVertex) {
            return;
        }
    }
    //Update edge weights
    for (unsigned i = 0; i < graph[startVertex].size(); i++) {
        graph[startVertex].at(i)->weight = edgeWeight;
    }
    for (unsigned i = 0; i < graph[endVertex].size(); i++) {
        graph[endVertex].at(i)->weight = edgeWeight;
    }
    graph[startVertex].push_back(graphEdge);
    graph[endVertex].push_back(graphEdge);

}

void Graph::createGraph(std::vector<int> edges) {
    for(unsigned i = 0; i < edges.size()-1; i += 2) {
        addEdge(edges[i], edges[i+1]);
        
    }
}

void Graph::printGraph() {
    for (std::pair<const int, std::vector<GraphEdge*>> & key_val : graph){
        std::cout << "Vertex: " << key_val.first << std::endl;
        std::cout << " U " << " V " << " weight " << std::endl; 
        for(unsigned i = 0; i<key_val.second.size(); i++) {
            std::cout << key_val.second[i]->u << " " << key_val.second[i]->v << " " <<key_val.second[i]->weight << std::endl;
        }
    }
}

void Graph::BFStraversal(int start){ 
    std::queue<int> queue;
    queue.push(start);
    visited[start] = true;

    while(!(queue.empty())){
        int temp = queue.front();
        std::cout << temp << std::endl;
        //int tempu = temp.u;
        queue.pop();
        for(unsigned i =0; i< graph[temp].size(); i++ ) {
            int one = graph[temp].at(i)->u;
            int two = graph[temp].at(i)->v;
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
void Graph::BFS(int start) {
    for(std::pair<const int, std::vector<GraphEdge*>> & key_val : graph){
        visited[key_val.first] = false;
    }
    for(std::pair<const int, std::vector<GraphEdge*>> & key_val : visited){
        if(visited[key_val.first == false]) {
            std::cout<<"Called BFStraversal helper" << std::endl;
            BFStraversal(key_val.first);
        }
    }
}