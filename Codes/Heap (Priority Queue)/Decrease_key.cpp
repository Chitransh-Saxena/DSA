/*
    We are given a binary heap.
    For that heap, we are given an index i and a new value x
    So, at that index i, we want to update heap[i] = x.
    Now, this new value will be smaller, so we have to adjust the heap accordingly


    Approaches - 

    1. We update the element at that position and implement heapify function
    2. Another approach is simply just inserting the element there, and swapping with parent till our conditions match  (Insert function approach)

*/

#include "heap_structure.h"

void decrease_key(int *heap, int i, int x) {

    MinHeap *m = new MinHeap(heap);
    heap[i] = x;

    while( i!=0 && heap[i] < heap[m->parent(i)]) {          // Until we either reach root or we have a parent which is smaller than our current element
        int k = m->parent(i);                               // Get the parent index for current element
        swap(heap[i], heap[k]);                             // Since we are inside this loop it means parent is greater, therefore swap
        i = m->parent(i);                                   // Now our element is at a different position, so update the index with that position
    }


}