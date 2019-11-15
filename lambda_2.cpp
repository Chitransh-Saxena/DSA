#include<iostream>
using namespace std;

int main()
{
	auto pGreet = [](string name){cout << "Hello\t" << name << endl; };
	pGreet("Kajal");


	/*
	auto pDivide = [](double a, double b){ 
		if( b == 0 )
			return 0;
		else
			return a/b; };

	*/
	auto pDivide = [](double a, double b) -> double {     //We use trailing return type in case of multiple return cases where the other types of results will be casted to this one 
		if( b == 0 )
			return 0;
		else
			return a/b; };

	//pDivide(10.0, 0);
	//pDivide(10.0, 3.2);

	cout << pDivide(10.0, 0) << endl;
        cout << pDivide(10.0, 5.0) << endl;	

	
}
