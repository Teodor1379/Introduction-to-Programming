#include <assert.h>

#include <stdlib.h>

#include <stdio.h>



#define DIF 32
#define MAX 1024



int isLowerLetter(const char c);
int isUpperLetter(const char c);



char*   buildString(                );
void    clearString(char* string    );



void transformString(char* string);



int main() {
    char* string = buildString();

    if (string == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    transformString(string);

    printf("The result string is: %s", string);


    clearString(string);


    return 0;
}



int isLowerLetter(const char c) { return c >= 'a' && c <= 'z';  }
int isUpperLetter(const char c) { return c >= 'A' && c <= 'Z';  }



char* buildString() {
    char* string = (char*)(malloc(MAX * sizeof(char)));

    if (string != NULL) {
        printf("Input the string: ");   fgets(string, MAX,  stdin   );
        printf("Output the string: ");  fputs(string,       stdout  );
    }

    return string;
}

void clearString(char* string) {
    assert(string != NULL   );

    free(string);

    string = NULL;
}



void transformString(char* string) {
    assert(string != NULL   );

    for (unsigned int i = 0; string[i] != '\0'; ++i) {
        if (isLowerLetter(string[i])) {
            string[i] = string[i] - DIF;
        } else if (isUpperLetter(string[i])) {
            string[i] = string[i] + DIF;
        } else {
            string[i] = string[i];
        }
    }
}
