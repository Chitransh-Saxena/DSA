#include <iostream>
#include <vector>

int firstOccurence(std::vector<int> v, int i, int key)
{
    if(i == v.size())
    {
        return -1;
    }

    if(v[i] == key)
        return i;
    
    return firstOccurence(v, i+1, key);
}

int lastOccurence(std::vector<int> v, int i, int key)
{
    if(i < 0)
    {
        return -1;
    }

    if(v[i] == key)
        return i;
    
    return lastOccurence(v, i-1, key);
}

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,4};

    std::cout << "First found at index = " << firstOccurence(v, 0, 4) << std::endl;
    std::cout << "Last found at index = " << lastOccurence(v, v.size()-1, 4) << std::endl;
}
