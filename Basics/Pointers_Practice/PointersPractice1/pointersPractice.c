/*
Problem: Write a program by using dynamic memory allocation
Date: 13 Dec 2022
Status: Completed
------------------------------------------------------------------------------------------
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// function prototype
void calculate_squareOfNumber(int32_t *pNumber);

int main()
{

	int32_t *squareOf = (int32_t *)malloc(sizeof(int32_t));
	printf("Enter a number:");
	scanf("%d", squareOf);
	printf("The square of the number %d is: ", *squareOf);

	calculate_squareOfNumber(squareOf);
	printf("%d\n", *squareOf);
	free(squareOf);
}

void calculate_squareOfNumber(int32_t *pNumber)
{
	*pNumber = *pNumber * (*pNumber);
}