#include <iostream>
#include <vector>

/*
    So, we have a base class. It has certain attributes and behaviours (data and methods).
    Now, we can have another class, that may inherit from that base class and it will aquire all the attributes and behaviours of that class.

    Now, why would we need this?
    So, imagine we have a company of Cars, and we are gonna design some softwares for those cars. Now my company is having different types of cars, like super cars, regular cars
    Luxury cars ...etc

    So, there would be some features of that software, which would be common to all kind of cars, and then, there would be some features, that would be specific to that certain category
    Now, for the common features, we would be forced to write a repeated code, and that it is just not right.

    Instead, we can have a base class named cars. That will have basic attributes and behaviours. Now all the other type of car classes will inherit from this, have the features of base clas
    as well as their own features.

    This way, we create a clean heirarchy, and a better looking code. So, whenever we need to modify some common feature, we just modify the base class.

*/

class Employee 
{
    // Private property will not be accessible to derived classes. We make these properties as 'protected' so that they can be accessed directly by derived classes without using getters
    // If we want to force the use of getters, we can make these properties as private
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
};

// Default inheritence is private, this means Developer will not have access to methods of Employee directly when Developer object is created
// Developer object will not have access if "default inheritnce" happens, only time we can access those methods is inside this class's methods

// In order to fix that, we put 'public' access modifier before base class
class Developer : public Employee      // Developer is inheriting from Employee
{
    // So, now developer class has properties and methods of Employee
    
    private:
        std::vector<std::string> programming_languages;
    
    public:

        /*
            If we do not provide any constructor to this class, it should call it's default constructor by default.
            But that is not the case for a class which inherited from some other class.
            The default constructor gets destroyed as soon as we have our own constructor. But we did not create any constructor for this yet, so why will it throw error?
            Because, it inherited even the constructor of it's base class, and thus all the hassle.
        */

        // We are able to use the first 3 args because we inherited them from base class
        // But we do not need to set them again here, we already have a constructor for those properties, so we are just gonna call that.
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
            // Note, derived class does not have access to base class's private members
            // If we make any property as protected, that property will be accessible to that class and it's derived classes as well
            std::cout << e_name << "'s favorite programming languages are - \n"; 
            for(std::string language: programming_languages)
            {
                std::cout << language << "\n";
            }
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

};

int main ()
{
    Developer dev = Developer("Lee", "Konoha", 18, {"C++", "Java", "Python", "Bash Scripting"});
    // std::vector<std::string> langs = dev.getLanguages();
    // dev.showFavLanguages(langs);
    // dev.askForPromotion();

    Teacher t = Teacher("Sangeetha", "SRM", 30, "Networking");
    t.prepareLesson();
    t.askForPromotion();

}