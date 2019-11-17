#include<iostream>
#include<cstdlib>
#include<cstring>

struct vec2{

	float x,y;
};


class strings{

	private:
		char* m_Buffer; //A buffer to store stirng
		unsigned int m_Size;
	public:
		strings(const char* str)
		{
			m_Size = std::strlen(str);
			//m_Buffer = new char[m_Size]{str};  //This was a trial to see if this method works, so basically compiler is trying to give values to each byte of m_Buffer. each value being, whatever
// variable str has. I cannot copy char* like this. need memcpy
 			m_Buffer = new char[m_Size]; //Here I did not take care of the null termination. still it worked, dont know how, usually need +1 size
			memcpy(m_Buffer, str, m_Size); //strcpy includes the null termination

		}

	friend std::ostream& operator<<(std::ostream& stream, const strings& str);  //Declared friend cause we are going to use this to access private members of this class

};

//In below written code, I am overloading the '<<' operator to return a type 'outputstream' object, where it takes paramaters as given below
//str is class reference passed to operator, and it accesses the required variable and puts into the output stream, from where it goes to 'stream' object of output stream.
//then it returns the same, simple!!!!.

std::ostream& operator<<(std::ostream& stream, const strings& str)
{
	stream << str.m_Buffer; 
	return stream;
}	

//Writing this method because we want to print something to string using this class to standard cout


int main()
{



		strings st = "Chitransh";
		std::cout << st << std::endl;

	

	
	/*
		int a = 2;
		int b = a; //Here I have created copy of a, when I modify b, it does not affect a;

		b = 3;

		vec2 a2 = {2, 3};
		vec2 b2 = a;


		b.x = 5;  //In this case also, we created a copy, so if I modify b.x, a.x will remain the same;

		//Let's see what happens in case of pointers
		//

		vec2* a1 = new vec2();
		vec2* b1 = a1;  //In this case, I have created a pointer which points to the same memory location as a1. So, if I modify something using b1, I will see change in a1 as well, because they point to same memory location

		b1++; //This will increament pointer address by 1 of b1. Nothing happens in relation to a1.

		b1 -> x=3; //Here, I modified value, this will be reflected when i use a1.

	*/



}
