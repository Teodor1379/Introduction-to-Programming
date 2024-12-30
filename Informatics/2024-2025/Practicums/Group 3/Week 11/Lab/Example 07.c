#include <stdlib.h>

#include <stdio.h>

#include <string.h>



void swap1(void* memory1, void* memory2, unsigned int size);
void swap2(void* memory1, void* memory2, unsigned int size);



void swapSamples1();
void swapSamples2();



int main() {
    swapSamples1();
    swapSamples2();

    return 0;
}



void swap1(void* memory1, void* memory2, unsigned int size) {
    void* memory3 = malloc(size);

    if (memory3 == NULL) {
        puts("Allocating Memory... ERROR!");

        return;
    }

    memcpy(memory3, memory2, size);
    memcpy(memory2, memory1, size);
    memcpy(memory1, memory3, size);

    free(memory3);

    memory3 = NULL;
}

void swap2(void* memory1, void* memory2, unsigned int size) {
    void* memory3 = malloc(size);

    if (memory3 == NULL) {
        puts("Allocating Memory... ERROR!");

        return;
    }

    memmove(memory3, memory2, size);
    memmove(memory2, memory1, size);
    memmove(memory1, memory3, size);

    free(memory3);

    memory3 = NULL;
}



void swapSamples1() {
    int x = 1;
    int y = 9;

    double a = 3.0;
    double b = 7.0; 
    

    swap1(&x, &y, sizeof(int)   );
    swap1(&a, &b, sizeof(double));


    printf("The number X is: %d\n",     x);
    printf("The number Y is: %d\n",     y);

    printf("The number A is: %lf\n",    a);
    printf("The number B is: %lf\n",    b);
}

void swapSamples2() {
    int x = 1;
    int y = 9;

    double a = 3.0;
    double b = 7.0;

    swap2(&x, &y, sizeof(int)   );
    swap2(&a, &b, sizeof(double));

    
    printf("The number X is: %d\n",     x);
    printf("The number Y is: %d\n",     y);

    printf("The number A is: %lf\n",    a);
    printf("The number B is: %lf\n",    b);
}
