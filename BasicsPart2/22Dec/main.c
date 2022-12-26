/*
Problem: 6. Write a C program that accept a sequence of positive integers
         from the user and find the length of the longest continuous subsequence
         from the said sequence.

         Sample Data:
         1. Length of the sequence: 5
         Sequence: 5 2 3 4 1
         Length of longest ascending contiguous subsequence: 5 [2 3 4]
         2. Length of the sequence: 6
         Sequence: 10 20 30 40 50 60
         3. Length of longest ascending contiguous subsequence: 6 [10 20 30 40 50 60]
         Length of the sequence: 3
         Sequence: 5 1 3
         Length of longest ascending contiguous subsequence: 2 [1 3]

Date: 22 Dec 2022
Status: Ongoing
----------------------------------------------------------------------
*/

#include <stdio.h>

int main(void)
{
    int SeqLength, AscendingNum[10], counter = 0, temp = 0, counter2 = 0;
    printf("Enter the maximum length of the input sequence:");
    scanf("%d", &SeqLength);

    SeqLength -= 1;
    printf("Enter your sequence: ");
    int SeqArr[SeqLength];
    for (int i = 0; i <= SeqLength; i++)
    {
        scanf("%d", &SeqArr[i]);
    }

    for (int i = 0; i <= SeqLength; i++)
    {
        if ((SeqArr[i] < SeqArr[i + 1]) | (i == SeqLength - 1) | SeqArr[i - 1] < SeqArr[i])
        {
            AscendingNum[counter] = SeqArr[i];
            counter++;
        }
    }

    for (int i = 0; i < counter; i++)
    {
        if (AscendingNum[i] > temp)
        {
            temp = AscendingNum[i];
            counter2++;
        }
    }
    if (counter2 - counter)

        printf("\n\n%d[", counter2);
    for (int i = 0; i < counter2; i++)
    {
        printf("%d ", AscendingNum[i]);
    }
    printf("]\n\n");
}