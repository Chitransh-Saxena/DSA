/*
    Unordered map stores the values in totally out of order manner
    If you input 
    1, "one"
    2, "two"
    3, "three"

    There is no guarantee that 1, "one" will be output first

    -> Internally, it does not implement Trees, it mantains hash-table
        -> Here, for each key, a hash value is calculated
        -> Because of above variation
            -> Time to insert - O(1)
            -> Time to access or find - O(1)
    
    -> Because in-built implementation is using Hash-Table, for literally everything a Hash Value is calculated
        -> Because of this, we cannot use complex data types as keys for unordered_maps, like pairs, or custom class objects
        -> This concept is very similar to what we have in Java, where we have to define the Hash function for the data types to be used in Maps. (One issue I faced once while prepping a Map)
*/

#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<int, std::string> m;

    m[1] = "One";
    m[2] = "Two";
    m[3] = "Three";

    for(auto &p: m)
    {   
        std::cout << p.first << " " << p.second << std::endl;
    }
}