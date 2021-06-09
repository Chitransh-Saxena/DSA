int trailingZeroes(int n) {
     
        /*
            Concept - To find any number of 'k's up until number 'n'
            
            1. We do { floor(n/pow(k,1)) + floor(n/pow(k,2) + floor(n/pow(k,3) + ... + floor(n/pow(k,n)}
            2. We do this up until the end or when floor of the 10/pow(k, x) becomes 0, x here being any number which may cause the floor to be zero
        */
        
        if(n<5)
        {
            return 0;
        }
        
        int ans = 0;
        int i = 1;
        int temp = floor(n/5);
        while(temp!=0)
        {
            temp = floor(n/(pow(5,i)));
            ans+=temp;
            i+=1;
        }
        
        return ans;
    }