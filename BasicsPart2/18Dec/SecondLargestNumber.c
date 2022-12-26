/*
Problem: 3. Write a C program that accepts three integers from the user
            and find second largest number among these.
            CONSTRAINTS:
            1≤ x ≤100
            1≤ y ≤100
            1≤ z ≤100
            SAMPLE DATA:
            (1 , 2, 3) -> 2
            (10, 12, 24) -> 12
            (34, 21, 30) -> 30
Date: 18 Dec 2022
Status: Completed
----------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define UpLimit 3

int main(void)
{
    short int UserNum[UpLimit], ValidNum, temp1;
    printf("input any 3 numbers:");

    for (int i = 0; i < UpLimit; i++)
    {
        scanf("%hu", &ValidNum);
        if (ValidNum >= 1 && ValidNum <= 100)
        {
            UserNum[i] = ValidNum;
        }
        else
        {
            printf("Only Numbers greater than or equal to 1 and less than or equal to 100  are permitted!\n");
            exit(0);
        }
    }

    for (int i = 0; i < UpLimit; i++)
    {
        for (int j = i + 1; j < UpLimit; j++)
        {
            if (UserNum[i] > UserNum[j])
            {
                temp1 = UserNum[i];
                UserNum[i] = UserNum[j];
                UserNum[j] = temp1;
            }
        }
    }

    printf("The Second Largest Number is: %d\n", UserNum[1]);
}