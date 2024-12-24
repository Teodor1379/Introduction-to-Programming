#include <stdio.h>



int main() {
    unsigned int z  =   0;
    unsigned int n  =   0;

    printf("Enter the number Z: "); if (scanf("%u", &z) != 1)   { puts("Input Error!"); return 1;   }
    printf("Enter the number N: "); if (scanf("%u", &n) != 1)   { puts("Input Error!"); return 1;   }

    if (n >= 8 * sizeof(unsigned int)) {
        printf("Invalid value for N!\n");

        return 1;
    }


    printf("The bitwise left    shift of Z with N is: %u\n",    z << n);
    printf("The bitwise right   shift of Z with N is: %u\n",    z >> n);


    return 0;
}
