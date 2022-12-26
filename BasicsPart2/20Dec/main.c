/*
Problem: 4. Write a C program that accepts two sequences ((a1, a2, .. an), (b1, b2, .. bn))
         of integers as input.
         Find all integers that appear in both sequences, one by one, in ascending order.

         Constraints:
         1≤N1≤100, N1 -> number of integers in first sequence.
         1≤N2≤100, N2 -> number of integers in second sequence.
         1 ≤ ai≤ 100 ( 1 ≤ i ≤ N1 )
         1 ≤ bj≤ 100 ( 1 ≤ j ≤ N2 )

         Sample Date:
         ( 1 2 3 1 2 3 4) -> 1 2 3
         ( 1 2 3 1 2 3) -> 1 2 3
         (1 2 3 4 5 6) ->
Date: 20 Dec 2022
Status: Ongoing
----------------------------------------------------------------------
*/

#include <stdio.h>

int main()
{
    int LimitSq1, LimitSq2, AscendingNum[20], counter = 0, temp = 0;
    printf("Total Number of positive integers you would like to store (Squence 1):");
    scanf("%d", &LimitSq1);

    printf("Enter the number: ");
    int InputNumSq1[LimitSq1];
    for (int i = 0; i < LimitSq1; i++)
    {
        scanf("%d", &InputNumSq1[i]);
    }

    printf("Total number of positive integers you would like to store (Sequence 2):");
    scanf("%d", &LimitSq2);

    printf("Enter the number: ");
    int InputNumSq2[LimitSq2];
    for (int j = 0; j < LimitSq2; j++)
    {
        scanf("%d", &InputNumSq2[j]);
    }

    // store the common numbers in AscendingNum
    for (int i = 0; i < LimitSq1; i++)
    {
        for (int j = 0; j < LimitSq2; j++)
        {
            if (InputNumSq1[i] == InputNumSq2[j])
            {
                AscendingNum[counter] = InputNumSq1[i];
                counter++;
            }
        }
    }

    // Arrange the numbers in ascending order
    for (int i = 0; i < counter; i++)
    {
        for (int j = i + 1; j < counter; j++)
            if (AscendingNum[i] > AscendingNum[j])
            {
                temp = AscendingNum[i];
                AscendingNum[i] = AscendingNum[j];
                AscendingNum[j] = AscendingNum[i];
            }
    }

    // Print AscendingNum
    for (int i = 0; i < counter; i++)
    {
        printf("%d ", AscendingNum[i]);
    }
}