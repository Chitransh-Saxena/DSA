/*
    We do binary search to find the square root of a number
    We try to set range in which the answer could be found and keep finding it

    For numbers like 16 -> 4 ...we found perfect answer

    FOr numbers like 8 -> root is 2.8 ...This has to be rounded off to 2 ....
    So, in this case, when we do binary search, we are gonna be stuck in a while loop where 2*2 = 4, which is less than 8
    and 3*3 = 9, which is more than 8

    Our while loop will end here because at this point l = 3 and r = 3; (while l<r)
    So, since we know our answer is 2, we after dry running this for few other values....if the while loop has run fully, we return l-1
*/


int mySqrt(int x) {
        
        if(x<2)
            return x;
        
        
        int l = 1;
        int r = x;
        
        long long mid = 0;
        while(l<r)
        {
            mid = l + (r-l)/2;
            
            if(mid*mid == x)
            {
                return mid;
            }
            
            if(mid*mid > x)
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        
        // Because if we did not find the number in the while loop, it has to be the last known mid element, this concept came up in dry run
        return l-1;
        
    }