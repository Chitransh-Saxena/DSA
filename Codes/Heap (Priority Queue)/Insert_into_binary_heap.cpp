/*
    We are given a binary heap tree and an element that we need to add to the heap. Consider it is a min heap
    Our task is to add the element to the binary heap, and complexity of that should be O(log(size_of_tree))

    Point to be noted, we only show the elements as a tree, they are actually residing in an array.

    So, when we insert the new element - 
    1. We need to ensure we are not exceeding the capacity
    2. We are following the properties of binary heap.


    Approach - 
    1. If the capacity allows, we insert the element at the end.
    2. Now we compare the element with it's parent, if parent is greater (we are in min_heap), we swap the elements.
    3. We stop only when we reach root or parent is smaller than current node.

*/
/* ************************************************************************************************************************** */

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

        void insert(int item) {

            if(size < capacity) {

                size+=1;
                heap[size] = item;

                // We stop either at root or when parent is smaller than current item (smaller condition because this is min_heap), we move forward otherwise.
                for(int i = size-1; i!=0 && heap[parent(i)] > heap[i]; i--) {

                    // Since we are inside this for loop, it means heap[parent(i)] > heap[i], therefore we can swap
                    // Note, we are making sure heap[i] is always the element that we inserted.
                    swap(heap[parent(i)], heap[i]);
                    // Since we swapped, our item has moved up some positions, which is basically the index of it's parent.
                    // Simply speaking, we swapped values first, now we taking care of indices.
                    i = parent(i);              
                }
            }
        }
};