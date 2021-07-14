#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> twoSum(const vector<int> &A, int B) {

    std::map<int, int> m;
    vector<int> v(2, 0);
    for(int i = 0; i<A.size(); i++)
    {
        int k = B - A[i];
        if(m.find(k) != m.end())
        {
            v[0] = i+1;
            v[1] = m[k]+1;

            if(v[0] > v[1])
                swap(v[0], v[1]);
        }

        if(m.find(A[i]) == m.end())
        {
            m.insert({A[i], i});
        }
    }

    return v;
}

int main()
{   
    vector<int> a = { 4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
    vector<int> v = twoSum(a, -3);

    for(int x: v)
        cout << x << " ";
}