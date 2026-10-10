//
// Created by User on 10/10/2026.
//

#include <iostream>

class Human
{
    public:
        std::string name;
        std::string occupation;
        int age;

    Human(std::string name, std::string occupation, int age)
    {
        this->name = name;
        this->occupation = occupation;
        this->age = age;
    }

    void eat()
    {
        printf("Human eat");
    }

    int getAge()
    {
        return age;
    }

    void setAge(int age)
    {
        this->age = age;
    }

};
int main()
{
    Human human1("Homer", "Plumber", 18);
    human1.eat();

    return 0;
}