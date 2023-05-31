## Task
Find the shortest path between two points in a given maze using the A\* algorithm. To implement the algorithm, use the data structure of a simple priority queue, which you have to write yourself.

### Input and output data
The input maze is specified in the file as a formatted two-dimensional matrix. In the code, the starting point of the path search and the end point are specified. Example of input data:
```
X X X X X X X X   
X       X X   X   
X   X   X X   X   
X   X         X   
X   X   X   X X     
X   X   X   X X   
X   X       X X   
X X X X X X X X 
```
Output – visualization of the algorithm’s work (to a file or to the screen)
```
X X X X X X X X   
X 5 6 7 X X e X   
X 4 X 8 X X d X   
X 3 X 9 a b c X   
X 2 X   X   X X    
X 1 X   X   X X  
X   X       X X  
X X X X X X X X  
```