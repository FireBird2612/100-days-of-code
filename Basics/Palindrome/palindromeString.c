/*
Problem: Write a c program to check given string is palindrome string or not.
Date: 10 Dec 2022
Status:
--------------------------------------------------------------------------------------------

A string is called palindrome if it symmetric.
In other word a string is called palindrome if string remains same if its characters are reversed.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[10], rev[10];
    int i, j;
    scanf("%s", str);

    for (i = strlen(str) - 1, j = 0; i >= 0; i--, j++)
    {
        rev[j] = str[i];
    }
    rev[j] = '\0';

    if (strcmp(rev, str))
    {
        printf("The string is not a palindrome\n");
    }
    else
        printf("The string is palindrome!\n");
    return 0;
}