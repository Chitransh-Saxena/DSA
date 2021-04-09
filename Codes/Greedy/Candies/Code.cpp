/*

So, in this question, we are following a greedy approach, we populate the vector left to right for the basic condition that is given.
Then we follow the same pattern and populate a vector(of assigning number of candies to give) from right to left.
Then, we just take max of at a certain index, add it for all. We are taking max here because that is the worst case scenario of that index.
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> l2r(n, 1);
        vector<int> r2l(n, 1);
        int ans = 0;
        
        
        for(int i=1; i<n; i++) {		
            if(ratings[i] > ratings[i-1]) {
                l2r[i] = l2r[i-1] + 1;
            }
        }
        
        for(int i = n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                r2l[i] = r2l[i+1] + 1;
            }
        }
        
        for(int i=0; i<n; i++) {
            ans += max(l2r[i], r2l[i]);
        }
        return ans;
        
    }
};
