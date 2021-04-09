/*
    {([])} - Fine
    ([] - Not fine
    Write a code to check so
*/

/*
    This approach does not use the concept of stack, it just made sense to me, so I did like this
*/
class Solution{
  public:
    // Function to return if the paranthesis are balanced or not
    bool ispar(string x)
    {   
        if(x.size() == 0) {
            return true;
        }
        // Create 2 maps, for open and close type chars
        map<char, int> m1;
        map<char, int> m2;
        for(int i = 0; i<x.size(); i++) {
            if(x[i] == '(' || x[i] == '{' || x[i] == '[') {
                m1[x[i]]++;
            }
            else if (x[i] == ')' || x[i] == '}' || x[i] == ']') {
                m2[x[i]]++;
            }
        }
        
        if(m1['[']!=m2[']'] || m1['(']!=m2[')'] || m1['{']!=m2['}']) {
            return false;
        }
        return true;
    }

};

/* This approach solves this same problem using stack */
bool ispar(string x)
{
    
    
    stack<char> s;
    
    auto lamb = [](char a, char b){
        if(a=='{' && b=='}')
            return true;
        if(a=='(' && b==')')
            return true;
        if(a=='[' && b==']')
            return true;
    };
    
    for(int i=0; i<x.size(); i++){
        if(x[i] == '{' || x[i] == '(' || x[i] == '[' ){
            s.push(x[i]);
            
        }
        else{
            if(s.empty())
                return false;
            
            else if (lamb(s.top(), x[i])==false)
                return false;
                
            else
                s.pop();
        }
        
    }
    if(s.empty()==true)
        return true;
    else
        return false;
}