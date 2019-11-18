#include<iostream>
#include<array>

using namespace std;

int main()
{
	array<int, 5> ar;
	ar = { 1, 2 ,3 ,4 ,5}; //Passing initializer list to array class object, this was not possible in c-style array

	cout << "Element at 4 : " << ar.at(4) << endl;
	cout << "Element at front : " << ar.front() << endl;

	cout << "ar.data() : " << ar.data() << endl; //This method gives us pointer to the original underlying array which is inside the array class obj 'ar'.

}
