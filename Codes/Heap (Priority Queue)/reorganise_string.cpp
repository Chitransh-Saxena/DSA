/*

    We are given a string of characters and we want to make sure that no 2 characters are adjacent
    If we can do that, we return the modified string, else we return an empty strin

    Approach -
    -> First, we build a frequency array of characters
    -> If the highest frequency is more than half, we are sure cannot build the string like it is expected
    -> Otherwise, we put the characters in a priority_queue
    -> Then we pick in pairs and add it to resulting string
    -> We are choosing priority queue because it will automatically keep the character with max frequency at the top
    -> So, each time we pop up a pair, add it to string, and add it with remaining frequency to pq, pq will auto-adjust
    -> This way, surely use up characters in their reducing frequency
    -> At the end, we check if there is one more element left, and add it to resulting string
*/



class Solution {
public:    
    string reorganizeString(string S) {
        
        // Get the frequency of a character
        // map<char, int> m;
        // for(int i = 0; i < S.size(); i++) {
        //     m[S[i]]++;
        // }
        
        string ans = "";
        int count[26] = {0};
        int n = S.size();
        
        // Building the frequency array
        for(int i = 0; i < S.size(); i++) {
            count[S[i]-'a']++;
        }
        
        // Keeps the element with max frequency at top
        auto comparator = [](pair<int, char> l, pair<int, char> r) {
            
            // If occurence is same, lower alphabet goes first
            // Otherwise, just the higher count goes first
            return l.first == r.first ? r.second < l.second : r.first > l.first;
            
        };
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comparator)> pq(comparator);
        
        for(int i = 0; i < 26; i++) {
            
            if(count[i] > 0) {
                
                if(count[i] > (n+1)/2) {          // Highest occurence is more than half, we cannot organize in that case
                    return "";
                }
                
                pq.push({count[i], (char)(i+'a')});           // (char)(i+a), this converts from character index to actual character
            }
        }
        
        while(pq.size() >= 2) {          // because we are gonna add 2 top most values and add it into the answer string
            
            pair<int, char> p1 = pq.top();
            pq.pop();
            
            pair<int, char> p2 = pq.top();
            pq.pop();
            
            // Once we get the top two values, we insert those characters into our answer string
            ans+=p1.second;
            ans+=p2.second;
            
            // We have to add back the character and it's occurence into the queue
            // Reduce the occurence by 1, check if it is still greater than 0, add it to the queue
            if(--p1.first > 0) {
                pq.push(p1);
            }
            
            if(--p2.first > 0) {
                pq.push(p2);
            }
        }
        
        if(pq.size() > 0) {
            
            // This is the edge case which was not handled in previous while loop
            // There was a chance that in cases of odd characters 1 is still left
            // So, we handle that specifically here
            ans+=pq.top().second;
            pq.pop();
        }
        
        return ans;
    }
};