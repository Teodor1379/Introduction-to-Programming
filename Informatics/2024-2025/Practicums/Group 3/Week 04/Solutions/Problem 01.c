#include <stdio.h>

int main() {
    unsigned int n  =   0;
    unsigned int s  =   0;

    unsigned int bit = (n >> s) & 1;

    printf("The S-th bit of number N is: %u\n", bit);

    return 0;
}
