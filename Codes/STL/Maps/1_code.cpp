/*
    It stores a key-value pair. Those can be any types of objects
    map<int, string> m;
    map<object_1, int> m;

    Map vs Unordered Map

    -> Map stores the values in sorted order. Unordered map does not store in sorted order
        -> This also reflects in the complexity
    -> Map internally implements Red-Black Trees.
        -> This is a self-balancing tree
    -> Map's each element is a pair, and the second element of map i.e. second pair, can be anywhere in memory
        -> Map does is not a contigous data structure, since it's index is not an integer but a user-defined any data type
        -> These memory blocks are linked.
        -> This is why, we cannot do iterator+=1 in case of map, but we can do iterator++;

    Time Complexities:
    
    -> Insert in Map - O(logN), where N is current sizwe of the map
        -> Since it internally implements Red-Black Trees, sometimes it depends on the length of the key
        -> In case of complex strings as keys, this can take more time because it has to balance out

    -> find in map - It returns the iterator to the map position. O(logN)
    -> remove in map. m.erase(val). O(logN)
*/

#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> m;

    m.insert(std::make_pair("one", 1));

    auto it = m.begin();

    std::cout << it->first;
}