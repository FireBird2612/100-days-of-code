/*
Problem: Write a c program to check given number is strong number or not.
Date: 07 Dec 2022
Status: Completed
---------------------------------------------------------------------------

A number is called strong number if sum of the factorial of its digit is equal to number itself.
For example,
145 is a strong number,
!1 + !4 + !5 = 145
*/

#include <stdio.h>

int main()
{
    // user input to check for strong number
    int ipStrongNum;
    scanf("%d", &ipStrongNum);

    // duplicate of ipStrongNum
    int dup = ipStrongNum;
    // responsible for keep the track of the sum of factorial
    int sum = 0;
    // Intialize facto to 1 to get the factorial of the digit
    int facto = 1;

    while (dup != 0)
    {
        // remainder will be the single digit from ipStrongNum to calculate factorial
        int remainder = (dup % 10);

        // Inner for loop to calculate factorial.
        for (int c = 1; c <= remainder; c++)
        {
            facto = facto * c;
        }
        // Add the facto to the sum
        sum += facto;
        // Remember to again initialize the facto to 1
        facto = 1;
        // This will give you the new quotient to determine the status of while loop
        dup /= 10;
    }

    (ipStrongNum == sum) ? (printf("%d is strong number", ipStrongNum)) : (printf("%d is not a strong number\n", ipStrongNum));
}