# README.MD  
[Project Video](https://drive.google.com/file/d/144wNiXpHyIN49j-8FwAa-BkFk3LbmFtv/view?usp=sharing)  
## **Project Files**  
```readFromFile.h readFromFile.cpp```: contains the code for reading in files as a vector of integers  
```graph.h, graph.cpp```: class representing a graph implementation and its corresponding implementation of BFS traversal, Dijkstra's algorithm, and greedy graph coloring  
```main.cpp```: code that uses the implementation of the Graph class to build a graph using the road network dataset and prints the corresponding results of each algorithm. Since the dataset contains a million nodes we also built a graph using only its first 500 nodes and the printed the corresponding results  
```tests/tests.cpp```: contains Catch test cases for each implemented algorithm. See description of tests in the following section  
```roadNet-PA.txt```: Contains Pennsylvania road network dataset. Each line of the text file represents an edge of the graph as described by the “starting” node in the first column and “ending” node in the second column   
```PA.txt```: Contains only the first 500 edges of the Pennsylvania road network dataset  
```catch```: contains the code needed for the Catch tests to run  
```make```: contains custom Clang enforcement rules  
## **Running the code**  
After formatting data as described above, place the text file in the current directory. Compile, build, and run the project executable as follows  
	``` make finalproj```  
	```./finalproj ```  
## **Test Suite**
After formatting data as described above, place the text file in the current directory. Compile, build, and run the project executable as follows  
	```make test```  
	```./test ```  
 **Graph Constructor Tests**  
 *Vertices add only once to graph - Small*  
 A graph consisting of 4 nodes was created according to tests/smallGraph1.txt. Since some of the vertices in this graph have a degree greater than 1, insertVertex() will be called multiple times on the same vertex. However, it is expected that the vertex will be added to the graph only once, making the total number of vertices be 4.  
 *Vertices are added only once to graph - Large*  
 A graph consisting of 233 nodes was created according to tests/largeGraph.txt, which is based on the first 500 edges listed in our dataset. Similar to the previous test case, insertVertex() will be called multiple times on the same vertex. However, it is expected that the vertex will be added to the graph only once, making the total number of vertices 233.   
 *addEdge() adds the edge to both of the vertices’ adjacency list*  
 A graph consisting of 4 nodes was created according to tests/smallGraph1.txt. A new edge connecting vertex 0 and vertex 3 was subsequently added. It was then verified that the adjacency list grew by exactly one and the correct edge was added for both corresponding vertices.  
 *Multi-edges aren’t added*  
 A graph consisting of 4 nodes was created according to the to tests/smallGraph1.txt. A new edge connecting vertex 2 and 0 was subsequently added. As seen in line 2 of the text file, however, this edge already exists, so a new edge shouldn’t be created as it would be redundant and form a multi-edge. This was verified by making sure the size of the adjacency list did not change.   
 *Self-cycles aren’t created*  
 A graph consisting of  4 nodes was created according to the tests/smallGraph1.txt. A new edge with start and end vertex was subsequently added. However, adding this edge would form a self cycle in the graph, making it no longer a simple one, and therefore should not be added to vertex 3’s adjacency list. This was verified by making sure the size of the adjacency list did not change.   
**BFS Traversal Tests**  
*BFS traversal reaches every node of a connected graph in BFS order*  
A connected graph consisting of 4 nodes was created according to the tests/smallGraph1.txt. Then using the Graph class’s BFS method, a vector of the vertices, starting with the first vertex added to the graph, was obtained. The order within this vector was compared with the expected BFS ordering.   
*BFS traversal reaches every node of a disconnected graph in BFS order*  
A disconnected graph consisting of 4 nodes was created according to the tests/smallGraph2.txt. Then using the Graph class’s BFS method, a vector of the vertices, starting with the first vertex added to the graph, was obtained. The order within this vector was compared with the expected BFS ordering. Notably, making sure that vertices 1, 2, and 3, which are  in no way connected to vertices 0 and 4 are still included in the BFS traversal.   
**Graph Coloring Tests**  
*No two adjacent nodes have the same color -- small*  
A connected graph consisting of 8 nodes was created according to tests/smallGraph3.txt. Each node was assigned a color using the colorGraph() algorithm implemented. Iterated through color assignments to ensure no two adjacent nodes have the same color.  
*No two adjacent nodes have the same color -- large*  
A connected graph consisting of 233 nodes was created according to tests/largeGraph.txt. Each node was assigned a color using the colorGraph() algorithm implemented. Iterated through the color assignments to ensure no two adjacent nodes have the same color.  
*Chromatic color of graph never exceeds the number of vertices*  
A connected graph consisting of 5 nodes was created according to tests/smallGraph4.txt. Each node was assigned a color using the colorGraph() algorithm implemented. This graph is unique in that is cyclic graph. This means that its chromatic number must be equal to the number of nodes. In general, the number of colors needed to color a graph should never exceed the number of nodes in the graph. We checked this ensuring that the number of colors in this graph was equal to number of nodes in the graph.   
**Dijkstra's Algorithm Tests**  
*Dijkstra correctly calculates shortest path - small*   
A connected graph consisting of 8 nodes was created according to tests/smallGraph3.txt. The shortest path from vertex 0 to vertex 7 was determined using the dijkstra() algorithm implemented. The way this graph is set up, there are multiple ways to get to the destination but we ensured the vector returning the shortest path was indeed the correct order.   
*Dijkstra correctly calculates shortest path - large*  
A connected graph consisting of 233 nodes was created according to tests/largeGraph.txt. The shortest path from vertex 0 to vertex 7 was determined using the dijkstra() algorithm implemented. The way this graph is set up, there are multiple ways to get to the destination but we ensured the vector returning the shortest path was indeed the correct order. 
