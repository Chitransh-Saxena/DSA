#include<iostream>
using namespace std;

int main()
{
	int one = 1;
	int two = 2;
	int three = 3;
	
	//This is lambda expr to capture 1 element by value else, lambda can't use member variables, they need to be captured
	[one](){ cout << one << endl; };

	//If we want to call it immidiately, like a method, we add parenthesis and call normally.
	[one](){ cout << one << endl; }();  	

	//This is to capture all local variables by value, we cannot modify the variables captured by value
	[=](){ cout << one << ", " << two << endl; }();

	//This is to capture all local variables by reference. We CAN modify variables captured by reference
	[&]() { cout << three << ", " << two << ", " << one << endl; }();

	//This is to capture everything by reference except two
	[&, two]() { cout << one << ", " << two << endl; }();




	return 0;
}
