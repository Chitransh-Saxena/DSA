class Solution
{
    /*
        Clarification first, when the question says deadline 2....that means the job can be performed at 1 or 2
        
        So, if we have 2 jobs with deadline 2, we can perform one job at 1 and second at 2
        
        Do not confuse this with only 1 job at 2 .... it is deadline, and not a set time to perform a job
    
    */
    
    class SortByJobEnd implements Comparator<Job> {
        
        public int compare(Job a, Job b) {
            
            return b.profit - a.profit;
        }
    }

    int[] JobScheduling(Job arr[], int n)
    {
        int [] ans = new int[2];
        
        // Sort on the basis of deadline, if the deadline is same, pick max profit job
        
        Arrays.sort(arr, new SortByJobEnd());
        

        /*
        
        int[] freeTime = new int[n+1];
        
        for(int i = 1; i<=n; i++) {
            freeTime[i] = -1;
        }
        
        This above array was originally created till value of n
        But this will fail if we have a deadline greater than n
        
        
        So, we need to create array of size max_deadline, for this we need to get the max_deadline first
        
        */
        
        int max_deadline = 0;
        
        for(int i = 0; i<n; i++) {
            
            max_deadline = Math.max(max_deadline, arr[i].deadline);
        }
        
        int[] freeTime = new int[max_deadline+1];
        for(int i = 1; i<=max_deadline; i++) {
            freeTime[i] = -1;
        }
        
        
        int k = 0;
        int profit = 0;
        
        int curr_time = 0;
        for(int i = 0; i<n; i++) {


            // While traversing the jobs in descending order of profit, we find a time to schedule the job
            // The time is anything between 1 to deadline
            // We try to schedule it as close to deadline as possible, so that other jobs with lesser deadline can be accomodated
            
            for(int j = arr[i].deadline; j>=1; j--) {
                
                if(freeTime[j] == -1) {
                    k+=1;
                    profit+=arr[i].profit;
                    freeTime[j] = 1;
                    
                    break;
                }
            }
        }
        
        ans[0] = k;
        ans[1] = profit;
        return ans;
        
    }
}