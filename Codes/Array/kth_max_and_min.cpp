/*
    Kth maximum and minimum element in an array

*/

// Approach 1: Sort the array, print the kth element
// This approach will take O(nlogn)
int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr, arr+r+1);
        return arr[k-1];
}


//Min-heap approach
int kthSmallet(int arr[], int l, int r, int k)
{
    // We just keep adding the elements in the priority queue, what this will do
    // It will always keep the smallest element at the top, so I will keep removing the k-1 elements

    for(int i = 0; i<=r; i++)
        {
            p.push(arr[i]);
        }
        
        int i = 0;
        while(!p.empty() && (i != k-1))
        {
            p.pop();
            i++;
        }
        
        return p.top();
}

