/*
    Standard approach of checking character by character for each string does not work here because it is too much time consuming
    and some extra corner cases pop up too
    
    
    So, we will first check the first character of each string, then second ....as soon as 1 of them mismatches, we break
*/




int getShortestLength(vector<string>& strs)
{
    int len = strs[0].size();
    for(int i = 1; i<strs.size(); i++)
    {
        len = min(len, (int)strs[i].size());
    }
    
    return len;
}
    
    
string longestCommonPrefix(vector<string>& strs) {
    
    if(strs.size() == 0)
        return "";
    if(strs.size() == 1)
        return strs[0];
    
    
    string ans = strs[0];
    int min_len = getShortestLength(strs);
    ans = ans.substr(0, min_len);
    for(int i = 0; i<min_len; i++)
    {
        
        char curr = ans[i];
        
        for(int j = 1; j<strs.size(); j++)
        {
            if(curr != strs[j][i])
            {
                ans = ans.substr(0, i);
                return ans;
            }
        }
    }
    
    return ans;
    
}