#include vector>
#include <iostream>

/*
    We are given two sorted vectors, we have to merge them into nums1 vector
    The capacity of nums1 is already m+n (so that it can accomodate elements of 2 vectors)


    Approach
    1. Start by looking at both of the elements from the back
    2. Whichever element is greater, will be put at the back
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{

    int first = m - 1;          // Back iterator of first vector
    int second = n - 1;         // Back iterator of second vector

    for(int i = m + n -1; i >=0; i--)
    {
        if(second < 0)          // This means we have reached the end of the second vector and all the elements have been merged
            break;

        if(nums1[first] > nums2[second])
        {
            // In this case, we move the element of the first vector within itself to the back, we are not changing the value at 'first' position, it will be automatically changed later
            nums1[i] = nums1[first--];

            // NOTE - Here we are only moving the element at position 'first' in nums1 to position 'i' in nums1
            // The element from nums2 which should have come here will be handled by the else case automatically, because the 'second' still points to that element
        }
        else{

            // When the element of second is greater, or equal, put it at the back of nums1
            nums1[i] = nums2[second--];
        }
    }
}