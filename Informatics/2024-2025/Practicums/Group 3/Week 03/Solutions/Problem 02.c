#include <stdio.h>

int main() {
    unsigned int z  =   0;
    unsigned int n  =   0;

    printf("Enter the number Z: "); scanf("%u", &z);
    printf("Enter the number N: "); scanf("%u", &n);

    if (n >= 8 * sizeof(unsigned int)) {
        printf("Invalid value for N!\n");

        return 1;
    }

    printf("The bitwise left    shift of Z with N is: %u\n",    z << n);
    printf("The bitwise right   shift of Z with N is: %u\n",    z >> n);

    return 0;
}
