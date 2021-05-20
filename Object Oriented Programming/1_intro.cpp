#include <iostream>

/*
    A Class is a blue print and not any data.
    A good practise is to keep the variables private, and use getters and setters to access those variables.

    Also few talks about 'this' pointer
*/

// This class represents a blue print of how an Employee would look in terms of code.
// A class is private by default
class Employee 
{
    public:
        std::string e_name;
        std::string company;
        int age;

    public:

        // A constructor is a special kind of method which is invoked each time an object of class is created with those certain parameters.
        // If a constructor is not defined in a class, a default constructor is called and inits with garbage values until we re-assign those values
        // A constructor follows 3 rules - 1. No return type    2. Same name as class   3. Access Modifier = Public
        Employee(std::string e_name, std::string company, int age)
        {   
            /*
            e_name = e_name, this would not reference the class variable on lhs, it would just treat it as assigining parameter 'e_name' to itself.
            To eliminate this problem, we use this pointer

            By using 'this' keyword, we can actually reference the class variables
            'this' is the pointer to the current instance of class. It is NOT referring to this current class, it is referring to this class's current object

            So, the data type of this, would be of clas type, something like this
            Employee* e = this;

            For a constant method, it would look something like this
            const Employee* e = this;
            */
            this->e_name = e_name;
            this->company = company;
            this->age = age;
        }

        /*
        This is also a vallid way to initialize, it is called initializer list

        Employee(std::string e_name, std::string company, int age)
            : e_name(e_name), company(company), age(age)
        */

       void intro() {

            std::cout << "Name : " << e_name << "\n";
            std::cout << "Company :" << company << "\n";
            std::cout << "Age: " << age << "\n";
       }
};

int main ()
{

    // When I am creating an object using 'new' keyword, it will be a pointer to a memory location in heap memory
    Employee* emp1 = new Employee("Bill Gates", "Microsoft", 65);
    emp1->intro();

    std::cout << "------------------------------------\n";
    // Without 'new' keyword, it will be constructed in stack memory of the RAM.
    Employee emp2 = Employee("Mark", "Facebook", 40);
    emp2.intro();


}