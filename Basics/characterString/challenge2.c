/*Challenge: using bubble sort algorithm to sort character strings
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int numberOfStrings;                    //maximum no. of strings
    char usrString[25][25], temp[25];      // input string
    int i, j;

    printf("-------------------------------------------------------------------\n");
    printf("This will sort the strings of an array using the buble sort\n");
    printf("-------------------------------------------------------------------\n");

    printf("Enter no. of strings you'd like to sort:\n");
    scanf("%d", &numberOfStrings);

    printf("Input string %d: \n", numberOfStrings);     //will ask the user to input numberOfStrings

    for (i = 0; i < numberOfStrings; i++){
        scanf("%s", usrString[i]);
    }

    for (i = 1; i <= numberOfStrings; i++){
        for (j = 0; j <= numberOfStrings - i; j++)
            if (strcmp(usrString[j], usrString[j+1]) > 0){
                strcpy(temp, usrString[j]);
                strcpy(usrString[j], usrString[j + 1]);
                strcpy(usrString[j+ 1], temp);
            }
   }
}