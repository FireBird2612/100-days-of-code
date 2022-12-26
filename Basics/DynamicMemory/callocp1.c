/*
Problem: Write a c program which writes and reads data dynamically
Date: 14 Dec 2022
Status: Completed
------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int memSizeAllocation, *pMemAddress = NULL, *temp = NULL;

    printf("Enter the size of the memory you would like to allcoate:");
    scanf("%d", &memSizeAllocation);

    pMemAddress = (int *)calloc(memSizeAllocation, sizeof(int));
    temp = pMemAddress;

    // If memory cannot be allocated
    if (pMemAddress == NULL)
    {
        printf("Error! Unable to allocate the Memory!");
        exit(0);
    }

    printf("Enter the numbers to be saved into the memory:\n");
    for (int i = 0; i < memSizeAllocation; i++)
    {
        scanf("%d", temp);
        temp++;
    }
    temp = pMemAddress;
    printf("-----------------------\n");
    // Display the number entered by the user
    for (int i = 0; i < memSizeAllocation; i++)
    {
        printf("%d\n", *temp);
        temp++;
    }

    // deallocating the memory
    free(pMemAddress);

    return 0;
}

/*

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int memSizeAllocation, *pMemAddress = NULL;

    printf("Enter the size of the memory you would like to allcoate:");
    scanf("%d", &memSizeAllocation);

    pMemAddress = (int *)calloc(memSizeAllocation, sizeof(int));

    // If memory cannot be allocated
    if (pMemAddress == NULL)
    {
        printf("Error! Unable to allocate the Memory!");
        exit(0);
    }

    printf("Enter the numbers to be saved into the memory:\n");
    for (int i = 0; i < memSizeAllocation; i++)
    {
        scanf("%d", pMemAddress);
        pMemAddress++;
    }
    pMemAddress--;

    printf("-----------------------\n");
    // Display the number entered by the user
    for (int i = 0; i < memSizeAllocation; i++)
    {
        printf("%d\n", *pMemAddress);
        pMemAddress--;
    }

    // deallocating the memory
    free(pMemAddress);

    printf("Checking the address of pMemAddress, %p", pMemAddress);

    return 0;
}

*/