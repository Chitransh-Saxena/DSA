#include <iostream>


/*
    Friend member can access private member

    Post Code review
        -> We are using the class name Complex in Calculate, so we have to tell the compiler the class exists
            -> Else it will throw compilation error
            -> We use forward declaration for that
        -> We are not able to implement the entire function in the Calculate class. Why?
            -> Because compiler is not sure that 'real' member exists. Why?
                -> Because class is not defined yet
            -> How to overcome?
                -> Make a function prototype now, and declare the function after the classes are defined
*/


class Complex;

using namespace std;

class Calculate
{
public:
    /*
            // At this point, this fails, because compiler is not sure that Complex class has any member named real or not
            int getSum(Complex& c1, Complex& c2) const
            {
                return c1.real + c2.real;
            }

        */

    // Possible solution of above problem, do a method declaration, nth else
    int getSum(Complex &c1, Complex &c2);
};

class Complex
{
    friend int Calculate::getSum(Complex &c1, Complex &c2);

    // a + ib;
private:
    int real;
    int com;

public:
    Complex(int real, int com)
    {
        this->real = real;
        this->com = com;
    }

    void printNumber()
    {
        std::cout << this->real << " +i" << this->com << "\n";
    }
};

int Calculate::getSum(Complex &c1, Complex &c2)
{
    std::cout << c1.real + c2.real;
}

int main()
{
    Complex c1(2, 3);
    c1.printNumber();

    Complex c2(5, 6);

    Calculate calc;
    calc.getSum(c1, c2);
}