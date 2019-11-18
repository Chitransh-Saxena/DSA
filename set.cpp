#include<iostream>
#include<set>
#include<string>
#include<functional>

using namespace std;

//associative container that constains a sorted set of unique objects(all elements are sorted and unique)
//Implemented using Red-Black Tree
//Insertion, Removal Search have o(logn) complexity
//We can pass comparator

class Boy{

	public:
		int age;
		string name;



//	bool operator < (const Boy& b){ return age < b.age; }
};


struct Compare{
	
	bool operator()(const Boy& lhs, const Boy& rhs)
	{
		return lhs.age > rhs.age;
	}
};
/*ostream& operator<<(ostream& stream, Boy& boy)
{
	return stream << boy.age << "\t " << boy.name;
}
*/





int main()
{
	set<int> Set = { 1,2,3,4,5,6,1,2,3,4};
	set<Boy, Compare> people = {{20, "Fameer"}, {21, "Bhuvan"}, {32, "Titu"}};

	for(auto &x: people)
	{
		cout << x.age << " " << x.name << endl;

	}
}
