/*
    Here the string can contain upper and both lower case, and maybe spaces, or some invalid characters
    We have to make sure we are just comparing alphanumeric characters ignoring the others

*/



bool isPalindrome(string s) {
        
        int l = 0;
        int r = s.size()-1;
        
        while(l<r)
        {
            // After this l will point to a valid character
            while(l<r && !isalnum(s[l]))
            {
                l++;
            }
            
            // After this r will point to a valid character
            while(l<r && !isalnum(s[r]))
            {
                r--;
            }
            
            // Once we have a valid character, we just have to make sure, they are in the right case before comparison
            if(l>r || (toupper(s[l++]) != toupper(s[r--])))
            {
                return false;
            }
        }
        
        
        return true;
    }