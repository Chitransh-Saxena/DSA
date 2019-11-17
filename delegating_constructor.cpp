#include<iostream>
using namespace std;


class A
{
	public:
		A(string t)
		{
			cout << "Hi " << t << endl;
		}

		A() : A("Jabba") {
			cout << "Default Parent" << endl; }
};

class B: public A{
	
	//public: string T = "Tia";
	public:
		B(){
		cout << "child constructor" <<endl; }
};







int main()
{
	//Here what basically happens is, B inherits all members of Parents but definition reside in parent, so parent constructor is called.
	//b calles default constructor of A which internally calls another constructor within same class, that is delegating constructor
	B b;
}



