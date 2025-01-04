#include <assert.h>

#include <stdlib.h>

#include <stdio.h>



#define MAX 1024



void clearStandardInput();



char    readCharacter();



char*   buildString(                );
void    clearString(char** string   );



unsigned int countOccurences(const char* string, char character);



int main() {
    char* string = buildString();

    if (string == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }

    
    char character = readCharacter();


    printf("The occurences are: %u\n",  countOccurences(string, character));


    clearString(&string);


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



char readCharacter() {
    char character = 0;

    printf("Enter the character: ");

    character = getchar();

    return character;
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
    assert(*string   != NULL );

    free(*string);

    *string = NULL;
}



unsigned int countOccurences(const char* string, char character) {
    unsigned int result = 0;

    for (unsigned int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == character) {
            result = result + 1;
        }
    }

    return result;
}
