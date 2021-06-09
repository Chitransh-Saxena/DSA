#include <iostream>
#include <vector>
/*

    Of any number of digits, there are *n!* permutations possible of those digits
    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


*/

std::vector<std::vector<int>> ans;

void premutate(std::vector<int> nums, int index)
{
    if(index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i = index; i<nums.size(); i++)
    {
        std::swap(nums[i], nums[index]);
        premutate(nums, index+1);
        std::swap(nums[i], nums[index]);
    }
}

int main()
{

    std::vector<int> v = {1,2,3};
    premutate(v, 0);

    for(std::vector<int> v: ans)
    {
        for(int x: v)
        {

            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}