#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include <vector>

using namespace std;
vector<int> tolist;
vector<int> fromlist;
vector<int> uniquenodes;


void createlists(vector<int> & v)
{
    ofstream input;
    input.open("roadNet-PA.txt");
    for(int i =0; i < v.length(); i++){
        getline(input, i, '\t');
         if(i%2==0){
            tolist.push_back(v[i]);
            printf(v[i]);
        }

        else{
        fromlist.push_back(v[i]);
        }
    }
void createlists(vector<int> & v){
	for(int i =0; i < v.length(); i++){
		if(i%2==0){
			tolist.push_back(v[i]);
		}
		
		else{
			fromlist.push_back(v[i]);
		}
	}
}

void return nodelist(vector<int> &v)
{
        for(int i =0; i < v.length(); i=i+2){
            if(i == 0)
            {
                uniquenodes.push_back(v[i]);
            }

            else if(v[i] != v[i-1])
            {
            uniquenodes.push_back(v[i]);
            }
    }
	for(int i =0; i < v.length(); i=i+2){
		if(i == 0){
			uniquenodes.push_back(v[i]);
		}

		else if(v[i] != v[i-1]){
			uniquenodes.push_back(v[i]);
		}
	}
}


struct node
{
    int nodeNumber;
    int connectedEdges;
};
struct edge{
int startNode;
int endNode;
int weight; // find startNode edges and endNode edges, ^(-1)
};
typedef pair<int, int> Pair;

class Graph
{
    vector<vector<Pair>> adjList;
    Graph::addnode(int node){
        for(unsigned long i = 0; i < uniquenodes.size(); i++){
            int temp = find(tolist, uniquenodes[i]);
            adjList.push_back(vector<Pair>(tolist[temp], fromlist[temp]));
            if(tolist[temp] == tolist[temp+1]){
                adjList.push_back()
            }
            
        }
    }
}
