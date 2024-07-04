#ifndef MAXHEAP_H
#define MAXHEAP_H

#include<iostream>
#include<algorithm>
#include<vector>

/* maxHeap is a template class 
priority queue is a queue that supports a deleteMin and an insert operations, no other operations are required

*/

template<typename T>
class MaxHeap
{
    public: 

        MaxHeap(){};
        ~MaxHeap(){};
        void insert(const T& an_item){};
        T DeleteMax(){};
        void percolateDown(){};
        void percolateUp(){};
        int size() const { return heapVec_.size(); };
        bool IsEmpty const() { return heapVec_.size() == 0 }; // returns 1 if empty, else 0. 

    private:
        std::vector<T> heapVec_;
};

#endif