#include <iostream>


// Sum till 'n'
int getSum(int n)
{
    if(n == 0)
    {
        return 0;
    }

    int thisSum = getSum(n-1);

    return thisSum + n;
}


// Get x ^ p
long long int getPower(int x, int p)
{
    if(p == 1)
    {
        return x;
    }

    long long int prevExp = getPower(x, p-1);

    return (long long int)x*prevExp;

}

// Factorial
int getFactorial(int n)
{
    if(n == 1)
    {
        return 1;
    }

    return n * getFactorial(n-1);

}


// n'th fibonacci number
int getFibonacci(int n)
{

    if(n == 1)
        return 0;
    
    if(n == 2)
        return 1;

    // Because fibonacci is the sum previous and a number before that
    return getFibonacci(n-1) + getFibonacci(n-2);

}


int main()
{

    std::cout << getSum(5) << std::endl;
    std::cout << getPower(10,2) << std::endl;
    std::cout << getFactorial(5) << std::endl;
    std::cout << getFibonacci(7) << std::endl;
}