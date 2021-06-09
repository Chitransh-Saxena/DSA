#include <iostream>
#include <vector>

bool isArraySorted(std::vector<int> v, int index)
{
    if(index == 1)
        return true ? v[1] > v[0]: false;


    return (v[index] > v[index-1] && 
    
    (v, index-1));
}

int main()
{
    std::vector<int> v = {2,1,3,4,5};
    if(isArraySorted(v, 4) == true)
    {

        std::cout << "Array is sorted\n";
    }
    else
        std::cout << "Array is not sorted\n";
}