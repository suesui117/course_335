# Project3 Priority Queue and Heap:
## Purpose of the project is to build a max heap. We'll be implementing a simple Customer class with 2 attributes - priority_level and service_time. Priority_level will be the comparables in building the max heap.

### Customer class: has 3 member variables, name_, priority_level_ and service_time_. Priority_level will be randomly generated between integer 0 to 100. Service_time_ will be randomly generated between integer 0 and 60.


### Heap consists of 2 main parts, insert and delete. 
#### Insert: Elements are added to the end of the vector - this part maintains the complete binary tree structure. But to preserve the max heap property, we need to percolate up, compare the last element to its parent and swap them if the last element is greater. This process is repeated until the last element is no longer greater than its parent or it becomes the root of the heap.

#### Delete: To delete, the root or first element in the vector is removed, then the last element is placed at the root/first position. Now we need to precolate down. Compare the root to both of its children, whichever is larger, moves up. It keeps moving down till it's larger than both of the children or reaches the end (a leaf node).

 #### The Heap class uses a vector with 1-based indexing to simplify calculations for root and children (where index 0 serves as a dummy). currentSize_ represents the number of elements stored in the heap.


#### notes:
A full tree has a total nodes of $$(2^ {h + 1} - 1)$$
A complete tree of height h consists of a full tree of height h-1. So it has at least: $$(2^ {(h - 1) + 1} - 1 + 1)$$ nodes and at most: $$(2^ {h + 1} - 1)$$ nodes.  
A full tree is also a complete tree. 

In a complete binary tree with n nodes, the highest index non-leaf node is the node
with index: &lfloor;n/2&rfloor; The remaining are leaf nodes: (n - &lfloor;n/2&rfloor;)  

In buildHeap(), we're calling percolateDown &lfloor;n/2&rfloor; times instead of n. It's more efficient because leaf nodes (nodes without children) do not need to be percolated down, they have no children to compare with.  

By focusing percolateDown() on the non-leaf nodes only, we avoid unnecessary comparisons and operations on nodes that are already in heap order (leaf nodes). This optimization reduces the number of operations and improves the overall efficiency. We're calling percolateDown() &lfloor;n/2&rfloor; times instead of n.




Command to run:  
make rebuild && ./main

References:
1. [Data Structures & Algorithm Analysis in C++ 4th Chapter 5, page. 248](https://www.uoitc.edu.iq/images/documents/informatics-institute/Competitive_exam/DataStructures.pdf)
2. [Priority Queue and Heap](https://www.cs.hunter.cuny.edu/~sweiss/course_materials/csci335/lecture_notes/chapter06.pdf)
3. [Heap](https://www.youtube.com/watch?v=HqPJF2L5h9U&t=2759s)
