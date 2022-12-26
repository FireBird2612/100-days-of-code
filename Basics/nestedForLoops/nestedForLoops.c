/*
HackerRank/conditionalLoops/PatternPrinting

Date:5 Dec 2022
Status: Incomplete
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int xDirection = n + (n - 1);
    int v = n;

    for (int i = 0; i < xDirection; i++)
    {
        for (int j = 0; j < xDirection; j++)
        {
            int min;
            min = i < j ? i : j;
            min = (2 * n) - 2 - i < min ? (2 * n) - 2 - j : min;
            min = (2 * n) - 2 - j < min ? (2 * n) - 2 - j : min;

            printf("%d ", n - min);
        }
        printf("\n");
    }
}