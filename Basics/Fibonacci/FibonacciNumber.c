/*
Problem: Write a c program to print Fibonacci series of given range.
Date: 11 Dec 2022
Status: completed
----------------------------------------------------------------------
Read about Fibonacci Series: https://www.cuemath.com/numbers/fibonacci-series/
*/

#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t userFibonacciNum;
    int32_t F0 = 0, F1 = 1;

    printf("Enter the number range:");
    scanf("%d", &userFibonacciNum);

    printf("The Fibonacci Series is:\n");
    printf("%d\n%d\n", F0, F1);

    for (int i = 2; i < userFibonacciNum; i++)
    {
        int32_t fibcalculateNum = F0 + F1;
        F0 = F1;
        F1 = fibcalculateNum;
        printf("%d\n", F1);
    }
}
