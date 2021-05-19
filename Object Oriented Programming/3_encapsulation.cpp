#include <iostream>

/*
    The idea behind encapsulation is bundeling the data and methods that operate on that data so that they are grouped together in a class.
    Why do we do that? 
        -> To be able to prevent anyone from directly access the data and modify the data
        -> We still want to keep some provision for modifying the data, we just do not want that to happen directly
        -> We want to provide our own way (method) for that to happen, so that any modification that takes place, is under our control.
        -> We keep our data variables private and make the methods that modify them as public.
        -> This allows us to set certain limits to the modifications, like setting age limit, string length limit ... and what not.
*/

class Student
{
    private:        // Although it is default setting for class in C++
        std::string s_name;
        int u_id;
        int s_class;
    
    public:
        Student(std::string s_name, int u_id, int s_class)
        {
            this->s_name = s_name;
            this->u_id = u_id;
            this->s_class = s_class;
        }

        std::string getStudentName()
        {
            return s_name;
        }

        int getUID()
        {
            return u_id;
        }

        int getClass()
        {
            return s_class;
        }

        void showInfo() {
            std::cout << "Name = " << s_name << "\n";
            std::cout << "UID = " << u_id << "\n";
            std::cout << "Class = " << s_class << "\n";

        }

};

int main () {

    Student vansh = Student("Vansh Saxena", 1234, 8);
    vansh.showInfo();

}