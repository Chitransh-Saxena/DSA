bool isValid(string s) {
        
       /*
            Idea - 
                1. Brackets can be opened in any sequence, we just have to make sure that they are closed in that sequence
                2. So, we basically need a way to check that if there is any closing bracket, is it of the expected opening bracket
                    2.1. We can maintain a stack of opening brackets, in the right order, if encounter any closing bracket, we can just lookup that stack
                    2.2 Ideally, since stack is FILO, the last open bracket must be at the top
                    2.3 So, it must match the closing bracket
                    2.4 Once checked, we can take a decsion and move forward
                3. Post this, we just have to check the standard corner cases
       */
       
       int n = s.size();
       
       if(n&1)
       {
           return false;
       }
       stack<char> st;
       
       
       for(int i = 0; i<n; i++)
       {
           
           if(s[i] == '(' || s[i] == '{' || s[i] == '[')
           {
               st.push(s[i]);
           }
           else
           {
               
                // NOTE - If these conditions are written separately, it makes it hard to write the conditions
               if((s[i] == ')' && !st.empty() && st.top() == '(') || (s[i] == ']' && !st.empty() && st.top() == '[') || (s[i] == '}' && !st.empty() && st.top() == '{'))
               {
                   st.pop();
                   continue;
               }
               else
                   return false;
               
               
           }
       }
       
       if(!st.empty())
       {
           return false;
       }
       
       return true;
    }