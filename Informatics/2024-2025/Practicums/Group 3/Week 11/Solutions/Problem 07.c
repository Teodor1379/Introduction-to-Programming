#include <assert.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>


#define MAX 1024


char*   buildString(                );
void    clearString(char** string   );



unsigned int calculateHammingDistance(const char* string1, const char* string2);



int main() {
    char* string1 = buildString();

    if (string1 == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }

    char* string2 = buildString();

    if (string2 == NULL) {
        puts("Allocating Memory... ERROR");

        clearString(&string1);

        return 1;
    }


    unsigned int result = calculateHammingDistance(string1, string2);

    printf("The Hamming distance for the strings is: %u\n", result);


    clearString(&string1);
    clearString(&string2);


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



unsigned int calculateHammingDistance(const char* string1, const char* string2) {
    assert(string1 != NULL);
    assert(string2 != NULL);

    if (strlen(string1) != strlen(string2)) {
        puts("Invalid Length for the strings!");

        return 0;
    }

    unsigned int distance = 0;

    unsigned int size = strlen(string1);

    for (unsigned int i = 0; i < size; ++i) {
        if (string1[i] != string2[i]) {
            distance = distance + 1;
        }
    }

    return distance;
}
