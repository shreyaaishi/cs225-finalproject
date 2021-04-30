#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include <vector>
#include <map>
#include<list>

using namespace std;
//using namespace Graph;
vector<int> tolist;
vector<int> fromlist;
vector<int> uniquenodes;


void createlists(const std::string & filename)
{
    ifstream text(filename);
	vector<int> tolist;
    vector<int> fromlist;
    if (text.is_open()) {
		std::istream_iterator<std::string> iter(text);
		while (!text.eof()) {
			int a, b;
			text >> a >> b;
			 fromlist.push_back(a);
             tolist.push_back(b);
			++iter;
		}
	}
     for(unsigned long i=0; i < fromlist.size(); i++){
            if(i == 0)
            {
                uniquenodes.push_back(fromlist[i]);
            }

            else if(tolist[i] != fromlist[i-1])
            {
            uniquenodes.push_back(fromlist[i]);
            }
     }
}
    // for(int i =0; i < v.size(); i++){
    //      if(i%2==0){
    //         tolist.push_back(v[i]);
    //         printf(v[i]);
    //     }

    //     else{
    //     fromlist.push_back(v[i]);
    //     }
//     }
// void createlists(vector<int> & v){
// 	for(int i =0; i < v.size(); i++){
// 		if(i%2==0){
// 			tolist.push_back(v[i]);
// 		}
		
// 		else{
// 			fromlist.push_back(v[i]);
// 		}
// 	}
// }

// void nodelist(vector<int> &v)
// {
//         for(unsigned long i =0; i < v.size(); i=i+2){
//             if(i == 0)
//             {
//                 uniquenodes.push_back(v[i]);
//             }

//             else if(v[i] != v[i-1])
//             {
//             uniquenodes.push_back(v[i]);
//             }
//     }
	// for(unsigned long i =0; i < v.size(); i=i+2){
	// 	if(i == 0){
	// 		uniquenodes.push_back(v[i]);
	// 	}

	// 	else if(v[i] != v[i-1]){
	// 		uniquenodes.push_back(v[i]);
	// 	}
	// }
//}


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
//typedef pair<int,int> Pair;

class Graph {
 
    // A function used by DFS
    //void DFSUtil(int v);
 
public:
    //map<int, bool> visited;
    map<int, list<int>> adj;
    map<int, int> weights;
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints DFS traversal of the complete graph
    //void DFS();
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    int node1 = count(fromlist.begin(), fromlist.end(), v);
    int node2 = count(fromlist.begin(), fromlist.end(), w);
    int weight = 1 / (node1+node2);
    weights.insert({v, weight});
}

int main(){
    Graph g;
    for(unsigned long i =0; i < fromlist.size(); i++){
        g.addEdge(tolist[i],fromlist[i]);
    }
    return 0;
}
// void createGraph()
// {
//     vector<vector<int>> adjList;
//     Graph g;
//         for(unsigned long i = 0; i < fromList.size(); i++){
//             g.addEdge
//         }
//         // for(unsigned long i = 0; i < uniquenodes.size(); i++){
//         //     int temp = fromlist.at(uniquenodes[i]);
//         //     //int temp = std::find(tolist, uniquenodes[i]);

//         //     vector<int> temp2 = vector<int>(tolist[temp]);
//         //     adjList.push_back(temp2);
//         //     if(fromlist[temp] == fromlist[temp+1]){
//         //         temp2.push_back(tolist[temp+1]);
//         //     }
//         //     if(fromlist[temp+1] == fromlist[temp+2]){
//         //         temp2.push_back(tolist[temp+2]);
//         //     }
//         //     if(fromlist[temp+2] == fromlist[temp+3]){
//         //         temp2.push_back(tolist[temp+3]);
//         //     }
            
//         // }
// }
