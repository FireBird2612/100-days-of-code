/*
Problem: Write a c program to check given number is palindrome number or not.
Date: 08 Dec 2022
Status:
--------------------------------------------------------------------------------------------
A palindrome is a number which remain same even when its digits are reversed.
ex, 121, 0, 1, etc...
*/

#include <stdio.h>

int main()
{
    int ipPalindrome;
    scanf("%d", &ipPalindrome);

    int dup = ipPalindrome;
    int sum = 0;

    while (dup != 0)
    {
        sum = sum * 10 + (dup % 10);
        dup = dup / 10;
    }

    (sum == ipPalindrome) ? printf("%d is a palindrome number", ipPalindrome) : printf("%d is not a palindrome number", ipPalindrome);
}