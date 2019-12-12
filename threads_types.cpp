//Threads can be created using callable objects
//Creating multiple threads at same time doesnt guarantee which will start first

//Can create thread using any of the following:
//1. function pointer //Not mentioned here, was quite obvious
//2. Lambda
//3. Functor
//4. non-static member functin ...We need object in order to call non-static member function
//5. Static member functions, object is not required because static data members are not related to any indivisual instance of class(object), ratherm, they are directly
//associated with class itself
#include<iostream>
#include<thread>

using namespace std;


class Base{
	public:
	void operator()(int x)     //Creating functor
	{
		while(x>0)
		{
			cout << x << endl;
			x--;
		}
	}

	void run(int x)
	{
		while(x>0){
			cout << x << endl;
			x--;
		}
	}
	static void run_2(int x){
		while(x>0){
			cout << x << endl;
			x--;
		}
	}
};

int main()
{
	thread t1([](int x){				//This one is created using Lambda
			while(x>0)
			{
				cout << x << endl;
				x--;
			}}, 10);
	t1.join();

	thread t2((Base()), 10);   //Calling functor
	t2.join();
	
	Base b;

	thread t3(&Base::run, &b, 10);   //The syntax includes, mentioning address of function(just like function pointer), address of object
       	t3.join();	
	
	thread t4(&Base::run_2, 10);
	t4.join();
	
	return 0;
}

