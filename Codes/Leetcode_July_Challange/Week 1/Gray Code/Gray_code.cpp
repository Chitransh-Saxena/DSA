/*
    Gray Code - 
    -> While going from one to another binary representation of a number
        -> Only 1 bit has to change
    
    For 2 bits
        -> 00, 01, 11, 10
    For 3 bits
        -> 000, 001, 011, 010
        -> Here, from 010 to 000 has more than 1 bit difference, so this would be wrong
        -> So, what we do here, we pick the bits from 2 bit code, and write them in reverse order
        -> 10, 11, 01, 00
        -> Now, prefix all with 1
        -> 110, 111, 101, 100
    For 4 bits
        -> Same logic can be applied
*/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<int> grayCode(int n)
{
    vector<int> ans;
    ans.push_back(0);
    
    if(n == 0)
        return ans;
    ans.push_back(1);
    
    int pow = 1;
    for(int i = 2; i<=n; i++)
    {
        pow = pow * 2;
        for(int j = ans.size() - 1; j>=0; j--)
        {
            ans.push_back(pow + ans[j]);
        }
    }
    return ans;
}

// This is another complicated solution, I need to understand this
// TODO- Understand this 
// Recursive function, understand this
void getAns(bitset<32>& b, vector<int>& v, int n)
{
    // Base case
    if(n == 0)
        v.push_back(b.to_ulong());
    else
    {
        getAns(b, v, n-1);
        b.flip(n-1);
        getAns(b, v, n-1);
    }
}

vector<int> grayCode(int n)
{
    int s = pow(2,n);
    
    bitset<32> b;
    vector<int> result;
    
    getAns(b, result, n);
    return result;
}