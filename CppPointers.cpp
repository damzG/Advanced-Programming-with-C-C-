//
// Created by User on 10/8/2026.
//

#include <iostream>

int main()
{
    std::string name = "Caffeine";
    int age = 23;

    // Pointer

    std::string *p_name = &name;
    int *pAge = &age;
    std::string freePizzas[3] = {"Pizza1", "Pizza1", "Pizza3"};

    std::cout << *p_name;
    std::cout << *pAge;
    std::cout << freePizzas; //shows memory address
}