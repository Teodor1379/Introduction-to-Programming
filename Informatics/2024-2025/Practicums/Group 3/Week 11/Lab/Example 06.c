#include <stdio.h>

#include <string.h>



int main() {
    const char* string = "Good afternoon, Mr. Wick!";


    char* string1 = strstr(string, "Wick!");
    char* string2 = strstr(string, "Roma!");

    printf("The result of pointer 1 is: %d\n",  string1 == NULL);
    printf("The result of pointer 2 is: %d\n",  string2 == NULL);


    return 0;
}
