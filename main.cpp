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
		if(i == 0){
		uniquenodes.push_back(v[i]);
}

else if(v[i] != v[i-1]){
uniquenodes.push_back(v[i]);
}
}
}


class graph;
struct node
{
    int nodeNumber
    /* data */
};
struct edge{
int startNode;
int endNode;
int weight; // find startNode edges and endNode edges, ^(-1)
};

void readFile{ // read file
    vector<int> list;
    ifstream infile;
    infile.open("roadNet-PA.txt");
    while(!infile.eof){
        getline(infile, list);
    }
    infile.close;
}
//read roadNet
//find all unique numbers, assign as nodes
//read in connections from txt, find edges
// thru public source -- cite, if its from this class, its okay except from prev sem labs
//spec -- lab flow
// parse, put into graph structure, traversal or algorithm done
