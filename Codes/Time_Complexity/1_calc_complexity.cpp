#include <iostream>

using namespace std;

int main()
{

    int a = 0;                          //O(1)
    for(int i = 0; i<10; i++)
    {
        a+=1;                           // O(1) * 10 times
    }

    cout << a;                          // O(1) 
}

// So, total time complexity of above code will be O(1) + O(1)*10 + O(1) = 12 * O(1) = O(12)
// So, O(1) can be treated as negligible one as compared to O(10) or O(n) where n is max number of times for loop is ran

int complexFunction(int a)
{
    for(int i = 0; i<20; i++)               //O(20)
    {
        for(int j = 0; j<10; j++)           // O(10)
        {
            a+=1;                           // This step will be executed O(1)*10*20 = O(1)*n*m
        }
    }

    return a;

    // In this case, for each step of i, j is run 10 times.
    // So, we can say, for each n, operation will happen m times
    // 

}