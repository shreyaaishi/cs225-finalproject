# Results.MD  
While testing our implemented algorithmxs, we came across some interesting results. We found out that compared to the amount of total nodes present in our large dataset, 
only a few colors actually being used when using colorGraph() to color our road network. This makes sense for a dataset that represents a roadmap. Roads can’t exactly be 
cyclic and each node will only have a few adjacent nodes, since only so many roads can be connected in one intersection. This also means that our edges have a set range of 
weights. We also found that the runtime for our BFS traversal was less than a minute, which was promising for a large dataset such as ours.  
  
We ran our full dataset through our main code once we passed all test cases, but for demonstration purposes for the BFS traversal and graph coloring, we’ve only 
passed in test datasets, containing only a few nodes and edges. This way, we will be able to show our full output in a screenshot. Our full dataset is quite large, 
so outputting every result from these algorithms will too large for the terminal. 
  
Our code passed all test cases that we made, which equaled 624 assertions in 12 test cases. These test cases tested our implementations of a a graph data structure, BFS traversal,
the graph coloring algorithm, and Djikstra’s algorithm. Each test case takes either a small graph dataset or a large graph dataset depending on what we are testing. There are 
four small graphs that we wrote that vary in connectedness and complexity, and the large graph dataset which contains the first 500 edges listed in the dataset. For more detail,
about what exactly each test case is testing, see our README.MD.  
![Image of Yaktocat](https://octodex.github.com/images/yaktocat.png) 

This is the representation of our shortest path output. The first path, from 2 to 7600, loads in our full dataset and traverses that to find the shortest path. The second path, 
from 2 to 24, loads only the first 500 edges listed in the dataset and traverses it to finds the shortest path. Both paths match the paths calculated by hand.  
![Image of Yaktocat](https://octodex.github.com/images/yaktocat.png)

This shows the output for a BFS traversal on a small graph. We used smallGraph1.txt and first performed the traversal by hand. After that, we compared the output of the BFS 
traversal algorithm to our traversal. They were the same, verifying that our traversal was correct.  
![Image of Yaktocat](https://octodex.github.com/images/yaktocat.png)
  
  
This shows the output for graphColor using a graph constructed with smallGraph3.txt as the dataset. We drew out the graph and assigned it the colors listed by hand according
to the output. Indeed none of the adjancent vertices had the color.     
![Image of Yaktocat](https://octodex.github.com/images/yaktocat.png]
