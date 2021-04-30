#include<iostream>
#include<cmath>
#include<fstream>
#include<string>

using namespace std;

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


//to do
//read in + parse txt file
//convert into graph
//  define and assign nodes+edges
//  define and assign edge weights
//write traversal
//makefile