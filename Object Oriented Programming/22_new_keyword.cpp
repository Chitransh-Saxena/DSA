#include <iostream>

/*
    new keyword basically allocates memory on the heap.
    It searches for a contiguous block of size of requested data type, and returns the pointer to the first block
        -> It doesn't do a linear or any sort of search, but it maintains a list called "free list"
        -> From that it provides us our required pointer, but again, it is a search operation, which has it's own cost
    -> new keyword also calls the constructor of that certain class for which the object is being created



    Similarly, delete and free are there

    -> all the memory allocated on heap can be freed via free(), but this does not call destructor
    -> It can be done via delete as well, which also calls the destructor too


*/

class Entity
{
    private:
        int id;
    
    public:
        void setId(int id)
        {
            this->id = id;
        }

        int getId()
        {
            return this->id;
        }
};
int main()
{
    int* a = new int;           // Single 4 byte integer allocated on the heap
    int* arr = new int[50];     // 50 * 4 bytes of integer allocated on heap

    Entity e = new Entity();    // Allocated memory for all the elements's data types
    

    // We could perform above operation in c-style with malloc, only difference is, below implementation does not call the constructor
    Entity e2 = (Entity*)malloc(sizeof(Entity));                    // Cast to Entity* because malloc returns a void*

    // malloc has to be accompanied by free
    free(e2);


    Entity e_arr = new Entity[50];  // Same thing for 50 blocks


    // All the new keyword has to be accompanied by delete
    delete a;
    delete[] arr;
    delete e;
    delete[] e_arr;
}