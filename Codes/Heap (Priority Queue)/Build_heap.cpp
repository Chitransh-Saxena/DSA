/*
    Given a random array, rearraneg its elements to form a min heap

    Approach - 

    1.  My Approach
        -> Find the minimum element, that will be at index 0 and find next 2 smaller elements, that will go at index left and right
        -> Recursively do this till we reach the end of array

    2. GFG Approach
        -> We start from bottom most, right most internal node (last parent with any child node)
        -> We call minHeapify(k) for that index, and we keep calling minHeapify(k--) till we reach k = 0 (root)
        -> The assumption for minHeapify() is, when we call minHeapify() for an index k, it's left and right should have been heapified already.
        -> This is why we start from bottom, because when we start from bottom, and reach upper node, left and right are already heapified since we started from there

        Points to think about in above approach - 
        1. How do we find bottom most right most internal node (parent of the last leaf) index ?
            Ans. - 
            -> Last node will be at index size-1
            -> Example, for 11 elements, size = 11.
            -> Index of last node = size - 1 = 10
            -> Index of parent of the last node (Check parent function in heap_structure.h) = (i-1)/2 = (10-1)/2 = 4
            -> So, this is how we get the parent of the last leaf. Simply it is ((size-1) -1 /2) = (size -2 /2)


        2. How do we make it's left and right correct before calling minHeapify() to this node and all it's upper levels ?
*/
#include "heap_structure.h"

void buildHeap(int *heap, int size) {

    int last_parent = ((size - 2) / 2);
    MinHeap *m = new MinHeap(heap, size);

    for(int i = last_parent; i>=0; i--) {           // Repeating this m number of times
        m->heapify(i);                              // O(log(n)) Function
    }


    // But the catch here is, the complexity of this function is O(n). How?
    
    /*
        Maximum number of nodes in a binary heap of height h - [ n / 2^h + 1]   (n = number of nodes in the heap, h = height at which we are counting the nodes)

        So, in our function, we call heapify() starting with height 1 (not 0) 

        ********* TO BE DONE, IT WAS TOO BORING TO CONTINUE **********
        Watch GFG heap course video on build heap to understand this
        https://practice.geeksforgeeks.org/tracks/DSASP-Heap/?batchId=140
    */
}