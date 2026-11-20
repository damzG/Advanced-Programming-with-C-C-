#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>

using namespace std;

//Pointer function
//return dynamically allocated memory on the heap using new
#include <iostream>

int* get_five() {
    // Allocate memory on the heap and initialize it to 5
    int* ptr = new int(5);
    return ptr;
}

//Swap the values of two integers using pointers
void swap_ints(int *a, int *b)
{
    int* spare = new int;
    *spare = *a;
    *a = *b;
    *b = *spare;
}

int find_maximum(int *arr, int size) {

    if(size <= 0){
        return 0;
    }

    int max = *arr;

    for(int i = 0; i < size; i++){
        if(*(arr + i) > max){
            max = *(arr + i);
        }
    }


    return max;
}


void reverse_array(int *arr, int size){
    // Loop through the first half of the array
    for(int i = 0; i < size / 2; i++){
        //Store the left element in a temp variable
        int temp = *(arr + i);


        //Move the corresponding right element to the left position
        *(arr + i) = *(arr + size - 1 - i);

        //Move the original left element (stored in temp) to the right
        *(arr + size - 1 - i) = temp;
    }

}

int strlen_ptr(char *str){

    int size = 0;

    for(char *s = str; *s != '\0'; s++){
        size ++;
    }


    return size;
}


int count_vowels(char *str){

    int vowel_size = 0;

    for(char *s = str; *s != '\0'; s++){
        char ch = std::tolower(*s);

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            vowel_size ++;
        }
    }


    return vowel_size;
}



void copy_string(char *dest, char *src){

    int index = 0;

    for(char *s = src; *s != '\0'; s++){
        char ch = *s;

        *(dest + index) = ch;

        index ++;
    }

    //Add null terminator
    *(dest + index) = '\0';
}

void concat_strings(char *dest, char *src)
{
    int dest_index = 0;

    // 1. Find the end of the destination string (locate its '\0' character)
    while (*(dest + dest_index) != '\0') {
        dest_index++;
    }

    // 2. Copy characters from src into dest starting from the end of dest
    int src_index = 0;
    while (*(src + src_index) != '\0') {
        *(dest + dest_index) = *(src + src_index);
        dest_index++;
        src_index++;
    }

    // 3. Null-terminate the final combined string
    *(dest + dest_index) = '\0';
}

int compare_strings(char *str1, char *str2) {
    int i = 0;

    // Traverse both strings until we hit a mismatch or a null terminator
    while (*(str1 + i) != '\0' && *(str2 + i) != '\0') {
        if (*(str1 + i) != *(str2 + i)) {
            // Return the ASCII difference of the first non-matching characters
            return *(str1 + i) - *(str2 + i);
        }
        i++;
    }

    // If one string is shorter (or both ended together), compare their termination points
    return *(str1 + i) - *(str2 + i);
}


int run() {
    int* p = get_five();
    if (p != nullptr) {
        std::cout << *p << std::endl; // Output: 5

        // Remember to free the memory to avoid a memory leak
        delete p;
    }

    //Storing values input by the user
    int numItems;
    cout << "how many items? ";
    cin >> numItems;
    int *arr = new int[numItems];

    //Read in each integer into the array
    for (int i = 0; i < numItems; ++i)
    {
        cout << "Enter a number " << i << ": ";
        cin >> arr[i];
    }

    //Write out the array to the screen
    for (int i = 0; i < numItems; ++i)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;

    int x = 5;
    int y = 10;

    swap_ints(&x, &y);

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    std::cout << "Reversed array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;

    char str[] = "OpenAI";
    int length = strlen_ptr(str);

    std::cout <<  "Length of the string \"Hello\" is:  " << length << std::endl;

    int vowels = count_vowels(str);

    std::cout << "Vowels: " << vowels << std::endl; // Output: 3 ('O', 'e', 'A')

    char src[] = "Hello";
    char dest[10];
    copy_string(dest, src);

    std::cout << "Destination String Updated: " << dest << std::endl;





        char res[20] = "Hello, ";
        char soc[] = "World!";

        concat_strings(res, soc);

        std::cout << "Concatenated: " << dest << std::endl;

        std::cout << "Done with revision" << endl;

    return 0;

}