/*
    Custom functions are implemented over the standard stack
    Implement a function that returns minimum value from the stack in O(1) time and O(1) auxilliary sapce
*/
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends


int min_val = 2147483647;

void push(stack<int>& s, int a){
	// Your code goes here
	if(s.empty()) {
	    min_val = a;
	    s.push(a);
	}
	else {
	    s.push(a);
    	min_val = min(a, min_val);
	}
	
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size() == n) {
	    return true;
	}
	else {
	    return false;
	}
}

bool isEmpty(stack<int>& s){
	// Your code goes 
	if(s.size() == 0) {
	    return true;
	}
	else {
	    return false;
	}
}

int pop(stack<int>& s){
	// Your code goes here
	if(s.size() >0) {
	    int x = s.top();
	    s.pop();
	    return x;
	}
	else {
	    return -1;
	}
}

int getMin(stack<int>& s){
	// Your code goes here
	return min_val;
}