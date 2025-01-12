#include <assert.h>

#include <stdlib.h>

#include <stdio.h>



#define MAX 1024



char*   buildString(                );
void    clearString(char** string   );



int validateString(const char* string);



int main() {
    char* string = buildString();

    if (string == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    int result = validateString(string);

    printf("Is the string valid: %s\n", result ? "Yes" : "No");


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



int validateString(const char* string) {
    assert(string != NULL);

    long long counter = 0;

    for (unsigned int i = 0; string[i] != '\0'; ++i) {
        switch (string[i]) {
            case '(':   counter = counter + 1;  break;
            case ')':   counter = counter - 1;  break;
        }

        if (counter < 0) {
            return 0;
        }
    }

    return counter == 0;
}
