#include <iostream>
#include <memory>

/*
    Smart pointers are wrappers around the original pointer, but with the additional overwritten functions that do the job
    -> They automate the memory management
    -> They are very safe, and prevent memory leak (when memory is assigned using 'new' but not 'freed' or 'deleted') and dangling pointers
*/

/*
    Unique Pointer -
    Scoped pointer, when it goes out of scope, it will call delete and get destroyed
    We cannot copy unique pointer. It requires an explicit constructor, it does not have any default constructor
    Also, it was made unique by making the copy constructor of this pointer = delete

    So, why did we need unqiue pointer? If we have 2 pointers pointing to the same memory address, and one of the pointers is done with its job and delete is called
    the other pointer is referring to a memory location that is invalid, thus, unique pointer - only one pointer can be there that is pointing to a memory address
*/

/*
    Shared Pointer -
    -> It uses the concept of reference counting.
    -> It keeps track of how many references of the pointer are alive, as soon as that count reaches 0, the pointer dies, and the memory is freed
    -> It is also a scoped pointer
    -> Allocates another block of memory to store reference count, so it has some slight cost (really negligible)
*/

/*
    Weak Pointer - 
    -> When we assign a shared pointer to another shared pointer, it increases the ref count
    -> When we assign a shared pointer to another weak pointer, it does not increase the ref count
    -> This is a good option when we are gonna store a list of objects and we do not care if they are valid or not
    -> We can ask if the pointer is alive, and we will get a valid answer, but it does not actually keep the pointer alive or enforces anything
*/

class Entity
{
    public:
        Entity()
        {
            std::cout << "Entity created\n";
        }
        ~Entity()
        {
            std::cout << "Entity Destoryed\n";
        }

        void print()
        {
            std::cout << "Just print\n";
        }
};

int main ()
{

    // // Unique Pointer
    // {
    //     std::unique_ptr<Entity> e(new Entity());
    //     // std::unique_ptr<Entity> e = new Entity(); This is not possible in unique_ptr because it does not have a default constructor

    //     e->print();

    //     std::unique_ptr<Entity> e2 = std::make_unique<Entity>();        // This method gives us more exception safety
    //     e2->print();


    //     // Entity ends in this scope, because unique_ptr is a scoped pointer
    // }


    // Shared Pointer
    {
        std::shared_ptr<Entity> e1;                                         // 1 reference is created here, not assigned to anything yet
        {
            std::shared_ptr<Entity> e2 = std::make_shared<Entity>();        // Another reference is created here, and constructor is called
            e1 = e2;                                                        // Now, we have 2 references of same block of memory
        }                                                                   // When this scope ends, e2 goes out of scope
    }                                                                       // At this point, e1 goes out of scope and the memory is freed

    // Weak Pointer
    {
        std::weak_ptr<Entity> w0;                                           // A weak pointer is created here, no constructor is called yet for 'Entity'
        {
            std::shared_ptr<Entity> e1 = std::make_shared<Entity>();        // A shared pointer is created here, constructor for 'Entity' called
            w0 = e1;
        }                                                                   // At this point, e1 is  out of scope, but destructor is not called yet                                                              
    }                                                                       // At this point, w0 is out of scope, and memory is freed, and destructor is called


}

