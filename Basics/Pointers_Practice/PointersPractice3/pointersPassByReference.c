/*
Problem: Write a program that that test your understanding of pass by reference
Date: 12 Dec 2022
Status: Completed
*/

#include <stdio.h>
#include <stdint.h>

// function prototype
void calculate_squareOfNumber(int *pNum);

int main()
{
    int SquareOf = 5;

    printf("The square of the number %d is: ", SquareOf);

    calculate_squareOfNumber(&SquareOf);
    printf("%d\n", SquareOf);
}

void calculate_squareOfNumber(int *pNum)
{
    *pNum = *pNum * (*pNum);
}