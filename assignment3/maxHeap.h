#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <algorithm>
#include <vector>

/* maxHeap is a template class 
priority queue is a queue that supports a deleteMin and an insert operations, no other operations are required

*/

template<typename T>
class MaxHeap
{
    public: 

        MaxHeap()
        {
            heapVec_.push_back(T()); // heap[0] is a dummy
        }

        MaxHeap(const std::vector<T>& input_vec )
        {
            heapVec_.push_back(T()); // heap[0] is a dummy
            for(int i = 0; i < input_vec.size(); ++i)
            {
                heapVec_.push_back(input_vec[i]);
                currentSize_++;
            }

            // now the calling heap object contains a vector of customer
            // we need to call percolate_down to compare the root with its children,
            // whoever is larger, gets swapped to the top.
            // this goal is to restructure the vector to maintain the max heap property.
            buildHeap();

            
        }

        void buildHeap() 
        {
            for(int i = currentSize_ / 2; i > 0; --i ) // begin from right to left. <-----, the last non-leaf parent to the root
            // scan vector from right to left 
            {
                std::cout << i << " " << heapVec_[i] << "\n";
                // percolateDown(i); // every i is a parent
                // the highest index non-leaf node is the node with index (n/2)
                // we have n nodes, n//2 floor division gives the count of all parent nodes
                // and n - (n//2) = leaf nodes, which are nodes without children. e.g. 
            }

        }

        void insert(const T& an_item){};
        T DeleteMax()
        {
            if (IsEmpty())
            {
                throw std::logic_error("Heap is empty. Cannot delete max.");
            }

            T max_item = heapVec_[1]; // root of the max heap is at index 1
            heapVec_[1] = heapVec_[currentSize_]; // move the last element to the root
            heapVec_.pop_back(); // remove the last element
            currentSize_--;

            percolateDown(1); // restore heap property

            return max_item;
        } // should return the Customer being deleted

        void percolateDown(){};
        void percolateUp(int sub_root)
        {
            std::cout << "This is the index of the root" << sub_root << "\n";
            int left = 2*sub_root;
            int right = 2*sub_root + 1;
            int larger_child = left;
        
            while( left < currentSize_ && right < currentSize_)
            {
                if (heapVec_[right] > heapVec_[left])
                {
                    larger_child = right;
                }

                if (heapVec_[sub_root] < heapVec_[larger_child])
                {
                    std::swap(heapVec_[sub_root], heapVec_[larger_child]);
                    sub_root = larger_child; // now the sub_root index has moved down to largest child
                    left = 2*sub_root;
                    right = 2*sub_root+1;
                }

                else{ break; }
            }


        }
        int size() { return currentSize_; }
        bool IsEmpty() { return (heapVec_.size() == 1); } // returns 1 if empty, else 0. 

    private:
        std::vector<T> heapVec_;
        // std::vector<T> historyVec_; // deleted customers, sorted from smallest to largest. 
        // when an element is deleted from a max heap, its always the largest being removed. Thus if we
        // append this removed root, we'll get a vector from largest to smallest.
        int currentSize_ = 0; // 1-indexed, number of elements in heap
};


#endif
