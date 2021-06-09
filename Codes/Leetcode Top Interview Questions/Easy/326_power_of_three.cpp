/*
    For a number to be power of 3, when it is divided by 3, it should always return 0
    We keep doing it till the end
*/


bool isPowerOfThree(int n) {
        
        if(n == 0)
                return false;
        
        while(n!=1) {
            
            if(n%3 != 0)
                return false;
            
            n /=3;
        }
        
        return (n==1);
        
    }