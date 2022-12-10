/*
Problem: Write a program to check given number is perfect number or not
Date: 05 Dec 2022
Status: Completed
*/

#include <stdio.h>

int main()
{
    unsigned int ipNum;
    unsigned int sum = 0;

    scanf("%d", &ipNum);

    for (int i = 1; i < ipNum; i++)
    {
        if (ipNum % i == 0)
        {
            sum += i;
        }
    }

    if (sum == ipNum)
    {
        printf("%d is a perfect number\n", ipNum);
    }
    else
        printf("%d is not a perfect number\n", ipNum);
}