#include <stdio.h>

#include <stdlib.h>



#define MAX 1024



void clearStandardInput();



void samples();



int main() {
    char string1[MAX];
    char string2[MAX];
    char string3[MAX];


    printf("Enter String 1: ");

    scanf("%s", string1);

    printf("String 1 is: %s\n", string1);


    clearStandardInput();


    printf("Enter String 2: ");

    scanf("%[^\n]s\n", string2);

    printf("String 2 is: %s\n", string2);


    clearStandardInput();


    printf("Enter String 3: ");

    fgets(string3, MAX, stdin);
    
    fputs(string3, stdout);


    samples();


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



void samples() {
    char string1[MAX];
    char string2[MAX];
    char string3[MAX];

    sprintf(string1, "%d", 1    );
    sprintf(string2, "%f", 3.79 );
    sprintf(string3, "%c", 'J'  );

    printf("The Number 1 is: %s\n", string1);
    printf("The Number 2 is: %s\n", string2);
    printf("The Number 3 is: %s\n", string3);
}
