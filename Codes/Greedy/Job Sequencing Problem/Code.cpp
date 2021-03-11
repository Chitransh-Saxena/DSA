/*
    Question is that we are given an array of structures (id, deadline, profit)
    We have to tell the maximum number of jobs we can perform with maximum profit.
*/

class Solution {
  public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // Create an array for storing jobs to be done with their profits
        // Maximum deadline will be the size of this array
        
        int max_deadline = 0;
        
        for(int i = 0; i < n; i++) {
            max_deadline = max(arr[i].dead, max_deadline);
        }
        
        // Creating the array with init value as -1
        int a[max_deadline];
        
        // Had to change this from 0 based indexing to 1 based because job_deadline is never 0
        // And this array will be used to fill up for job_dealine only.
        // 0 based indexing was giving a wrong answer
        for(int i = 1; i <=max_deadline; i++) {
            a[i] = -1;
        }
        
        // Need to sort the arr[] based on Job.profit, in descending order
        auto it = [](Job j1, Job j2) {
            return j1.profit > j2.profit;
        };
        
        // Passing the lambda to the sort function
        sort(arr, arr+n, it);
        int profit = 0, num_of_jobs = 0;
        
        // Now, we have to perform the job with maximum profit first
        // But we are not going to perform the job after the deadline. On or before deadline only
        
        for(int i = 0; i < n; i++) {    // For all the jobs, with highest profit first
            
            // Since arr is sorted based on profit, we iterate in reverse manner to get job of max profit, first.
            for(int j = arr[i].dead; j>0; j--) {
                
                // Search for free slot
                if(a[j] == -1) {
                    num_of_jobs+=1;
                    profit+=arr[i].profit;
                    
                    // Mark this slot as not free anymore
                    a[j] = i;
                    
                    break;
                }
            }
        }
        vector<int> ans{num_of_jobs, profit};
        return ans;
    } 
};