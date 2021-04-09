/*  
    Celebrity - It is a person who knows nobody but is known by everybody

    If we have 5 people in a party, we will be given a matrix of 5x5
    This matrix is filled with 0s and 1s

    0   1   1   1   1
    1   0   0   1   0
    1   0   0   1   0
    0   0   0   0   0
    0   1   0   1   0

    And this matrix represents that, on whichever cell we have the value 1, we say that ith person knows kth person
    Example, 0 knows 1, 0 knows 2,3,4
    1 knows 3
    2 knows 3
    4 knows 1 ... etc

    So, from above matrix we can see, 3 knows nobody (entire row is 0), but everybody knows 3 (apart from 3 itself and that is fine), therefore 3 is a celebrity


    Approach - 

    1. We are taking an elimination kind of approach
    2. We push all the people in a stack (5 people means, 0 1 2 3 4)
    3. We pop them in pairs and check if one of them is a potential celebrity (he is known by the other)
    4. We push the potential celebrity back in stack
    5. We pop until we have only one candidate in the stack
    6. Then, we check if he is a celebrity (he knows no one, and is known by everyone apart from himself)

*/

class Solution {
    public:
    
    int isCelebrity(vector<vector<int>>& M, int a, int b) {
        
        vector<int> a_knows = M[a];
        if(a_knows[b] == 1) {
            return b;
        }
        else {
            vector<int> b_knows = M[b];
            if(b_knows[a] == 1) {
                return a;
            }
            else {
                return INT_MAX;
            }
        }
    }
    
    int celebrity(vector<vector<int> >& M, int n) {
        stack<int> boys;
        for(int i = 0; i<n; i++) {
            boys.push(i);
        }
        
        // Some logic + if isCelebroty returns > N, then none of the boys is a celebrity
        
        while(!boys.empty()) {
            
            int a = boys.top();
            boys.pop();
            
            if(!boys.empty()) {
                int b = boys.top();
                boys.pop();
                
                int celeb = isCelebrity(M, a, b);
                if (celeb < n) {
                    
                    boys.push(celeb);
                }
            }
            else {
                // This means 'a' is the last element in the stack
                
                // Check if a knows anyone
                for(int i = 0; i<n; i++) {
                    if(M[a][i] == 1) {
                        return -1;
                    }
                }
                // Confirm that a is known by everybody apart from itself
                for(int j = 0; j<n; j++) {
                    
                    if(M[j][a] !=1 && (a!=j)) {
                        return -1;
                    }    
                }
                
                return a;
            }
            
        }
        
    }
};