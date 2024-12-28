#include <stdio.h>



int main() {
    int matrix[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };


    printf("%p\n", (void*)(matrix));            // Address of element: { 1, 2, 3, 4 }

    printf("%p\n", (void*)(matrix + 0));        // Address of element: { 1, 2, 3, 4 }
    printf("%p\n", (void*)(matrix + 1));        // Address of element: { 5, 6, 7, 8 }
    printf("%p\n", (void*)(matrix + 2));        // Address of element: { 9, 10, 11, 12 }


    printf("%p\n", (void*)(*matrix));           // Address of element: 1

    printf("%p\n", (void*)(*matrix + 0));       // Address of element: 1
    printf("%p\n", (void*)(*matrix + 1));       // Address of element: 2
    printf("%p\n", (void*)(*matrix + 2));       // Address of element: 3
    printf("%p\n", (void*)(*matrix + 3));       // Address of element: 4

    printf("%p\n", (void*)(*(matrix + 1) + 0)); // Address of element: 5
    printf("%p\n", (void*)(*(matrix + 1) + 1)); // Address of element: 6
    printf("%p\n", (void*)(*(matrix + 1) + 2)); // Address of element: 7
    printf("%p\n", (void*)(*(matrix + 1) + 3)); // Address of element: 8

    printf("%p\n", (void*)(*(matrix + 2) + 0)); // Address of element: 9
    printf("%p\n", (void*)(*(matrix + 2) + 1)); // Address of element: 10
    printf("%p\n", (void*)(*(matrix + 2) + 2)); // Address of element: 11
    printf("%p\n", (void*)(*(matrix + 2) + 3)); // Address of element: 12

    
    printf("%d\n", *(*matrix + 0));         // Element: 1   // Just: **matrix
    printf("%d\n", *(*matrix + 1));         // Element: 2
    printf("%d\n", *(*matrix + 2));         // Element: 3
    printf("%d\n", *(*matrix + 3));         // Element: 4

    printf("%d\n", *(*(matrix + 1) + 0));   // Element: 5   // Just: **(matrix + 1)
    printf("%d\n", *(*(matrix + 1) + 1));   // Element: 6
    printf("%d\n", *(*(matrix + 1) + 2));   // Element: 7
    printf("%d\n", *(*(matrix + 1) + 3));   // Element: 8

    printf("%d\n", *(*(matrix + 2) + 0));   // Element: 9   // Just: **(matrix + 2)
    printf("%d\n", *(*(matrix + 2) + 1));   // Element: 10
    printf("%d\n", *(*(matrix + 2) + 2));   // Element: 11
    printf("%d\n", *(*(matrix + 2) + 3));   // Element: 12


    // Equivalent: *(*matrix + n)           matrix[n]
    // Equivalent: *(*(matrix + i) + j)     matrix[i][j]


    return 0;
}
