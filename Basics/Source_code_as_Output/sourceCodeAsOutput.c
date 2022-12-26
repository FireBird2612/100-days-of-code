/*
Problem: Write a c program which produces its own source code as its output.
Date: 14 Dec 2022
Status: Completed
------------------------------------------------------------------------------
*/

#include <stdio.h>

int main()
{
    // Declare a pointer *fp of type file.
    FILE *filePointer = NULL;
    char c;

    filePointer = fopen(__FILE__, "r");

    do
    {
        // read character from the file
        c = getc(filePointer);
        // displays the character from the file.
        putchar(c);
    } while (c != EOF); // keep loopin until the end of file is reached.

    fclose(filePointer); // close the file.
    return 0;
}