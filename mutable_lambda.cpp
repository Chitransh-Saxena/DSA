#include<iostream>

using namespace std;

int main()
{
	int cats = 5;
	
	/*
	[cats](){
		cats = 8;    //This gives error
		cout << cats << endl;
	}();
	*/

	[cats]() mutable{
		cats = 8;
		cout << cats << endl;
	}();

	return 0;
}
