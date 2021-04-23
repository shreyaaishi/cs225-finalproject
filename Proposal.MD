## Project Proposal (shreyab4 ezhan292 dsikli2)
### Leading Question: Given two intersections or endpoints, what is the shortest path possible between them?  
Given two intersections or endpoints on a roadmap, we would like to find the shortest path possible with the shortest amount of edges, 
and then create a colored graph to display the possible paths.

**Dataset Acquisition and Processing**
We would like to use a set from the available SNAP datasets, specifically the Pennsylvania road network. 
It gives us undirected data with nodes representing endpoints and intersections, and edges as the roads 
between. It comes as a .txt file, so we will read in our data according to [this source](http://www.cplusplus.com/forum/beginner/78150/)
as an array of strings. For our graph, edges will be elongated according to weight, which will be determined
by 1/(the number of edges connected to both nodes connected to the edge). If we are unable to graph a 
certain node or edge, we will drop that edge as this set is considerably large, so another route will exist. 
We will avoid dropping data as much as possible, however.
1. http://snap.stanford.edu/data/roadNet-PA.html
2. Edge weight is 1/(number of edges connected to each node)
---
**Algorithms to Implement** We plan on covering the following algorithms in order to answer our leading question.
1. BFS Traversal - This type of traversal visits all the nodes at one level before moving onto the next. Since graphs 
can have cycles, unlike trees, we will need to use some sort of data structure to assist with keeping track of which nodes 
have already been visited. [Source](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)
2. Dijsktra’s Algorithm - The most common implementation of this algorithm involves creating a shortest-path tree, which 
is built from a given source node and finding the shortest paths from it to all other nodes in the graph. Its run time is 
O(V + ElogV) where V is the number of nodes and E is the number of edges. [Source](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
3. Graph Coloring - Since our graph is most likely not bipartite, coloring our graph such with the lowest color scheme 
possible becomes a NP-complete problem. Instead we plan on using the greedy coloring algorithm. Each vertex of the graph
is considered sequentially and assigned the smallest available color not used by any of its neighbors, adding a fresh 
color if needed. Its run time is O(V+E) where V is the number of vertices and E is the number of edges. 
[Source](https://www.cs.cornell.edu/courses/cs3110/2012sp/recitations/rec21-graphs/rec21.html)
---
**Timeline**  
April 8th -- complete contract and proposal  
April 9th -- verify contents, submit proposal and contract  
April 13th -- set up repository with data, initial Makefile, and main  
April 15th -- verify that data can be read into  
April 22 -- Write BFS and Dijikstra’s algorithms + test  
April 29th -- Write graph coloring algorithm, visualize data and verify  
May 6th -- Finish final report  
May 9th -- Record final presentation  
May 12 -- submit final presentation  
