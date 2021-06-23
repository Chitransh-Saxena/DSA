/*
    Copy takes both time and memory
    -> Sometimes it is useful, when we do not wanna touch the original memory's data (mark it as const in that case, just to be safe)
    -> But it takes both time, and extra space

    Copy Constructor
        -> Allows us to create deep copies of objects
        -> It is called each time a copy of the object is created, like even passing by value to another function


    Extra NOTE: If we declare any function as a FRIEND in a class declaration, that method can access the private variables of that class


*/

#include <iostream>
#include <cstring>

class String
{
    private:
        char* m_buffer;
        unsigned int m_Size;
    
    public:
        String(const char* string)
        {
            m_Size = strlen(string);
            // m_buffer = new char[m_Size];            // In this size, I have not considered an extra null character, thus I am getting garbage at the end
            m_buffer = new char[m_Size + 1];
            memcpy(m_buffer, string, m_Size + 1);
        }

        /*

        This would be wrong, because this copy constructor is still just copying the pointer

        String(const String& string)
            : m_buffer(string.m_Buffer), m_Size(string.m_Size);
            {}
        */

        // String(const String& string) = delete;          // This restricts the copy of this object
        
        // This implementation allocates new memory and copies the content over there
        String(const String& string)
            : m_Size(string.m_Size)
        {
            m_buffer = new char[m_Size + 1];
            memcpy(m_buffer, string.m_buffer, m_Size + 1);
        }
       


        ~String()
        {
            delete[] m_buffer;
        }

        friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_buffer;
    return stream;
}

int main()
{
    String name("Chitransh");
    std::cout << name;


    // Till above point everything is good, now starts the fun part
    /*
        If I create a new String object, and copy it from the original String
        String name2 = name;

        What will happen in the above case is, the C++ compiler will do a shallow copy, and that will copy all the members  (private and public) from name to name2
        So, it will even copy the char* m_Buffer;

        So, in both the String objects, m_Buffer is pointing to the same memory address in both of these String objects

        When everything is done and printed, and the main is about to go out of scope, the Destructor is called, now when destructor is called for the first object
        It frees the memory, and that's okay......
        BUT, when it is called for the String name2. it is again trying to free the same block of memory which is already freed, and thus we get a runtime crash


        To avoid this, we have to do a DEEP COPY i.e. create a new block of memory, and copy the contetns over there
        For this, we create a copy constructor
    */
}