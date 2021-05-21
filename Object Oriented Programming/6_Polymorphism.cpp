#include <iostream>
#include <vector>

/*
    4th principle of Object Oriented Programming
    Polymorphism - Greek word which means 'poly' - many, 'morph' - form. In short, it means many forms.
    In programming, it simply becomes the ability of an object or method to have many forms.

    To always remember, where most people start getting confused - 'When a parent class object is referring to a child class method'


    POST CODE REVIEW - 

    What happened?
    1. We created a method of same name and type and args in 1 base, and 2 derived classes (void work())
    2. In main method, we created object of Dev and Teacher (both derived classes)
    3. We create a pointer of type Employee (base class) and store the reference of developer in that pointer. (Employee *e1 = &dev)
    4. Repeat step 3 for Teacher object (Employee *e2 = &t)
    5. Now, we call  work() from these 2 Employee pointers. We notice that it calls the method implementation in the base class. (Expected, coz nth special happening yet)
    6. To play with polymorphism, we go to Employee class implementation of work() method, and make it 'virtual'
    7. So, now, when Employee pointer (which was referring to Developer and Teacher object) invoked work() method, the code searched for 'most derived implementation of that method'
    8. And that implementation of the method was executed

    TODO - In long term, why would we wanna do this? Why don't we just do dev.work()?
*/


class Employee 
{
    protected:
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

       std::string getName()
       {
           return e_name;
       }

       void askForPromotion()
       {
           if(age > 25)
           {
               std::cout << "Promoted\n";
               return;
           }

           std::cout << "Sorry, no promotion\n";
                
       }

        // Why make a function virtual?
        // When a virtual function is invoked, there is a check for the implementation of same function in the derived classes
        // If yes, execute that. If no, execute this function
        virtual void Work()
        {
            std::cout << "An Employee has to work a lot\n";
        }
};

class Developer : public Employee
{    
    private:
        std::vector<std::string> programming_languages;
    
    public:

        Developer (std::string e_name, std::string company, int age, std::vector<std::string> programming_languages)
            : Employee(e_name, company, age)
        {
            this->programming_languages = programming_languages;
        }
        void setLanguages(std::vector<std::string> langs)
        {

            programming_languages = langs;
        }

        std::vector<std::string> getLanguages()
        {
            return programming_languages;
        }

        void showFavLanguages(std::vector<std::string> programming_languages)
        {   

            std::cout << e_name << "'s favorite programming languages are - \n"; 
            for(std::string language: programming_languages)
            {
                std::cout << language << "\n";
            }
        }

        void Work()
        {
            std::cout << "An employee who is a developer, has to write new code, fix bugs\n";
        }

};

class Teacher: public Employee
{   
    private:
        std::string mainSubject;

    public:

        Teacher(std::string e_name, std::string company, int age, std::string mainSubject)
            : Employee(e_name, company, age)
        {
            this->mainSubject = mainSubject;
        }

        void prepareLesson()
        {
            std::cout << e_name << " is preparing lesson of " << mainSubject << "\n";
        }

        void Work()
        {
            std::cout << "An employee who is a teacher, has to teach students\n";
        }

};

int main ()
{
    Developer dev = Developer("Lee", "Konoha", 18, {"C++", "Java", "Python", "Bash Scripting"});
    Teacher t = Teacher("Sangeetha", "SRM", 30, "Networking");

    dev.Work();
    t.Work();

    // When a parent class object is referring to a child class method
    // Here, a pointer of type Employee, is holding reference of derived class object.
    // Why do even wanna do this? - Because Developer IS an employee after all. But how does it help is in code, let's see ...

    // When we make the function 'virtual' on which we wanna achieve polymorphism, then the function of derived class can be called from Parent class object
    // Also, only pointer or reference of base class type can be used for virtual function
    Employee *e1 = &dev;        // This can be read as Pointer of type Employee is pointing to Deveoper object, even if it is of Employee type
    e1->Work();

    Employee *e2 = &t;
    e2->Work();

    // In case of confusion at this point, go to line 12

}