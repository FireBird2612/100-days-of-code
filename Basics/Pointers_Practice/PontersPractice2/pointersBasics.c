/*
Problem: Write a program that creates an integer variable with a
         with a hard coded value. Assign that variable's address
         to a pointer variable.
         Display
Date:
Status:
*/

#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t hardCodedVariable = 533;
    int32_t *pHardCodedVariable = &hardCodedVariable;

    printf("The address of the pointer is:  %p\n", &pHardCodedVariable);
    printf("The address of the variable is: %p\n", pHardCodedVariable);
    printf("The address of the variable is: %p\n", &hardCodedVariable);
    printf("The value of the variable is: %d\n", *pHardCodedVariable);
}