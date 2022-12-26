/*
Problem: Write a C program that takes n number of positive integers.
         Find the integer that appears the least number of times among the said integers.
         If there are multiple such integers, select the smallest one.
Date: 16 Dec 2022
Status: Ongoing
-------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int positiveNumber, greaterThan = 0, lessThan = 0, lessThanIndex, prevLessThan;

    printf("Enter the total number of poitive integers you would like to input:");
    scanf("%d", &positiveNumber);

    int positiveArr[positiveNumber];
    for (int i = 0; i < positiveNumber; i++)
    {
        scanf("%d", &positiveArr[i]);

        if (positiveArr[i] < 0)
        {
            printf("Negative integers are not allowed!\n");
            exit(0);
        }

        // lets say these are these are the said integers, 54, 64, 2, 55, 34, 64, 22, 2,
        if (positiveArr[i] > greaterThan)
        {
            greaterThan = positiveArr[i];
        }
        else
        {
            prevLessThan = positiveArr[i];

            if (positiveArr[i] < lessThan)
            {
                lessThan = positiveArr[i];
                lessThanIndex = i;
            }
        }
    }

    for (int i = 0; i < positiveNumber; i++)
    {
        for (int j = 1; j < positiveNumber; j++)
        {
            // less than
            if (positiveArr[j] < positiveArr[i])
            {
            }
        }
    }
}