// Name: Oyindamola Olaosun
// Student ID: C00313475
// Module: Advanced Programming Lab Work  (Q1 - Q19 corrected)

#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>   // abs

// ---------------------------------------------------------------------------
// Q1: Leap year.
// FIX: your function had no "return false" -> undefined behaviour for non-leap years.
// ---------------------------------------------------------------------------
bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

// ---------------------------------------------------------------------------
// Q2 (helper): reverse digits. 123 -> 321.
// FIX: you returned 0 instead of the reversed number, and printed the
//      original AFTER the loop had already reduced it to 0.
// ---------------------------------------------------------------------------
int Reversed(int testNumber) {
    int reversedNumber = 0;
    while (testNumber != 0) {
        int lastDigit = testNumber % 10;
        reversedNumber = reversedNumber * 10 + lastDigit;
        testNumber /= 10;
    }
    return reversedNumber;
}

// ---------------------------------------------------------------------------
// Q2: Palindrome.
// FIX: you compared testNumber (which is 0 after the loop) to reversedNumber.
//      Keep a copy of the original. Reuse the helper.
// ---------------------------------------------------------------------------
bool isAPalindrome(int testNumber) {
    if (testNumber < 0) return false;
    return testNumber == Reversed(testNumber);
}

// ---------------------------------------------------------------------------
// Q3: Prime.
// FIX: looping i <= 2147483647 overflows int (infinite loop) and is far too
//      slow. Only test divisors up to sqrt(n), using long long to avoid overflow.
// ---------------------------------------------------------------------------
bool isAPrimeNumber(int n) {
    if (n <= 1) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// Q4: Binary -> decimal (no shift operator). 110 -> 6.
// FIX: "lastDigit = lastDigit % 10" should be "binaryNumber % 10";
//      you returned 0 instead of decimal; the printf used binaryNumber after
//      it was already 0. Also avoided pow() (returns double) by multiplying.
// ---------------------------------------------------------------------------
int convertBinarytoDecimal(int binaryNumber) {
    int decimal = 0;
    int placeValue = 1;              // 2^0, 2^1, 2^2 ...
    while (binaryNumber != 0) {
        int lastDigit = binaryNumber % 10;
        decimal += lastDigit * placeValue;
        placeValue *= 2;
        binaryNumber /= 10;
    }
    return decimal;
}

// ---------------------------------------------------------------------------
// Q6: Right-angled triangle (was fine).
// ---------------------------------------------------------------------------
void drawRightAngledTriangle() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= i; j++) printf("A");
        printf("\n");
    }
}

// ---------------------------------------------------------------------------
// Q7: Diamond-like triangle, 2 for loops, 1 if/else (was fine).
// ---------------------------------------------------------------------------
void drawIsocelesTriangle() {
    for (int i = 1; i <= 7; i++) {
        int count;
        if (i <= 4) count = i;
        else        count = 8 - i;
        for (int j = 1; j <= count; j++) printf("A");
        printf("\n");
    }
}

// ---------------------------------------------------------------------------
// Q19 (EXTRA): Same pattern, 2 for loops, NO conditionals.
// Trick: count = 4 - |i - 4|   -> 1,2,3,4,3,2,1
// ---------------------------------------------------------------------------
void drawIsocelesTriangle2() {
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 4 - abs(i - 4); j++) printf("A");
        printf("\n");
    }
}

// ---------------------------------------------------------------------------
// Q8: Find element, print index or -1.
// FIX: you returned 0 on success (not the index) and printed nothing on failure.
// ---------------------------------------------------------------------------
int find(int size, int arr[], int toFind) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == toFind) {
            printf("The index of %d is %d\n", toFind, i);
            return i;
        }
    }
    printf("-1\n");
    return -1;
}

// ---------------------------------------------------------------------------
// Q9: Second largest (positive ints), -1 if none. (Your logic was correct.)
// ---------------------------------------------------------------------------
int find2ndLargest(int size, int arr[]) {
    int maximumNumber = -1;
    int secondLargest = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > maximumNumber) {
            secondLargest = maximumNumber;
            maximumNumber = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != maximumNumber) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

// ---------------------------------------------------------------------------
// Q10: Copy arr1 -> arr2 (was fine).
// ---------------------------------------------------------------------------
void copyArraytoArray(int size, int arr1[], int arr2[]) {
    for (int i = 0; i < size; i++) arr2[i] = arr1[i];
}

