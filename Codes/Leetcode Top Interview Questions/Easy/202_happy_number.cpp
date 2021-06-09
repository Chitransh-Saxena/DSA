    bool isHappy(int n) {
        
        /*
        The thing I did not know here was, that when a square is repeated and 1 is not reached, the values of sum of digit sqaure would be repeated
        */
        
        // To keep track of numbers and their digit squares
        map<int, int> m;
        
        while(n!=1)
        {
            int temp = n;

            int sum = 0;
            while(temp>0)
            {
                int t = temp%10;
                temp = temp/10;
                sum += (t*t);
                
            }
            
            if(m.find(n) == m.end())
            {
                m[n] = sum;
                n = sum;
            }
            
            else
            {
                return false;
            }
            
        }
        
        return true;
    }