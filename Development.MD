# Development.MD
**April 8**  
This week, we got together to create our team contract and proposal. We discussed what dataset we wanted to use, and after deciding on a dataset containing 
Pennsylvania road intersections as nodes and roads as edges, we went on to finalize what we wanted to accomplish. With a road dataset, it felt natural to set 
a goal of finding the shortest path possible from one node to another. With that in mind, we set our traversal to be BFS since that would allow us to find a 
shortest path easily. Dijkstra’s algorithm would be covered in class and also worked on finding a shortest path, so we decided to go ahead with that algorithm as 
well. For our last algorithm, we decided we would implement graph coloring.
**April 15**  
We worked on setting up our team repository with all the files we need. We created a main.cpp where we have been putting all our code to be organized later, and 
imported our txt file. We are still unclear on Github so we are coding together through LiveShare sessions on Visual Studio Code. We created a graph class and 
defined an edge structure and node structure.  
**April 22**  	
We have a check in this week, so we worked on getting our code working. Our main priority was creating a readFromFile function to read and parse our txt file 
effectively, since it is an edge list with fromNode and toNode listed in two columns, tabulated by tabs. We are trying to figure out how to get the from nodes 
into one vector, and the to nodes into another vector, and call up each edge through indices. We also need to figure out how to create a graph object.  
**April 29**  
We have a second check in this week because we did not have a working code base last week, so we worked on getting what we had working and adding a BFS traversal
to get points back. Our main issue was our readFromFile compiling but not working due to how our data was formatted. We were able to work around it so that every
other data point parsed was a to or from node, which is an odd workaround, but it works.  
**May 6**  
We worked this week individually on fixing our readFromFile and BFS traversal. We mistakenly put in a DFS traversal, so we first edited that. We brainstormed possible
test cases to implement. We also split BFS into two functions, creating a private helper function. We also organized all of our code into separate files, creating 
readFromFile and graph header and implementation files to organize our objects better. We created a small dataset from our original data to test our cases with.   
**May 11**  
We worked this week to finish up our code to add in Dijkstra’s algorithm, a basic graph coloring algorithm, and create our final video. We also created our test 
cases. We ran into issues implementing Dijkstra’s, but were able to push through and debug. We were able to come up with a couple more test cases, and found some 
edge cases we didn’t previously think of, so we were able to change our code accordingly.  
