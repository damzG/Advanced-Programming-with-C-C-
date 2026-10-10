//
// Created by User on 10/10/2026.
//

#include <iostream>
#include <ostream>
#include <stdio.h>

int sum(int *ptr, int numValues)
{
    int sum = 0;
    for (int i = 0; i < numValues; i++)
    {
        sum = sum + *(ptr + i); //Using pointer arithmetic to access each element
    }
    return sum;
}

int main()
{
    int numbers[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    //Pointer pointing to the first number of the array
    int *ptr = numbers;

    printf("Walking the array using pointers:\n");
    for (int i = 0; i < size; i++)
    {
        //Deference the pointer and then increment it to point to the next element
        printf("Element %d: %d\n", i, *ptr);
        ptr++;
    }

    printf("Accessing array elements using pointer arithmetic:\n");
    for (int i = 0; i < size; i++)
    {
        //*(arr + 1) accesses the value at memory address (arr + i)
        printf("array[%d] = %d\n", i, *(numbers + i));
    }

    std::cout << sum(numbers, size) << std::endl;

    printf("%p", ptr);

    return 0;
}