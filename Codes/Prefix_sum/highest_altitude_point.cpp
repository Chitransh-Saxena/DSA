int largestAltitude(vector<int>& gain) {
        
        /*
            We are given a prefix sum kind of array, convert it to regular array
            Pen-paper approach worked
        */
        
        int arr[gain.size()+1];
        arr[0] = 0;
        int ans = 0;
        for(int i = 1; i<=gain.size(); i++)
        {
            arr[i] = gain[i-1] + arr[i-1];
            // cout << arr[i] << " ";
            ans = max(ans, arr[i]);
        }
        
        return ans;
        
    }
};