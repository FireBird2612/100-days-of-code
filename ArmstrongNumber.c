/*
Problem: Write a C program to check given number is Armstrong number or not
Date: 06 Dec 2022
Status: Completed
---------------------------------------------------------------------------

A number is Armstrong number when a number is equal to the sum of cube of its digits.
For example, 153 == (1^3 + 5^3 + 3^3);
To get each digit from the number you need to divide that number with 10.
*/

#include <stdio.h>

int main()
{
    // Take a number from user and store the value in Armstrong
    int Armstrong;
    scanf("%d", &Armstrong);

    // Create a duplicate of Armstrong
    int pQuotient = Armstrong;
    // Initialise the sum to 0
    int sum = 0;

    // The loop will keep executing until the quotient p is equal to zero 
    while (pQuotient != 0)
    {
        // This will give us the cube of the remainder which will get added to the sum
        sum = sum + (pQuotient % 10) * (pQuotient % 10) * (pQuotient % 10);
        // This will be give the new pQuotient
        pQuotient = pQuotient / 10;
    }

    // Use of Ternary operator, if (condition is true) ? (then execute this) : (or execute this)
    (Armstrong == sum) ? (printf("%d is Armstrong Number!\n", Armstrong)) : (printf("%d is not an Armstrong Number!\n", Armstrong));          
}
