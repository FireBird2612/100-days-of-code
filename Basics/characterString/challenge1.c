#include <stdio.h>
#include <stdlib.h>

int stringcount(const char yourstring[]);                                       //function prototype
void stackon(const char string1[], const char string2[], char final[]);

int main (){                                                                    //main function
    char dest[] = "Sanket Gunjal";
    const char src[] = " you did it!";
    char final[50];

    stackon(dest, src, final);

    printf("\n\n\n\n%s", final);
}

int stringcount(const char yourstring[]){                                       //this is my fucntion for counting the number of characters in a string
    int count = 0;
    while(yourstring[count] != '\0'){
        ++count;
    }
    return count;
}

void stackon(const char string1[], const char string2[], char final[]){             //stacking function
    int i, j;
    for (i = 0; string1[i] != '\0'; ++i ){
        final[i] = string1[i];
    }

    for (j = 0; string2[j] != '\0'; ++j){
        final[i + j] = string2[j];
    }

    final[i + j] = '\0';
}