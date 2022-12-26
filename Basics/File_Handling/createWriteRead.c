#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Pointer of type FILE to store the address from fopen.
    FILE *filePointer = NULL;
    char *memAddress = NULL, *temp = NULL;
    int sizeOfMemory;

    printf("Enter the maximum limit of words you want to write:");
    scanf("%d", &sizeOfMemory);

    // Allocate dynamic memory for storing of the ip character from the user
    memAddress = (char *)calloc(sizeOfMemory, sizeof(char));
    temp = memAddress;

    if (memAddress == NULL)
    {
        printf("unable to assign memmory!\nExiting the program...\n");
        return 0;
    }

    filePointer = fopen("myFullName.txt", "w");

    for (int i = 0; i < sizeOfMemory; i++)
    {
        printf("Enter any word:");
        scanf("%c", temp[i]);
        fprintf(filePointer, "%c", temp[i]);
    }

    fclose(filePointer);
    free(memAddress);

    return 0;
}