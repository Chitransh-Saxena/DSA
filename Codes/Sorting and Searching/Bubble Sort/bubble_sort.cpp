/*
    In this sorting technique we just keep swapping the adjacent elements if they are not in correct order

    It gets tricky when we have to think about how long do we have to do this. Because if you think, we are not gonna get the items in correct sequence in only 1 pass

    So, the the correct way is to repeat this n number of times.
    -> But, fortunately we do not have to iterate till the end of the array each time. Why?
    -> If we Notice, after the first pass (when the first for loop completes, the biggest element will come to the end)
        -> Imagine this, we start swapping elements from 0th index, if bigger element is on the left, we swap the elements and bigger element goes 1+ index
        -> Now, this way, the biggest element of the array will reach the end of the index in first for loop
    -> So, we do not have to loop till 'n' in each for loop

    -> Next, for how long do we have to keep re-running this entire for loop?
        -> We need to run this inside a while or a for loop for count < n
        -> Basically, after first for loop, we still have to handle for n-1 elements, so, we basically need to run for n-1 times at least
*/

#include <iostream>

void bubbly(int arr[], int n)
{
    int count = 1;
    while(count < n)
    {
        for(int i = 0; i < n - count; i++)
        {
            if(arr[i] > arr[i+1])
            {
                std::swap(arr[i], arr[i+1]);
            }
        }

        count+=1;
    }
}