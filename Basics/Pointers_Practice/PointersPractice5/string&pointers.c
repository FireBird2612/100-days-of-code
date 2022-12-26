/*
Problem: Effect of adding an integer value to a pointer.
Date: 08 Dec 2022
Status:
---------------------------------------------------------------------------------------------

*/

#include <stdio.h>
#include <string.h>

int main()
{
    // char array to store a string
    char multiple[] = "a string";
    // pointer variable of char data type
    char *p = multiple;

    for (int i = 0; i < strnlen(multiple, sizeof(multiple)); ++i)
    {
        printf("multiple[%d] = %c *(p+%d) = %c &multiple[%d] = %p p+%d = %p\n", i, multiple[i], i, *(p + i), i, &multiple[i], i, p + i);
    }
}