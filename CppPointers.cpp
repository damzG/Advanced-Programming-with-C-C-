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

    //Null Pointers

    int *pointer = nullptr;
    int x = 123;

    pointer = &x;

    if (pointer != nullptr)
    {
        printf("Address was asssigned");
    }
    else
    {
        printf("Address Was not assigned");
    }

    //Dynamic Memory
    /*
     * Memory that is allocated after the program is already compiled & running
     * Use the 'new' operator to allocate memory in the heap rather than the stack
     */

    int *pNum = NULL;
    pNum =  new int; //dynamic memory
    *pNum = 5;

    printf("Address: %p\n", pNum);
    printf("Value: %d\n", *pNum);

    delete pNum; //to prevent memory leakage

    char *pGrades = NULL;

    int size = scanf("How many grades to enter in? ");
    pGrades = new char[size];

    for (int i = 0; i < size; i++)
    {
        pGrades[i] = 'A';
    }
}