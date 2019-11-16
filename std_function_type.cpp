#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

bool check(string &s)
{
	return s.size() == 3;
}

class Check{
	public:
		bool operator()(string &s){
		return s.size() == 5;
	}
} check_obj;


void run(function<bool(string)> func) {    // Here in arguements I declared a function which returns bool and takes string as arguement, now, I can pass a method of this type as arguement to 'run'
	cout << func("dog") << endl;
}

int main()
{
	vector<string> vec{"one", "two", "three" };

	//int cunt = count_if(vec.begin(), vec.end(), [](string test){return test.size()==3;});  //This lets us count number of strings in that range with size of 3

	//cout << cunt << endl;

	int count = count_if(vec.begin(), vec.end(), check_obj); //We can pass in anything to count_if that is callable

	cout << count << endl;

	run([](string t){ return t.size() == 3;});



	function<int(int, int)> add = [](int a, int b){ return a+b; };

	cout << add(5,6) << endl;



}
