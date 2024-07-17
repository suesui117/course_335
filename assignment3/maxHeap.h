#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <algorithm>
#include <vector>

/* maxHeap is a template class */
template<typename T>
class MaxHeap
{
    public: 
        /**
         * @brief : default constructor
         */
        MaxHeap()
        {
            heapVec_.push_back(T()); // heap[0] is a dummy
        }


        /**
         * @brief   Parameterized constructor for MaxHeap class.
         * @param   input_vec Vector of type ItemType containing elements to initialize the heap.
         * @post    Adds a dummy element at index 0 to make the heapVec_ 1-indexed,
         *          copies elements from input_vec to heapVec_, and increments currentSize_
         *          Calls buildHeap to establish the max heap property.
         */
        MaxHeap(const std::vector<T>& input_vec )
        {
            heapVec_.push_back(T()); // heap[0] is a dummy
            for(int i = 0; i < input_vec.size(); ++i)
            {
                heapVec_.push_back(input_vec[i]);
                currentSize_++;
            }

            // restructure the vector to maintain the max heap property.
            buildHeap();
        }


        /**
         * @param an_item The item to insert into the heap.
         * @post an_item is appended to the heapVec_ and currentSize_ is incremented by 1.
         * calls percolteUp() to bubble up this element till a max heap structure is obtained.
         */
        void insert(const T& an_item)
        {
            heapVec_.push_back(an_item);
            currentSize_++; // last_index

            percolateUp(currentSize_);
        };



        /**
         * @post Deletes the max element (root) from the max heap.
         * and move the last element up to the root, then call percolateDown() to re-adjust
         * the max heap property.
         * The deleted max element is appeneded to the history_ vector and also returned
         * note: the history_ vector will have the largest element at index-0, second largest at index-1...
         * from largest to smallest.
         * @return Returning the max element
         * @throws std::logic_error if the heap is empty.
         */
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



        /**
         * @post Clears both heapVec_ and history_ vectors and sets currentSize_ to 0.
         */
        void makeEmpty()
        {
            currentSize_ = 0;
            heapVec_.clear();
            history_.clear();
        }


        /**
         * @brief Returns the maximum element in the heap.
         * 
         * @return A const reference to the maximum element in the heap.
         * @throws std::logic_error if the heap is empty.
         */
        const T& findMax( ) const
        {
            if (IsEmpty())
            {
                throw std::logic_error("Heap is empty. There's no max.");
            }

            return heapVec_[1];
        }


        /**
         * @return The number of elements currently in the heap.
         */
        int size() { return currentSize_; }

        /**
         * @return true if the heap is empty (contains only the dummy element), false otherwise.
         */
        const bool IsEmpty() const { return (heapVec_.size() == 1); }


        /**
         * @return Returns a vector of elements with max heap property
         */
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


       /**
         * @brief Builds a max heap from the current state of the heapVec_ vector.
         * 
         * buildHeap is O(n), itself is O(n/2) and calls percolateDown() which is O(log n).
         * worst-case is really O(n log n). Some elements may require more operations which is O(log n), most require O(1) fewer,
         * resulting in O(1 * n) operations. 
         * 
         * @post The heapVec_ vector is restructured into a max-heap.
         */
        void buildHeap()
        {
            for(int i = currentSize_ / 2; i > 0; --i ) // begin from right to left. <-----, the last non-leaf parent to the root
            // scan vector from right to left 
            {
                percolateDown(i); // every i is a non-leaf node parent
                // the highest index non-leaf node is the node with index (n/2)
                // we have n nodes, n//2 floor division gives the count of all parent nodes
                // and n - (n//2) = leaf nodes, which are nodes without children. e.g. 
            }
        } // end buildHeap


       /**
         * @brief Performs the percolate up operation to maintain the heap property after insertion.
         * it starts with the last element and compares it with its parent.
         * If it is larger than its parent, a swap is performed. Then, last_index is updated to its parent's index
         * that was just swapped with, continuing to compare until the max-heap property is achieved.
         * @param last_index The index of the last inserted element to be percolated up.
         * @post The element at last_index satisfies the max-heap property with respect to its parent nodes.
         */
        void percolateUp(int last_index) // this is the same as heapify up time complexity is O(log n), called by insert(), which inserts at the end
        {
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
        }; // end percolateUp


        /**
         * @brief Performs the percolate down operation to maintain the heap property.
         * It compares sub_root with its children, which ever is the largest gets swapped with the parent.
         * then set the parent_index to index of the largest child and continues down the heap until the
         * node is in its correct position relative to its children.
         * @param sub_root The index of the node from which to start the percolate down operation.
         * @post The subtree rooted at sub_root satisfies the max-heap property.
         */
        void percolateDown(int sub_root) // this is same as heapify down time complexity is O(log n), called by buildHeap() and deleteMax() which deletes from the root and moves last element up to the node and trickle down
        { 
            while (2 * sub_root <= currentSize_) // checking for at least one child is enough
            {
            int left = 2 * sub_root;
            int right = 2 * sub_root + 1;
            int largest = sub_root;

            // Check if left child exists and is greater than the current node
            if (left <= currentSize_ && heapVec_[left] > heapVec_[largest]) 
            {
                largest = left;
            }

            // Check if right child exists and is greater than the current largest node
            if (right <= currentSize_ && heapVec_[right] > heapVec_[largest]) 
            {
                largest = right;
            }

            // If the largest node is not the current node, swap and continue
            if (largest != sub_root) 
            {
                std::swap(heapVec_[sub_root], heapVec_[largest]);
                sub_root = largest; // Move down to the largest child
            } 
            else 
            {
                break; // The subtree is now a valid max-heap
            }
        }


    } // end percolateDown

}; // end MaxHeap class


#endif