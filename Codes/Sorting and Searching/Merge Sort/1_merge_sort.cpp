#include <iostream>
#include <algorithm>

/*
    Merge Sort is a divide and conquer based algorithm
    -> It is split into two major tasks
        -> Split the array - Here we divided a array into smaller tasks until we have a workable unit
        -> Merge the array - Now the merge has to be in such a way that the arrays become sorted
            -> Here we can use any approach to merge
            -> Most common approach is to use a 2 pointer approach, have pointers in both of the sub-arrays
            -> Compare the elements, whichever is smaller, add that into your merged array's index

    Time complexity
        -> In each step, we have n operations where we compare the elements and split and merge them
        -> How many steps we have?
            -> We have steps which keep on getting half (n/(2^k))
            -> This means we have logN steps
        -> So, total complexity will be O(NlogN)
*/


// We are passing 3 indices here, because, we wanna merge the array based on [left, mid], and [mid+1, right]
void merge(int arr[], int left, int mid, int right)
{

    int i = left;
    int j = mid+1;

    int k = left;       // This will be used in auxillary array
    int b[1000];


    // This while loop is simply comparing 2 sub-arrays via a 2 pointer approach, and incrementing the pointer for the array from where we picked up the element
    while(i <= mid && j <= right)
    {
        if(arr[i] < arr[j])
        {
            b[k] = arr[i];
            k+=1, i+=1;
        }
        else
        {
            b[k] = arr[j];
            k+=1, j+=1;
        }
    }

    // Now, there is a condition when one of the sub-arrays is still left
    if(j > right)
    {
        while(i<=mid)
        {
            b[k] = arr[i];
            i+=1, k+=1;
        }
    }
    else
    {
        while(j <= right)
        {
            b[k] = arr[j];
            j+=1, k+=1;
        }
    }

    for(int x = left; x<= right; x++)
    {
        arr[x] = b[x];
    }
}


// This helper function will 
void helper(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left)/2;
        helper(arr, left, mid);
        helper(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}


void mergeSort(int arr[], int n)
{

    helper(arr, 0, n-1);

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arr[] = {3,2,1,5,0,-7,25};
    int n = sizeof(arr)/sizeof(int);

    mergeSort(arr, n);

    for(int i = 0; i<n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}