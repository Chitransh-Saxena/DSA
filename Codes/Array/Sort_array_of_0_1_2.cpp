/*
    Used count sort approach

    
*/
#include <iostream>
#include <map>

using namespace std;

// Count Sort approach, but very noobish
// O(n) + O(n) = O(2n)
void sort012(int a[], int n)
{   
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        m[a[i]]++;
    }
    
    int i = 0;
    for(; i<m[0]; ++i) {
        a[i] = 0;
    }
    
    for(; i<n && (m[1] > 0); ++i, m[1]--) {
        a[i] = 1;
    }
    for(; i<n && (m[2] > 0); ++i, m[2]--) {
        a[i] = 2;
    }
    
}

// Next approach is to do a selection sort type of thing
// This is a variation of german flag algorithm problem
void sort012(int a[], int n)
{
    int l = 0, mid = 0, end = n-1;

   while(mid <= end)
   {
       switch(a[mid])
       {
            case 0:
                swap(a[mid++], a[l++]);
                break;
            case 1:
                mid+=1;
                break;
            case 2:
                swap(a[mid], a[end--]);
                break;
       }
   }

}
