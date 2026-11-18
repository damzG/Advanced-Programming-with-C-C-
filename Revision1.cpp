#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>

using namespace std;

//Pointer function
//return dynamically allocated memory on the heap using new
int *getPtrToFive()
{
    int *x = new int;
    *x = 5;

    //Other way
    /*
     * int *x = new int(5);
     * return ptr;
     */
    return x;
}

int main()
{
    int *p = getPtrToFive();
    if (p != nullptr)
    {
        std::cout << *p <<std::endl; //Output 5

        //Free the memory to avoid a memory leak
        delete p;
    }
    return 0;
}