/*
Problem: Write a program that counts characters in a string using pointer arithmetic
Date: 12 Dec 2022
Status: Completed
------------------------------------------------------------------------------------------
*/

#include <stdio.h>

// Function Prototype
int calculateStringLength(const char *pString);

int main()
{
	char myName[] = "";

	printf("\n\nEnter your first Name: ");
	scanf("%s", myName);

	char const *pointerMyName = myName;

	printf("The length of the string is: %d\n", calculateStringLength(pointerMyName));
}

int calculateStringLength(const char *pString)
{

	const char *lastAddress = pString;
	while (*lastAddress)
	{
		++lastAddress;
	}

	return lastAddress - pString;
}
