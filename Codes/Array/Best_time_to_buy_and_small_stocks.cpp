#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Basic intuition (Pen - paper approach)
        -> We have to find the minimum and maximum while i < j
        -> Or we can put it like this, we have to return a valid answer (max_stock_price - min_stock_price) while i < j else return 0

    Approach
        -> Keep track of minimum at each step
        -> Keep track of profit this minimum is generating at each step, if it is more, then we update, else keep it's previous value
*/

int maxProfit(vector<int>& prices) {
       
    int n = prices.size();
    
    int i = 0, j = n-1;
    int ans = 0;
    
    int min_ = INT_MAX;
    
    for(int i = 0; i<n; i++)
    {
        min_ = min(min_, prices[i]);
        ans = max(ans, prices[i] - min_);
    }
    
    return ans;
}