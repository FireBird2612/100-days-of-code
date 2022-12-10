/*
Problem: Perform read and write operation with pointer
Date: 06 Dec 2022
Status: Complete
*/

#include <stdio.h>

int main()
{
    int var1 = 999999999;
    printf("Value of var1 is: %d\n", var1);
    printf("Address of var1 is: %p\n", &var1);

    // STEP 2
    char *pAddressOf = &var1;
    char value = *pAddressOf;
    printf("Read value is %d\n", value);

    // STEP 3
    *pAddressOf = 65;
    printf("value of var1 is: %d\n", *pAddressOf);
}