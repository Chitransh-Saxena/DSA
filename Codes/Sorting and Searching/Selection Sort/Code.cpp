/*
    Selection Sort - O(n2)

    Why is selection sort?

    -> It selects the position in the array (index) annd finds the right candidate for this position.
    -> We move pointer to next index and select right candidate for that position.

    *** Why use selection sort? What can this do that bubble sort or other sorting algos cannot do?

    Algorithm - 

    1. We start performing operation from first position and we declare a variable that keeps track of minimum_value_index
        1.1 Call it min_id, now this position will hold minimum value from this to remaining array
        1.2 Process will be, we compare current element to next element, if it is smaller, we update min_id to the index value of this element.
        1.3 We keep on comparing min_id till end of array because there is a chance that there is an even smaller element.
        1.4 This way, makes sure we select the minimum element for our current position
    
    2. Once we have found the next least element, we update min_id to that index.
    3. We repeat this process for the reamining indices.
*/

#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


 // } Driver Code Ends







 // ############################### MY CODE ##################################################
class Solution
{
    public:
    int select(int arr[], int i, int n)
    {
        // code here such that selectionSort() sorts arr[]
        int min_id = i;
        for(int j = min_id+1; j<n; j++) {
            if(arr[j] < arr[min_id]) {
                min_id = j;
            }
        }
        swap(arr+min_id, arr+i);
        return arr[i];              // NOTE THAT I AM RETURNING arr[i] BECAUSE I HAVE SWAPPED THE VALUES SO NOW THIS CONTAINS LEAST VALUE
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
       for(int i = 0; i<n; i++) {
           arr[i] = select(arr, i, n);
       }
    }
};

// { Driver Code Starts.
// ###################################### MY CODE ENDS #############






/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends