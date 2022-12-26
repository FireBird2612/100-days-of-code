#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>                                                    //use this library for using boolean data type.

bool compare(const char str1[], const char str2[]);                     //function prototype.

int main(){
    const char name1[] = "Sm";                         
    const char name2[] = "Sam";

    printf("%d\n", compare(name1, name2));
    printf("%d\n", compare("Sams", "sam"));
}

bool compare(const char str1[], const char str2[]){
    int i=0;
    bool result;                                                        //stores the results of two strings.
    while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')    //compare if two strings are equal in character and number, exit the loop if any of the two strings character is null.
    {
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0')                             //only if both the strings have null on same element will they evaluate to true.
        result = true;
    else
        result = false;                                                 //else false

    return result;
}