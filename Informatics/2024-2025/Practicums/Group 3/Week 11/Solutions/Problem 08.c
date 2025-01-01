#include <assert.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>



#define MAX 1024


char*   buildString(                );
void    clearString(char* string    );


int isSubstring(const char* string, const char* substring);



int isPrefix(const char* string, const char* substring);
int isInfixx(const char* string, const char* substring);
int isSuffix(const char* string, const char* substring);



int main() {
    char* string1 = buildString();

    if (string1 == NULL) {
        puts("Allocate Memory... ERROR!");

        return 1;
    }

    char* string2 = buildString();

    if (string2 == NULL) {
        puts("Allocating Memory... ERROR!");

        clearString(string1);

        return 1;
    }


    int global = isSubstring(string1, string2);

    int result1 =   isPrefix(string1, string2);
    int result2 =   isInfixx(string1, string2);
    int result3 =   isSuffix(string1, string2);

    printf("Is substring: %s\n", global ? "Yes" : "No");

    if (global) {
        printf("Is prefix: %s\n",   result1 ? "Yes" : "No");
        printf("Is infix : %s\n",   result2 ? "Yes" : "No");
        printf("Is suffix: %s\n",   result3 ? "Yes" : "No");
    }

    
    clearString(string1);
    clearString(string2);


    return 0;
}



char* buildString() {
    char* string = (char*)(malloc(MAX * sizeof(char)));

    if (string != NULL) {
        printf("Input the string: ");   fgets(string, MAX,  stdin   );
        printf("Output the string: ");  fputs(string,       stdout  );
    }

    string[strlen(string) - 1] = '\0';

    return string;
}

void clearString(char* string) {
    assert(string != NULL);

    free(string);

    string = NULL;
}



int isSubstring(const char* string, const char* substring) {
    assert(string       !=  NULL    );
    assert(substring    !=  NULL    );

    return strstr(string, substring) != NULL;
}



int isPrefix(const char* string, const char* substring) {
    assert(string       !=  NULL    );
    assert(substring    !=  NULL    );

    if (strlen(string) < strlen(substring)) {
        return 0;
    }

    return strncmp(substring, string, strlen(substring)) == 0;
}

int isInfixx(const char* string, const char* substring) {
    assert(string       !=  NULL    );
    assert(substring    !=  NULL    );

    const char* pointer = strstr(string, substring);

    if (pointer == NULL) {
        return 0;
    }

    return  !isPrefix(string, substring)    &&
            !isSuffix(string, substring)    ;
}

int isSuffix(const char* string, const char* substring) {
    assert(string       !=  NULL    );
    assert(substring    !=  NULL    );

    if (strlen(string) < strlen(substring)) {
        return 0;
    }

    return strcmp(string + strlen(string) - strlen(substring), substring) == 0;
}
