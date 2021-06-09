/*
    For a set of numbers [1,2,3]
    The power set will be a set containing all the possible subsets

    There will be 2^n subsets of 'n' numbers

    [[], [1], [1,2], .[1,3], [1,2,3], [2], [2,3], [3]];

    So, these subsets are basically formed by either choosing or not choosing a number in any traversal

    If we are at 1:
        -> We can choose none and our set will include [1]
        -> We can choose 2 and not 3. [1,2]
        -> We can choose 3 and not 2. [1,3]
        -> We can choose all, [1,2,3]
        -> We can choose none []
    Similarly for 2
        -> []
        -> [2]
        -> [2,3]
        -> NOTE: We did not include [2,1] here, because that is equivalent to [1,2]
        -> Power set includes unqiue elements



    ANOTHER APPROACH OF FILLING RESULT SET. We are gonna code for this

    We initialize with empty set

    If we are at 1:
        -> We add 1. Result = {[], [1]}
    When we are at 2:
        -> We add 2 to the result set subsets = {[], [1], [2], [1,2]}
        -> What happened above? 2 added to empty becomes [2], we add that.
        -> 2 added to 1 becomes [1,2] ...so we added that
    When we are at 3:
        -> We add 3 to the result set
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> power_set;

void getSet(std::vector<int> nums, int index)
{
    if(index == 0)
    {
        power_set.push_back({});                // Insert Empty
        power_set.push_back({nums[index]});     // Insert Last element
    }
    else
    {
        getSet(nums, index-1);
        int n = power_set.size();       // Since our plan is to add elements to currently formed sets, get those formed elements from here

        for(int i = 0; i<n; i++)
        {
            std::vector<int> v = power_set[i];      // We fetch the current susbet. Say {3}
            v.push_back(nums[index]);               // Add our element to it.       It becomes {3,2}
            power_set.push_back(v);                 // Formed the newly formed subset to answer
        }
    }
        
}

std::vector<std::vector<int>> getPowerSet(std::vector<int> nums)
{
    if(nums.empty())
        return {{}};
    
    getSet(nums, nums.size()-1);
    return power_set;
}

int main()
{
    std::vector<int> nums = {1,2,3};

    std::vector<std::vector<int>> powerSet = getPowerSet(nums);

    for(std::vector<int> v: powerSet)
    {
        for(int x: v)
        {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}


