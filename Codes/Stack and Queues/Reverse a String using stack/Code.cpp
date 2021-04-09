/*
    Using LIFO functionality
*/

//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    stack<char> s;
    
    for(int i = 0; i<len; i++) {
        s.push(S[i]);
    }
    
    char c[len];
    for(int i =0; i<len; i++) {
        S[i] = s.top();
        s.pop();
    }
    return S;
}