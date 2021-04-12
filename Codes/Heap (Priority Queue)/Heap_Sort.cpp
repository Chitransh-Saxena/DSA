/*
    Heap sort is based on selection sort algorithm
    It is an optimization over selection sort based on an assumption that we are using heap data structure.

    -> In selection sort, we find out the minimum / maximum element and swap it with the current element.
    -> We do a linear search to find out the min/max element
    -> The above 2 steps make selection sort a O(n^2) complexity function

    Considering we are going to sort the elements in ascending order, we are going to need max heap
    
    -> In heap sort, to find the max / min element, instead of doing a linear search, heap sort uses min / max heap data structure.
    -> So, if we are given an array, we restructure the elements so that they form a min / max heap. O(n)
    -> After building the max heap, we swap the last element of the array with the root of the max_heap (root of max_heap is largest element, in ascending order that has to be the last element of the array)
    -> Once we have done this, we heapify this array. Now the point to note is, last element of this array was 1st element in previous step
        -> So if we heapify, we will again get the same heap
        -> Therefore, we heapify for size - 1 now. That means, in our heapify function, we do not consider the last element
    -> So, we again heapify for size --. Replace the first element with second last now .... repeat the process.
*/

#include "heap_structure.h"



// Step 1: build a max heap, because we want ascending type sort
void build_heap(int *heap, int size) {                              // O(n)
    
    MinHeap *m = new MinHeap(heap, size);       // Class is minHeap but it is normal heap which supports both min and max heapify functions, nothing else special
    int last_parent = (size - 2) /2;

    for(int i = last_parent; i>=0; i--) {
        m->maxHeapify(i);
    }
}

// Step 2: 
// -> Now we follow selection sort type of process, swap max element with the last element, because last element has to go at the end after all
// -> Second last element at the second place and so on...
void heapSort(int *heap, int size) {

    build_heap(heap, size);         // We have our heap now

    for(int i = size - 1; i >=0; i--) {
        // At first iteration, we have first element as largest element because of line 40, now we swap it with last element (correct placement)
        // For consequent iterations, after max_heapify is called, first element will be again maximum element of the remaining array (last element ignored because we put correct value in it's place)
        // We repeat this till we reach root.
        swap(heap[0], heap[i]);
        MinHeap *m = new MinHeap(heap, i);
        m->maxHeapify(0);
    }  
}

