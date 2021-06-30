/*
        This is a helper function which is gonna make the recursive calls
        Complexity analysis
        1. Because of recursion, it will take LogN time
        2. Again, because of recursive call, we are gonna keep allocating in the stack frame, so it will be exponential, (LogN)
    
    */
    
    int getAns(int i, int j, int m, int n)
    {
        if(i == (m-1) && j == (n-1))
            return 1;
        if(i > m || j > n)
            return 0;
        
        return getAns(i+1, j, m, n) + getAns(i, j+1, m, n);
    }
    
     int getAns(int i, int j, int n, int m, vector<vector<int>>& DP)
    {
        if(i == (n-1) && j == (m-1))
            return 1;
        if(i > n || j > m)
            return 0;
         
         
        if(DP[i][j] != -1)
            return DP[i][j];
         
        else
           return DP[i][j] = getAns(i+1, j, n, m, DP) + getAns(i, j+1, n, m, DP);
    }
    
    int uniquePaths(int m, int n) {
        
        /*
            My approach, we can solve this using backtracking
            1. From end, to reach end point, there are basically 2 ways
                -> We come down from some point, or come to right from some point (if those points exist)
            2. Now, for each of those points which exist, can count the possibilties of reaching those points
            
            -> This way, we can count the unique paths
            
            Complicate to code
        */
        
        
        // Trying out the brute force approach, which basically means, I have to recursively traverse all the possibilites (left or down, whichever possible)
        // return getAns(0, 0, m, n);
        
        
        /*
            Optimial approach is basically the recursive approach but with a Table which checks if we have visited or not
        */
        
        
        vector<vector<int>> DP(m+1, vector<int>(n+1, -1));
        return getAns(0, 0, m, n, DP);
    }