/*
    Given an array of size n and an integer k
    Print k largest elements.
    Example - if k = 3, print largest, second and third largest elements
*/

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int> v;
	    sort(arr, arr+n, greater<int>());
	    for(int i = 0; i<k; i++ ) {
	        v.push_back(arr[i]);
	    }
	    return v;
	}

};