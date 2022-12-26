/*
Problem: Write a C program to get the absolute difference between n and 51.
         If n is greater than 51 return triple the absolute difference.
Date: 24 Dec 2022
Status: ongoing
-------------------------------------------------------------------------------------------
*/

#include <stdio.h>

const int abVal = 51;

int absolute_difference(int userip);

int main()
{
    int n, difference = 0;
    scanf("%d", &n);
    printf("%d\n", absolute_difference(n));
}

int absolute_difference(int userip)
{
    if (userip > abVal)
    {
        return (userip - abVal) * 3;
    }
    else
        return abVal - userip;
}