#include <iostream>

/*
    When we do 2 + 3
        -> The compiler knows that when we have ooperands like integers, so '+' means to add those numbers
        -> But, what happens if we give some custom data type instead of integers
            -> Since compiler does not know about it, we will get an error
*/

class Entity
{
    private:
        int id;
        std::string name;
    
    public:
        Entity(int id, std::string name)
        {
            this->id = id;
            this->name = name;
        }

        friend int operator + (Entity &e1, Entity &e2);
        friend void operator << (std::ostream &o, Entity &e1);
        friend void operator += (Entity &e1, Entity &e2);
};

int operator + (Entity &e1, Entity &e2)
{
    return e1.id + e2.id;
}

void operator << (std::ostream &o, Entity &e1)
{
    o << e1.id << " " << e1.name << "\n";
}

void operator += (Entity &e1, Entity &e2)
{
    e1.id = e1.id + e2.id;
}

int main()
{
    Entity e1(5, "e1");
    Entity e2(3, "e2");

    int ans = e1 + e2;

    std::cout << e1;

    e1+=e2;
    std::cout << e1;
}