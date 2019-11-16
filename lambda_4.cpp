#include<iostream>
using namespace std;

class Test{

	private:
		int one{1};
		int two{2};

	public:
		void run()
		{
			int three{3};
			int four{3};

			//auto pLambda = [two, three, four](){    //Here we can not use two, that is instance variable. To use two, we can use 'this', that captures all instance variables	
			//	cout << two << ", " << three << ", " << four << endl;}();
			
			auto pLambda = [this, three](){ cout << one << "\t" << three << endl; };
			pLambda();

		}

	};

int main()
{
	Test t;
	t.run();
}

