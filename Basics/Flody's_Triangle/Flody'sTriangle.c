/*
Problem: Write a c program for Floyd’s Triangle.
Date: 11 Dec 2022
Status: Completed
-----------------------------------------------------------------------------
Read about Floyd's Triangle: https://en.wikipedia.org/wiki/Floyd%27s_triangle
*/

#include <stdio.h>
#include <stdint.h>

int main()
{
    // input range of Floyd's triangle to print from user
    int32_t userInputRange, Count = 1, innerCount = 0, outerCount = 1;

    printf("Enter the range of the Floyd's Triangle:");
    scanf("%d", &userInputRange);

    while (Count <= userInputRange)
    {
        while (innerCount < outerCount && Count <= userInputRange)
        {
            if (Count < 10)
            {
                printf("%d   ", Count);
                Count++, innerCount++;
            }

            else if (Count > 10 && Count < 100)
            {
                printf("%d  ", Count);
                Count++, innerCount++;
            }

            else
            {
                printf("%d ", Count);
                Count++, innerCount++;
            }
        }
        printf("\n");
        // increment the outerCount for comparision with innerCount
        outerCount++;
        //  reset the inner counter
        innerCount = 0;
    }
}