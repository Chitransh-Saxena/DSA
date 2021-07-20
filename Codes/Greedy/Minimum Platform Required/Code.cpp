/*
    Original intuitive approach was to sequentially traverse the start and end time of the array, get the maximnum consecutive platforms required
        -> This did not work, idk why

    Internet's approach
        -> Sort the start and end time
        -> This will make the start and end time for the original ith train out of sync, but helps in a greater idea
        -> The idea now is, we look at the start time, and end time at ith index
            -> If the s[i] < dep[i], we can keep 1 train, and move towards the start time of next train
                -> Do not move the dep time
            -> Now, we compare start time of this second train with the first departure time, if current time is greater
                -> This means, we need one more platform
        -> Just read through the while loop part of code, for better understanding
*/


int findPlatform(int arr[], int dep[], int n)
    {
    	int ans = 0;
    	int curr = 0;
    	
    	sort(arr, arr+n);
    	sort(dep, dep + n);
    	
    	/*
    	    Since we sorted, we might not have the track of which train came at what time
    	    But, we still have the track of last starting and least ending time
    	    Now, based on this, we can select the number of platforms required
    	*/
    	
        
        int j = 0;
    	int last_departure = dep[j];
    	for(int i = 0; i<n; i++) {
    	    
    	    if(arr[i] <= last_departure) {
    	        curr+=1;
    	    }
    	    else {
    	        i-=1;
    	        curr -=1;
    	        j+=1;
    	        last_departure = dep[j];
    	    }
    	    
    	    ans = max(curr, ans);
    	}
    	
    	
    	/*
    	int i = 0;
    	int j = 0;
    	
    	int last_dep = dep[0];
    	
    	while(i<n) {
    	    
    	    if(arr[i] <= dep[j]) {
    	        curr+=1;
    	        i+=1;
    	    }
    	    else {
    	        curr-=1;
    	        j+=1;
    	    }
    	    
    	    ans = max(curr, ans);
    	    
    	}
    	*/
    	
    	return ans;
    }