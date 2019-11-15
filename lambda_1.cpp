#include<iostream>

using namespace std;


void Test(void (*check)())
{
	check();
}


int main()
{
	auto lambda = [](){ cout << "Testing" << endl;};

	lambda();
	Test(lambda);

	Test([](){cout << "Passing Lambda Expression where it expects function pointer because that is compatible" << endl; });	

	return 0;
}

