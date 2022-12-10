/*
Problem: Write a c program to check given number is prime number or not.
Date: 07 Dec 2022
Status: Complete
---------------------------------------------------------------------------------
Prime Number: A number that is greater than one is divisible only by itself and 1
*/

#include <stdio.h>

int main()
{
    // User input to check the number for prime
    int checkPrime;
    scanf("%d", &checkPrime);

    // Initialise result to zero since any number that has 0 remainder will be added and stored in result for later comparision
    int result = 0;

    // For loop that checks for each number to be a prime, starting from 1 to checkPrime
    for (int i = 1; i <= checkPrime; i++)
    {
        // The remainder will be stored in a temporary variable n
        int n = checkPrime % i;

        // Only those number with 0 remainder has the right to enter this statement :)
        if (n == 0)
        {
            // The number with 0 remainder i will get added and stored in result.
            result += i;
        }
    }
    // Ternary operator which checks for the result variable.
    (result == (1 + checkPrime)) ? printf("%d is Prime Number\n", checkPrime) : printf("%d is not a Prime Number\n", checkPrime);
}