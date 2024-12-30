#include <stdio.h>

#include <stdlib.h>

#include <string.h>



int main() {
    char* string1 = "John Wick";
    char* string2 = " is EXCOMMUNICADO!";

    size_t size1    =   strlen(string1)     ;
    size_t size2    =   strlen(string2)     ;
    size_t size     =   size1 + size2 + 1   ;


    char* string = (char*)(malloc(size * sizeof(char)));

    if (string == NULL) {
        puts("Allocating Memory... ERROR");

        return 1;
    }


    strcpy(string, string1);
    strcat(string, string2);

    printf("The string result is: %s\n", string);


    free(string);

    string = NULL;


    return 0;
}
