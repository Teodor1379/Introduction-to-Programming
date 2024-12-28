#include <stdlib.h>

#include <stdio.h>



void allocateVariable();



int main() {
    allocateVariable();

    return 0;
}



void allocateVariable() {
    int* variable = malloc(sizeof(int));

    if (variable == NULL) {
        return;
    }

    *variable = 1379;

    printf("The value is: %d\n", *variable);

    // int j = 'J';
    // variable = &j;

    free(NULL);

    free(variable);

    variable = NULL;

    // free(variable);
}
