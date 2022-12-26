/*
Problem: Write a c program to generate multiplication table.
Date: 12 Dec 2022
Status: ongoing
*/

#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t ipTable, maxMultiplication = 10;
    printf("Enter the multiplication table you would like to print:");
    scanf("%d", &ipTable);

    printf("Printing the Mulitplication Table of %d...\n", ipTable);

    for (uint32_t count = 1; count <= maxMultiplication; count++)
    {
        uint32_t result = ipTable * count;
        printf("%d x %d = %d\n", ipTable, count, result);
    }

    return 0;
}