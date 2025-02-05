#include <assert.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>



#define MAX 1024



void clearStandardInput();



unsigned int readSize();



char* buildString(              );
void  clearString(char** string );



int isPrefix(const char* string1, const char* string2);
int isSuffix(const char* string1, const char* string2);



int main() {
    char* string1 = buildString();  if (string1 == NULL)    { puts("Allocating Memory... ERROR!");                          return 1;   }
    char* string2 = buildString();  if (string2 == NULL)    { puts("Allocating Memory... ERROR!");  clearString(&string1);  return 1;   }


    int isPrefixNumber = isPrefix(string1, string2);
    int isSuffixNumber = isSuffix(string1, string2);

    printf("Is the string a prefix: %s\n",  isPrefixNumber ? "Yes" : "No");
    printf("Is the string a suffix: %s\n",  isSuffixNumber ? "Yes" : "No");


    clearString(&string1);
    clearString(&string2);


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



char* buildString() {
    char* string = (char*)(malloc(MAX * sizeof(string)));

    if (string != NULL) {
        printf("Input   the string: "); fgets(string, MAX,  stdin   );
        printf("Output  the string: "); fputs(string,       stdout  );
    }

    string[strlen(string) - 1] = '\0';

    return string;
}

void clearString(char** string) {
    assert(*string != NULL);

    free(*string);

    *string = NULL;
}



int isPrefix(const char* string1, const char* string2) {
    assert(string1  !=  NULL);
    assert(string2  !=  NULL);

    unsigned int size1  =   strlen(string1);
    unsigned int size2  =   strlen(string2);

    if (size1 < size2) {
        return 0;
    }

    const char* pointer1 = string1;
    const char* pointer2 = string2;

    while (*pointer2 != '\0') {
        if (*pointer1 != *pointer2) {
            return 0;
        }

        pointer1 = pointer1 + 1;
        pointer2 = pointer2 + 1;
    }

    return 1;
}

int isSuffix(const char* string1, const char* string2) {
    assert(string1  !=  NULL);
    assert(string2  !=  NULL);

    unsigned int size1  =   strlen(string1);
    unsigned int size2  =   strlen(string2);

    if (size1 < size2) {
        return 0;
    }

    const char* pointer1    =   string1 + size1 - 1;
    const char* pointer2    =   string2 + size2 - 1;

    while (pointer2 != string2) {
        if (*pointer1 != *pointer2) {
            return 0;
        }

        pointer1 = pointer1 - 1;
        pointer2 = pointer2 - 1;
    }

    return 1;
}
