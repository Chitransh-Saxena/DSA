/*
    Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.
    A subarray is a contiguous subsequence of the array.


    Approach - 

    Noob approach 1:
        -> Find all the subarrays of length odd (1,3,5 ... )
        -> Add their sum, but this is practically very very complex
    
    Better Approach
        -> Prepare a prefix sum array
        -> Now, run a loop for starting index
            -> Run a loop for ending index, but this index will make sure the length is always odd
            -> Now, once we have a starting and ending index, we can do a direct look up to the prefix sum and get the result
            -> Add all the results
        -> Finally, return this result
*/

#include <iostream>
#include <vector>


int getSum(int arr[], int start, int end)
{
    if(start == 0)
    {
        return arr[end] - 0;
    }
    else
        return arr[end] - arr[start - 1];
}

int sumOddLengthSubarrays(std::vector<int>& arr)
{
    // Prepare a prefix sum array
    int prefix_sum[10000];
    prefix_sum[0] = arr[0];

    int answer = 0;

    for(int i = 1; i<arr.size(); i++)
    {
        prefix_sum[i]+=(prefix_sum[i-1] + arr[i]);
    }

    // Now do iterations for starting and ending index in such a way that the length is always odd
    for(int i = 0; i<arr.size(); i++)
    {   
        // j will always increase by length 2, because first length is 1, for single element, then 3 (so j+2), then 5 ... so we keep incrementing by 2
        for(int j = i; j<arr.size(); j+=2)
        {
            // This get sum function will fetch us the sum between start to end index
            answer += getSum(prefix_sum, i, j);
        }
    }

    return answer;
}

