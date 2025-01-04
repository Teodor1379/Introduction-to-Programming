#include <assert.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>



#define MAX 1024



char*   buildString(                );
void    clearString(char** string   );



int isPalindrome(const char* string);



int main() {
    char* string = buildString();

    if (string == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    int result = isPalindrome(string);

    printf("Is the string a palindrome: %s\n", result ? "Yes" : "No");


    clearString(&string);


    return 0;
}



char* buildString() {
    char* string = (char*)(malloc(MAX * sizeof(char)));

    if (string != NULL) {
        printf("Input the string: ");   fgets(string, MAX,  stdin   );
        printf("Output the string: ");  fputs(string,       stdout  );
    }

    return string;
}

void clearString(char** string) {
    assert(*string != NULL);

    free(*string);

    *string = NULL;
}



int isPalindrome(const char* string) {
    assert(string != NULL);

    unsigned int size = strlen(string) - 1;

    for (unsigned int i = 0; i < size / 2; ++i) {
        if (string[i] != string[size - i - 1]) {
            return 0;
        }
    }

    return 1;
}