// ---------------------------------------------------------------------------
// Q11: Insert at index, shifting right.
// FIX: loop was "for (int i = count; count > insertIndex; count--)" - it
//      decremented count (the wrong variable) and never changed i.
// ---------------------------------------------------------------------------
bool insertElement(int& size, int& count, int arr[], int elementToInsert, int insertIndex) {
    if (count >= size || insertIndex < 0 || insertIndex > count) return false;

    for (int i = count; i > insertIndex; i--) {
        arr[i] = arr[i - 1];
    }
    arr[insertIndex] = elementToInsert;
    count++;
    return true;
}

// ---------------------------------------------------------------------------
// Q12: Delete at index, shifting left.
// FIX: "count >= size" wrongly rejected deletes from a full array, and
//      "deleteIndex > size" should be ">= count" (valid indices are 0..count-1).
// ---------------------------------------------------------------------------
bool deleteElement(int& size, int& count, int arr[], int deleteIndex) {
    if (deleteIndex < 0 || deleteIndex >= count) return false;

    for (int i = deleteIndex; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
    return true;
}

// ---------------------------------------------------------------------------
// Q13: Frequency of a value (was fine).
// ---------------------------------------------------------------------------
int frequencyCount(int size, int arr[], int value) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) count++;
    }
    return count;
}

// ---------------------------------------------------------------------------
// Q14: Count duplicates (was fine).
// Interpretation: every element that has already appeared earlier counts once.
// {1,2,2,3,3,3} -> 3.   (If the exam means "distinct values that repeat" -> 2.
//  Read the question carefully / ask.)
// ---------------------------------------------------------------------------
int countDuplicates(int size, int arr[]) {
    int duplicateCount = 0;
    for (int i = 0; i < size; i++) {
        bool alreadySeen = false;
        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) { alreadySeen = true; break; }
        }
        if (alreadySeen) duplicateCount++;
    }
    return duplicateCount;
}

// ---------------------------------------------------------------------------
// Q15: Reverse in place (was fine). Added spaces/newline to the printout.
// ---------------------------------------------------------------------------
void reverse(int size, int arr[]) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

// ---------------------------------------------------------------------------
// Q16: Left rotate by one (was fine).
// ---------------------------------------------------------------------------
int rotateLeft(int size, int arr[]) {
    if (size <= 1) return 1;
    int temp = arr[0];
    for (int i = 0; i < size - 1; i++) arr[i] = arr[i + 1];
    arr[size - 1] = temp;
    return 0;
}

int rotateRight(int size, int arr[])
{
    if (size <= 1)
    {
        return 1;
    }

    int temp = arr[size - 1];
    for (int i = size; i > 0; i--) arr[i] = arr[i - 1];
    arr[0] = temp;
}

// ---------------------------------------------------------------------------
// Q17: Two movies sum to flight length (was correct, O(n^2)).
// ---------------------------------------------------------------------------
bool twoMovies(int flightLength, int movieLengths[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (movieLengths[i] + movieLengths[j] == flightLength) return true;
        }
    }
    return false;
}

// ---------------------------------------------------------------------------
// Q18: Word counter (was correct).
// ---------------------------------------------------------------------------
bool isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int wordCounter(int size, char characters[]) {
    int wordCount = 0;
    bool inWord = false;
    for (int i = 0; i < size; i++) {
        if (isLetter(characters[i])) {
            if (!inWord) { wordCount++; inWord = true; }
        }
        else {
            inWord = false;
        }
    }
    return wordCount;
}

// ---------------------------------------------------------------------------
// Q19: PrintArray (only function allowed printf in that lab).
// FIX: inner loop condition was "i < 6" (should be j < 6) -> infinite loop.
//      Also added spaces and a newline per row.
// ---------------------------------------------------------------------------
void PrintArray(int array[4][6]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
}

// ---------------------------------------------------------------------------
// Tests: a tiny helper so results read PASS / FAIL.
// ---------------------------------------------------------------------------
void check(const char* name, bool ok) {
    printf("%-34s %s\n", name, ok ? "PASS" : "FAIL");
}

