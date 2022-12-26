/*
Date: 2 December 2022
Time: 3:57pm
Purpose: Learning pointer arithemtic on Udemy.
Course: C programming
Section: 08. Pointer Arithmetic
*/

#include <stdio.h>

// function prototype
int arraySum(int *array, const int n);

int main()
{
    int values[10] = {3, -34, -9, 3, 6, -5, 7, 9, 1, -5};

    printf("The sum is %i\n", arraySum(values, 10));
}

int arraySum(int *array, const int n)
{ // takes two arguments, an array of type int and an constant integer n
    int sum = 0;
    int const *arrayEnd = array + n;

    while (array < arrayEnd)
    {
        sum += *array;
        array++;
    }

    return sum;
}