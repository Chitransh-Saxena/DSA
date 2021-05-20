#include <iostream>

/*
    What is abstraction ?
    -> It is the process of hiding complex things so that the main process that is happening at the front looks simple.
    -> Example, smartphone - clicking picture is just a press of button, but behind the scenes, so many hardwares and softwares are interacting to make that action smooth and fast.'

    -> So, basically, we want to create some sort of interface between the complex processing and the end user.
    -> So, on the code level, how do we create that interface?
    -> We can use abstract class for that.
*/

/*
    In this example, we can create a interface for a query that will tell if a car is super car or not.
    Super has certain properties like, speed, horse power, torque, engine cc ..etc

    In Example 2, we are gonna check if an employee should get promotion or not, we will create an abstract class to implement that functionality
    That abstract class will serve as a contract, and it will be like, whichever class decides to follow that contract, it has to follow some rules (implement all methods in that abstract class)
*/

class car
{
    private:
        std::string c_name;
        int max_speed;
        int horse_power;
        int torque;
        int engine;
    
    public:

        car(std::string c_name, int max_speed, int horse_power, int torque, int engine)
        {
            this->c_name = c_name;
            this->max_speed = max_speed;
            this->horse_power = horse_power;
            this-> torque = torque;
            this->engine = engine;
        }

        void isSuperCar () {

            if(max_speed > 200 && horse_power > 500 && torque > 670 && engine > 3000)
            {
                std::cout << "Yo, it's a super car\n";
                return;
            }

            std::cout << "Na, it's just a regular car\n";
                
        }
};


// How does a virtual function work?
// How does a pure virtual function work?
class AbstractEmployee
{
    // This is a pure virtual function, this makes the class abstract (any class with pure virtual function is called abstract class)
    virtual void askForPromotion() = 0;
};

// By adding `colon abstract class name` we are forcing our class to sign the contract, or basically follow the rules set by abstract class
// So, this class has to override the functions in abstract class

// We also call it inheritence, but inheritence is a different concept, and here we wanna use the abstraction functionality of that feature.
class Employee : AbstractEmployee 
{
    public:
        std::string e_name;
        std::string company;
        int age;

    public:
        Employee(std::string e_name, std::string company, int age)
        {   
            this->e_name = e_name;
            this->company = company;
            this->age = age;
        }
        void intro() {

            std::cout << "Name : " << e_name << "\n";
            std::cout << "Company :" << company << "\n";
            std::cout << "Age: " << age << "\n";
        }

        // In java spring, we need to add @override annotion, not the case here
        void askForPromotion()
        {
            // Keeping the logic simple in order to avoid complex code, because we just wanna show how this works
            if(age > 30) {
                std::cout << "Yeah, promote him/her\n";
            }
            else {
                std::cout << "Maybe some other day\n";
            }
        }
};


int main ()
{
    car lamb = car("Aventador", 400, 550, 720, 4500);
    // lamb.isSuperCar();

    Employee keshav = Employee("Keshav", "The Nielsen Company", 45);
    keshav.intro();
    keshav.askForPromotion();
}

