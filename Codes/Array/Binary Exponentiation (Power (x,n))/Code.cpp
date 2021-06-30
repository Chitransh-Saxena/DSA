double myPow(double x, int n) {
   
    long p = n;     // This is to prevent integer overflow
    int num = x;
    
    double ans = 1.0;   // because final answer can become a double type value in some cases of fractional or negative power
    
    if(p < 0)
        p = -1 * p;
    
    while(p>0)
    {
        if(p%2 == 1)
        {
            ans = ans * x;
            p-=1;
        }
        else
        {
            x = x * x;
            p/=2;
        }
    }
    
    // So, if you wanna do 2^ (-10), just get 2 ^ 10 = 1024, and return 1/1024
    if(n<0)
    {
        ans = (double)(1.0)/ans;
    }
    
    return ans;
    
}