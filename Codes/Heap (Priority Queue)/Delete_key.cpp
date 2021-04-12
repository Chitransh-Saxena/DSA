/*
    Given a min heap and a index, we want to delete the element at this index.

    Approaches:

    1.
        -> Go this index, and swap this element with the last element of the heap array
        -> Now decrease the size of the array (size--)
        -> Heapify it now.
    
    2. GFG approach
        -> Repace the value at given index with INT_MIN
        -> Call DecreaseKey() function on this heap now, because we have replaced a key with a lesser value
        -> This will make INT_MIN go to the top as it is smallest
        -> Now call extract_min function

        Flaws in above approach - It makes sense but it is extra work, extract_min calls heapify() internally, so my approach reduces 2 steps (decreaseKey() and extractMin())
*/
#include "heap_structure.h"


void heapify(int k, int *heap, int size) {

    MinHeap *m = new MinHeap(heap);
    
    int left_id = m->left(k);
    int right_id = m->right(k);

    int small = k;              // We begin by assuming right now given index is smaller element index.

    if(left_id < size && heap[left_id] < heap[k]) {         // element at left index is smaller than element at parent position

            small = left_id;                                // Not swappin values, only updating small to lower element index value
    }

    if(right_id < small && heap[right_id] < heap[k]) {
        small = right_id;
    }

    if(small != k) {                                        // If our original assumption was wrong
        
        // We only swap the values and we do not have to make any adjustments for indices, because we assume that is correct only the value at that index is wrong
        // This is different as compared to insert operation
        swap(heap[k], heap[small]);
        heapify(small, heap, size);
    }

}


void deleteKey(int i, int *heap, int size) {

    heap[i] = heap[size-1];     // Replace current element with the last element.
    size = size - 1;            // Reduce size of array by 1

    heapify(0, heap, size);
}