#include <iostream>
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

        MinHeap(int *heap) {        // New constructor when we have a heap already and just want to use below methods

            this->heap = heap;
        }

        MinHeap(int *heap, int size) {
            this->heap = heap;
            this->size = size;
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

        // Adding this here because it is used in so many other questions, it is better to have it as a library function
        void heapify(int k) {               // O(log(n))

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

        void maxHeapify(int k) {               // O(log(n))

            // 2 Approaches which I could think of
            // 1. We can go from bottom to top (level wise) and check if parent < child, if not we swap, but if we do that, children of the new parent will get unorganized
            // 2. Use Recursion. We can check minimum(parent, left, right) and if parent is not minimum, we swap it with min, and call this recursively for the entire tree

            int left_id = left(k);
            int right_id = right(k);

            int great = k;
            if(left_id < size && heap[left_id] > heap[k]) {

                great = left_id;    // In case of smaller value, we exchange indices. Now item at heap[k] will come at the index of smaller element.
                // Isn't item at left_id lost then? No, because we have just given the index variable 'small' same value as left_id index, we have not exachanged the value at that index yet.

            }

            if(right_id < size && heap[right_id] > heap[k]) {
                great = right_id;
            }

            if(great != k) {
                swap(heap[great], heap[k]);
                heapify(great);             // Recursively fix the whole tree now.
            }


        }
};