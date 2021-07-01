#include <iostream>

/*
    Stack and heap, are 2 different types of memories that are inside RAM
        -> Stack is usually 2 MB or so, thats why if we allocate more than we should get a buffer overflow or something
        -> Heap is usually more, and based on our request we can access that amount of memory, but again, we have to be aware of RAM and all that stuff

    But since stack is a small amount of memory in RAM, it is usually contiguous blocks of memory.
    So, to have a variable like `int x = 5` is a simple 1 instruction task. Super easy for the CPU and super fast
        -> This is also helpful for CPU cache hits
        -> But this is only helpful when there are a bunch of variables, with just 10-20, it is no big deal if we have cache miss or not

    But, when we do int* i = new int[5];    
        -> This has to go through the free list
        -> Give back a pointer of at least 4 * 5 bytes
        -> Update the free list that above memory is not free anymore
        -> If at all in our program we ask for more somehow, it again has to do the same work
    -> So, heap allocation is a whole different and heavy animal
*/