# Project3 Heap:
## Purpose of the project is to build a maxHeap

### Heap consists of 2 main parts, insert and delete. 
#### Insert: Elements are added to the end of the vector - this part maintains the complete binary tree structure. But to preserve the max heap property, we need to percolate up, compare the last element to its parent and swap them if the last element is greater. This process is repeated until the last element is no longer greater than its parent or it becomes the root of the heap.

#### Delete: To delete, the root or first element in the vector is removed, then the last element is placed at the root/first position. Now we need to precolate down. Compare the root to both of its children, whichever is larger, moves up. It keeps moving down till it's larger than both of the children or reaches the end (a leaf node).


Command to run:


References:
1.
