# Project3 Priority Queue and Heap

## Purpose of the project is to build a max heap. We'll be implementing a simple Customer class with 2 attributes - `priority_level_` and `service_time_`. `priority_level_` will be the comparables in building the max heap. Heap is the best choice to implement priority queue, here customer `priority_level_` is the priority, ranking from largest to smallest. Then we will delete the customers one by one from the max heap and push them to a history vector which will then be sorted based on `service_time_` from smallest to largest

### Customer class: has 3 member variables, `name_`, `priority_level_` and `service_time_`. Priority_level will be randomly generated between integer 0 to 100. `service_time_` will be randomly generated between integer 0 and 60. The class includes overloaded comparison operators to compare Customer objects based on their priority_level_, enabling them to be used effectively in heap structures

### Heap consists of 2 main parts, insert and delete

#### Insert: Elements are added to the end of the vector - this part maintains the complete binary tree structure. But to preserve the max heap property, we need to percolate up, compare the last element to its parent and swap them if the last element is greater. This process is repeated until the last element is no longer greater than its parent or it becomes the root of the heap

#### Delete: To delete, the root or first element in the vector is removed, then the last element is placed at the root/first position. Now we need to precolate down. Compare the root to both of its children, whichever is larger, moves up. It keeps moving down till it's larger than both of the children or reaches the end (a leaf node)

#### The Heap class uses a vector with 1-based indexing to simplify calculations for root and children (where index 0 serves as a dummy). currentSize_ represents the number of elements stored in the heap

#### Next step is to delete from max heap one by one, and push it to a history vector, which will then be sorted based on `service_time_` from smallest to largest. Note: after deleting the maximum element, the order of remaining elements in the heap may not match the original. This is because the heap restructures itself to maintain the max heap property, where the largest element is always at the root, ensuring efficient retrieval of max values

#### notes

A full tree has a total nodes of $$(2^ {h + 1} - 1)$$
A complete tree of height h consists of a full tree of height h-1. So it has at least: $$(2^ {(h - 1) + 1} - 1 + 1)$$ nodes and at most: $$(2^ {h + 1} - 1)$$ nodes.  
A full tree is also a complete tree

In a complete binary tree with n nodes, the highest index non-leaf node is the node
with index: &lfloor;n/2&rfloor; The remaining are leaf nodes: (n - &lfloor;n/2&rfloor;)  

In buildHeap(), we're calling percolateDown &lfloor;n/2&rfloor; times instead of n. It's more efficient because leaf nodes (nodes without children) do not need to be percolated down, they have no children to compare with.  

By focusing percolateDown() on the non-leaf nodes only, we avoid unnecessary comparisons and operations on nodes that are already in heap order (leaf nodes). This optimization reduces the number of operations and improves the overall efficiency. We're calling percolateDown() &lfloor;n/2&rfloor; times instead of n.

Binary heap does not have a strict order. The only guarantee of binary heap is the parent is greater than the children, there are no guarantees between sibling nodes.

buildHeap is DIFFERENT from heapify. buildHeap is a process that converts an unordered array into a heap. The time complexity of buildHeap is `O(n)`. Whereas heapify is called when there's an insertion or deletion to restructure the heap and maintain the max or min heap property. The time complexity of heapify is `O(log n)`.

Command to run:  
`make clean && make rebuild && ./main`

References:

1. [Data Structures & Algorithm Analysis in C++ 4th Chapter 5, page. 248](https://www.uoitc.edu.iq/images/documents/informatics-institute/Competitive_exam/DataStructures.pdf)
2. [Priority Queue and Heap](https://www.cs.hunter.cuny.edu/~sweiss/course_materials/csci335/lecture_notes/chapter06.pdf)
3. [Heap](https://www.youtube.com/watch?v=HqPJF2L5h9U&t=2759s)
4. [Heap Ordering](https://btholt.github.io/four-semesters-of-cs-part-two/heap-sort)
5. [buildHeap vs heapify](http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap07.htm#:~:text=The%20HEAPIFY%20procedure%2C%20which%20runs,sorts%20an%20array%20in%20place.)
