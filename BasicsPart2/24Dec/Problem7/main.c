/*
Problem: Write a C program to compute the sum of the two given integer values.
         If the two values are the same, then return triple their sum.
Date: 24 Dec 2022
Status: Completed
-------------------------------------------------------------------------------------------
*/

#include <stdio.h>

int main()
{
    int A, B, Sum;
    scanf("%d   %d", &A, &B);
    if (A == B)
    {
        Sum = (A + B) * 3;
        printf("Sum =  %d\n", Sum);
    }
    else
        printf("Sum = %d\n", Sum = A + B);
}