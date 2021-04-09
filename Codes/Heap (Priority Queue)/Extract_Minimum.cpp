/*
    Clarification First - getMin(int *heap) - This will return the 0th index item (considering min heap) and that's all. O(1).    
    BUT IN EXTRACT MINIMUM - We remove this element from the priority queue and then heapify the heap. Example - Doctor's queue, he checks a patient and he is removed from the queue.

    Approach written inside function itself.

*/

#include <iostream>
#include <vector>
using namespace std;

class MinHeap {

    // An heap data structure will have an array, it's size and it's capacity
    int size;
    int capacity;
    int *heap;

    public:
        MinHeap(int cap) {
            this->size = 0;
            this->capacity = cap;
            heap = new int[cap];     // Dynamic allocation of memory
        }

        // Refer file Heap_Theory.txt in same directory for the reasoning behind these mathematical operations
        int left(int i) {
            return (2*i + 1);
        }

        int right(int i) {
            return (2*i + 2);
        }

        int parent(int i) {
            return (i-1)/2;     // The round off automatically gives us the floor value.
        }

        void heapify(int k) {

            // 2 Approaches which I could think of
            // 1. We can go from bottom to top (level wise) and check if parent < child, if not we swap, but if we do that, children of the new parent will get unorganized
            // 2. Use Recursion. We can check minimum(parent, left, right) and if parent is not minimum, we swap it with min, and call this recursively for the entire tree

            int left_id = left(k);
            int right_id = right(k);

            int small = k;
            if(left_id < size && heap[left_id] < heap[k]) {

                small = left_id;    // In case of smaller value, we exchange indices. Now item at heap[k] will come at the index of smaller element.
                // Isn't item at left_id lost then? No, because we have just given the index variable 'small' same value as left_id index, we have not exachanged the value at that index yet.

            }

            if(right_id < size && heap[right_id] < heap[k]) {
                small = right_id;
            }

            if(small != k) {
                swap(heap[small], heap[k]);
                heapify(small);             // Recursively fix the whole tree now.
            }


        }   

        int extract_and_heapify() {

            // My Approach - 
            /*
                We get the left and right children of the first item.
                minimum of them will be the new root.
                If, let'say, we picked the left_id
                So, what we can do is, give that heap[left_id] = INT_MAX and call heapify.
                Then we can remove the last element and do size--;
            */

            // Slightly better gfg approach - 
            /*
                Swap, first and last element, so now the last element as at 0th index and minimum element is at the end
                Since we want to remove the minimum, we simply do size-- and thus remove that element.
                Now we call heapify.
            */
            if(size == 0) {
                return INT_MIN;
            }

            if(size == 1) {
                size--;
                return heap[0];
            }

            int item = heap[0];
            swap(heap[0], heap[size-1]);
            size--;
            
            heapify(0);         // Because we know element at index 0 is wrong, so start from there.

            return item;
        }
};