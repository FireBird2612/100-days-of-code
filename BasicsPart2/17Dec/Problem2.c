/*
Problem: 2. Write a C program that takes a string and two integers (n1, n2).
            Now reverse the sequence of characters of the string between n1 and n2.
            Sample Date:
            ("abcdxyabcd", 5, 6) -> "abcdyxabcd"
            ("Exercises", 1, 3) -> "exercises"
Date: 17 Dec 2022
Status: Completed
-------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char UserString[20], temp;
    short int ReverseNum1, ReverseNum2, StringLength;

    printf("Enter a string without any space with maximum limit of 20 characters:");
    scanf("%s", UserString);

    printf("Enter any 2 positive integer to exchange the characters:");
    scanf("%hu %hu", &ReverseNum1, &ReverseNum2);

    if (ReverseNum1 < 0 | ReverseNum2 < 0)
    {
        printf("Only Positive integers are valid!\n");
        exit(0);
    }

    printf("-------------------------------------");
    printf("\nOriginal String: \"%s\"\n", UserString);

    StringLength = strlen(UserString);

    temp = UserString[ReverseNum1 - 1];
    UserString[ReverseNum1 - 1] = UserString[ReverseNum2 - 1];
    UserString[ReverseNum2 - 1] = temp;
    printf("Modified string = \"%s\"\n", UserString);

    return 0;
}