int main() {
    printf("--- Q1 Leap year ---\n");
    check("1700 not leap", !isLeapYear(1700));
    check("1600 leap", isLeapYear(1600));
    check("2016 leap", isLeapYear(2016));

    printf("--- Q2 Reverse / Palindrome ---\n");
    check("Reversed(123)==321", Reversed(123) == 321);
    check("Reversed(1)==1", Reversed(1) == 1);
    check("Reversed(1234)!=321", Reversed(1234) != 321);
    check("1 palindrome", isAPalindrome(1));
    check("121 palindrome", isAPalindrome(121));
    check("1213 not palindrome", !isAPalindrome(1213));

    printf("--- Q3 Prime ---\n");
    check("3 prime", isAPrimeNumber(3));
    check("2147483647 prime", isAPrimeNumber(2147483647));
    check("4 not prime", !isAPrimeNumber(4));
    check("1 not prime", !isAPrimeNumber(1));

    printf("--- Q4 Binary -> decimal ---\n");
    check("110 -> 6", convertBinarytoDecimal(110) == 6);
    check("111 -> 7", convertBinarytoDecimal(111) == 7);
    check("0 -> 0", convertBinarytoDecimal(0) == 0);

    printf("--- Q6 / Q7 / Q19(extra) Triangles ---\n");
    drawRightAngledTriangle();
    printf("\n");
    drawIsocelesTriangle();
    printf("\n");
    drawIsocelesTriangle2();
    printf("\n");

    printf("--- Q8 Find ---\n");
    int a[] = { 5, 3, 9, 3, 7 };
    check("find 9 -> 2", find(5, a, 9) == 2);
    check("find 4 -> -1", find(5, a, 4) == -1);

    printf("--- Q9 Second largest ---\n");
    int b[] = { 4, 9, 2, 9, 7 };
    int c[] = { 5, 5, 5 };
    check("2nd largest of b == 7", find2ndLargest(5, b) == 7);
    check("2nd largest of c == -1", find2ndLargest(3, c) == -1);

    printf("--- Q10 Copy ---\n");
    int d[5];
    copyArraytoArray(5, a, d);
    check("copy matches", d[0] == 5 && d[2] == 9 && d[4] == 7);

    printf("--- Q11 Insert ---\n");
    int size = 6, count = 4;
    int e[6] = { 1, 2, 4, 5 };
    check("insert 3 at 2", insertElement(size, count, e, 3, 2));
    check("array now 1 2 3 4 5", e[0] == 1 && e[2] == 3 && e[3] == 4 && e[4] == 5 && count == 5);
    check("insert at bad index fails", !insertElement(size, count, e, 9, 10));

    printf("--- Q12 Delete ---\n");
    check("delete index 2", deleteElement(size, count, e, 2));
    check("array now 1 2 4 5", e[2] == 4 && e[3] == 5 && count == 4);
    check("delete bad index fails", !deleteElement(size, count, e, 4));

    printf("--- Q13 Frequency ---\n");
    check("3 appears twice", frequencyCount(5, a, 3) == 2);

    printf("--- Q14 Duplicates ---\n");
    int f[] = { 1, 2, 2, 3, 3, 3 };
    check("duplicates == 3", countDuplicates(6, f) == 3);

    printf("--- Q15 Reverse ---\n");
    int g[] = { 1, 2, 3, 4, 5 };
    reverse(5, g);
    check("reversed", g[0] == 5 && g[4] == 1);

    printf("--- Q16 Rotate left ---\n");
    int h[] = { 1, 2, 3, 4 };
    rotateLeft(4, h);
    check("rotated 2 3 4 1", h[0] == 2 && h[3] == 1);

    printf("--- Q17 Two movies ---\n");
    int movies[] = { 90, 120, 100, 60 };
    check("flight 160 -> true (100+60)", twoMovies(160, movies, 4));
    check("flight 500 -> false", !twoMovies(500, movies, 4));

    printf("--- Q18 Word counter ---\n");
    char text[] = "Hello  world, this is C++";
    check("words == 5", wordCounter((int)sizeof(text) - 1, text) == 5);

    printf("--- Q19 PrintArray ---\n");
    int array[4][6] = { {0,0,3,1,3,4},
                        {0,0,2,3,4,3},
                        {0,0,1,3,3,2},
                        {0,0,1,1,1,1} };
    PrintArray(array);

    return 0;
}