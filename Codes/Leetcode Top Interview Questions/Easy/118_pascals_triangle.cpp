/*
    We know first and last values are 1. We put them as it is
    For middle value we know it is sum of above 2 cells, so we simply take that sum and add them to the resulting vector
*/


vector<vector<int>> generate(int numRows) {
        

        vector<vector<int>> ans;
        vector<int> v1 = {1};
        
        ans.push_back(v1);
        
        for(int i = 1; i<numRows; i++)
        {

            vector<int> v;
            v.push_back(1);
            
            for(int j = 1; j<i; j++)
            {
                v.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            v.push_back(1);
            
            ans.push_back(v);
        }
        
        return ans;
        
    }