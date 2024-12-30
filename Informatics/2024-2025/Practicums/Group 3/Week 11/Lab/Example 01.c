#include <stdio.h>

#include <stdlib.h>



int main() {
    const char string1[]    =   { 'J', 'e', 's', 's', '\0' };
    const char string2[]    =   "Teodor";
    const char* string3     =   "John Wick";


    printf("String 1 is: %s\n", string1);
    printf("String 2 is: %s\n", string2);
    printf("String 3 is: %s\n", string3);


    char* string = (char*)(malloc(14 * sizeof(char)));

    string[0]   =   'E' ;
    string[1]   =   'X' ;
    string[2]   =   'C' ;
    string[3]   =   'O' ;
    string[4]   =   'M' ;
    string[5]   =   'M' ;
    string[6]   =   'U' ;
    string[7]   =   'N' ;
    string[8]   =   'I' ;
    string[9]   =   'C' ;
    string[10]  =   'A' ;
    string[11]  =   'D' ;
    string[12]  =   'O' ;
    string[13]  =   '\0';

    printf("The status of the member is: %s\n", string);

    free(string);


    return 0;
}
