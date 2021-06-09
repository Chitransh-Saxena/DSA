/*
    TODO - Recursive solution of this approach

*/
void reverseString(vector<char>& s) {        
        
        int k = s.size();
        for(int i = 0; i < s.size()/2; i++) {
            swap(s[i], s[k]);
            k--;

        }
    }