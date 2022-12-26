/*
Problem: Write a C program to check given number is Armstrong number or not
Date: 25 Dec 2022
Status: Completed
---------------------------------------------------------------------------

A number is Armstrong number when a number is equal to the sum of cube of its digits.
For example, 153 == (1^3 + 5^3 + 3^3);
To get each digit from the number you need to divide that number with 10.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int userip, division, modulus, counter = 0, sum = 0, power, x = 1;
    scanf("%d", &userip);
    division = userip;

    if (userip < 0)
    {
        printf("Only positive numbers folks!\n");
        exit(0);
    }

    // This loop is necessary to get the total digits in a number.
    while (division != 0)
    {
        modulus = division % 10;
        counter++;
        division = division / 10;
    }

    // on the basis of counter this loop is based.
    division = userip;
    power = counter;
    for (int i = 0; i < counter; i++)
    {
        modulus = division % 10;
        while (power != 0)
        {
            x *= modulus;
            power--;
        }
        sum += x;
        x = 1;
        power = counter;
        division = division / 10;
    }

    if (sum == userip)
    {
        printf("%d is a Armstrong Number!\n", userip);
    }
    else
        printf("%d is not a Armstrong Number!", userip);
}