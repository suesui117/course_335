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
            heapify();
        }


        void insert(const T& an_item)
        {
            heapVec_.push_back(an_item);
            currentSize_++; // last_index

            percolateUp(currentSize_);
        };


        T DeleteMax()
        {
            if (IsEmpty())
            {
                throw std::logic_error("Heap is empty. Cannot delete max.");
            }

            T max_item = heapVec_[1]; // root of the max heap is at index 1, we're returning this, so storing it
            heapVec_[1] = std::move(heapVec_[currentSize_]); // move the last element to the root
            heapVec_.pop_back(); // remove the last element, these 2 operations, "replaces/deletes the max" with the last element
            currentSize_--;

            percolateDown(1); // restore heap property
            history_.push_back(max_item);

            return max_item;
        } // should return the Customer being deleted


        void makeEmpty()
        {
            currentSize_ = 0;
            heapVec_.clear();
            history_.clear();
        }

        const T& findMax( ) const
        {
            if (IsEmpty())
            {
                throw std::logic_error("Heap is empty. There's no max.");
            }

            return heapVec_[1];
        }


        int size() { return currentSize_; }
        const bool IsEmpty() const { return (heapVec_.size() == 1); } // returns 1 if empty, else 0. 


        std::vector<T> getHeapVec() 
        { 
            std::vector<T> result(heapVec_.begin() + 1, heapVec_.end()); // heapVec[0] = dummy, excluding it

            return result;
        }
        

    private:
        std::vector<T> heapVec_;
        std::vector<T> history_; // deleted items, sorted from smallest to largest. 
        // when an element is deleted from a max heap, its always the largest being removed. Thus if we
        // append this removed root, we'll get a vector from largest to smallest.
        int currentSize_ = 0; // 1-indexed, number of elements in heap

        void percolateUp(int last_index) // for insert
        {
            std::cout << "last_index is " << last_index << "\n";

            while ( last_index > 1 ) // bubbling up, stop when it becomes 1, else will swap with heapVec_[index0] if greater than heapVec_[index0]
            {
                int parent_index = (last_index ) / 2; // get its parent
                
                if (heapVec_[last_index] > heapVec_[parent_index]) // if inserted element is strictly greater, swap
                {
                    std::swap(heapVec_[last_index], heapVec_[parent_index]);
                    last_index = parent_index; // update the last index, move it up to equal to its parent
                }
                else
                {
                    break; // else if smaller or equal, do nothing
                } 
            }

        }; 

        void heapify() // heapify is O(n), although starting at O(n/2) and decrement, it converges to O(n)
        {
            for(int i = currentSize_ / 2; i > 0; --i ) // begin from right to left. <-----, the last non-leaf parent to the root
            // scan vector from right to left 
            {
                percolateDown(i); // every i is a non-leaf node parent
                // the highest index non-leaf node is the node with index (n/2)
                // we have n nodes, n//2 floor division gives the count of all parent nodes
                // and n - (n//2) = leaf nodes, which are nodes without children. e.g. 
            }

        }

        void percolateDown(int sub_root) // for heapify and delete
        {
            int left = 2*sub_root;
            int right = 2*sub_root + 1;
            int larger_child = left;
            // std::cout << "This is the index of the root: " << sub_root << " it has left child at index " << left << " and right child at index " << right << "\n";
     
            while( left <= currentSize_ )
            {
                if ( right <= currentSize_ && heapVec_[right] > heapVec_[left]) // if right is within range
                {
                    larger_child = right;
                }

                if (heapVec_[sub_root] < heapVec_[larger_child])
                {
                    std::swap(heapVec_[sub_root], heapVec_[larger_child]);
                    sub_root = larger_child; // subroot becomes the child
                    left = 2*sub_root; // and its children
                    right = 2*sub_root+1;
                }

                else 
                { 
                    break; 
                }
            }
        }
};


#endif