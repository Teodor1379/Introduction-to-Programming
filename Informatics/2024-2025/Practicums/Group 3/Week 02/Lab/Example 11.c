#include <stdio.h>



int main() {
    printf("Size of             INT: %lu\n",    sizeof(int)             );
    printf("Size of SHORT       INT: %lu\n",    sizeof(short int)       );
    printf("Size of LONG        INT: %lu\n",    sizeof(long  int)       );
    printf("Size of LONG LONG   INT: %lu\n",    sizeof(long long int)   );


    printf("Size of             UNSIGNED INT: %lu\n",   sizeof(unsigned int)            );
    printf("Size of SHORT       UNSIGNED INT: %lu\n",   sizeof(short unsigned int)      );
    printf("Size of LONG        UNSIGNED INT: %lu\n",   sizeof(long unsigned int)       );
    printf("Size of LONG LONG   UNSIGNED INT: %lu\n",   sizeof(long long unsigned int)  );


    printf("Size of FLOAT: %lu\n",  sizeof(float));

    printf("Size of         DOUBLE: %lu\n", sizeof(double)      );
    printf("Size of LONG    DOUBLE: %lu\n", sizeof(long double) );


    printf("Size of             CHAR: %lu\n",   sizeof(char)            );
    printf("Size of UNSIGNED    CHAR: %lu\n",   sizeof(unsigned char)   );


    printf("Size of VOID*   : %lu\n",   sizeof(void*)   );
    printf("Size of INT*    : %lu\n",   sizeof(int*)    );
    printf("Size of FLOAT*  : %lu\n",   sizeof(float*)  );
    printf("Size of DOUBLE* : %lu\n",   sizeof(double*) );
    printf("Size of CHAR*   : %lu\n",   sizeof(char*)   );


    return 0;
}
