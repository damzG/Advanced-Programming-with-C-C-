//
// Created by User on 10/8/2026.
//

#include <iostream>


double getTotal1(double* arr, int size);

int main()
{

    /*
     *User Input and output
     * std::string name
        std::cout << "Request"
        std::cin >> name

        To get full name with spaces
        std::getline(std::cin >> std::ws, name);
        std::ws - to remove unnecessary whitespaces after input

        String methods - length(), empty(), clear(), append(), at(),
        insert(), find(), erase()
     */
        //Pass an array to a afunction

    double prices[] = {45.89, 12.02, 23, 2.33};
    int size = sizeof(prices) / sizeof(prices[0]);
    double total = getTotal1(prices, size);

    std::cout << "$" << total;
    return 0;
}

double getTotal1(double prices[], int size)
{
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += prices[i];
    }

    return total;
}
