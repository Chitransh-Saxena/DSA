/*
    Used count sort approach

    
*/


void sort012(int a[], int n)
    {   
        // Count Sort approach, but very noobish
        // O(n) + O(n) = O(2n)
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