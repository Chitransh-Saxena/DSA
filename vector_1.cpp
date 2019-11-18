#include<iostream>
#include<vector>

using namespace std;

//it is a "sequence container", size can grow and shrink dynamically

//Problem:
//	whenever capacity reaches end, it doubles the size, creates another array, copies stuff to new array, destroys old array. These many operations take time.

//Solution:
//	we reserve some block of memory for the vector, and till size is that, capacity will remain same, avoiding so many internal operations.
//	array has o(1) access time.
//	Also, emplace_back helps us put the values directly to the memory allocated for container insted of first putting to heap of main menu, then copyong. Saces time and memory

int main()
{
	vector<int> v;
	v.reserve(10);

	for(int i = 0; i< 10; i++)
	{
		v.emplace_back(i);
		cout << "Size = " << v.size() << "\t" << "Capacity = " << v.capacity() <<endl;
	}
}

