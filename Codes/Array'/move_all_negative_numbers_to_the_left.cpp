#include<bits/stdc++.h> 
using namespace std; 


void rearrange(vector<int>& v)
{
    int index = 0;
    for(int i = 0; i<v.size(); i++)
    {
        if(v[i] < 0)
        {
            swap(v[index], v[i]);
            index+=1;
        }
    }
}
  
// Driver code 
int main() 
{   
    vector<int> v = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    rearrange(v);
    for(int x: v)
    {
        cout << x << " ";
    }
    cout << endl;
} 