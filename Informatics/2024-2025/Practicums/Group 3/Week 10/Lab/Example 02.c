#include <assert.h>

#include <limits.h>

#include <stdlib.h>

#include <stdio.h>



void clearStandardInput();



int             readElem();
unsigned int    readSize();



int* buildArray1(                       unsigned int size   );
int* buildArray2(                       unsigned int size   );
void clearArray (        int* array                         );

void inputArray (        int* array,    unsigned int size   );
void printArray (const   int* array,    unsigned int size   );



int* insertElement(int** array, unsigned int* size, int element);



int main() {
    unsigned int size1 = readSize();
    unsigned int size2 = readSize();


    int* array1 = buildArray1(size1);   if (array1 == NULL) { puts("Allocating Memory... ERROR!");                       return 1;   }
    int* array2 = buildArray2(size2);   if (array2 == NULL) { puts("Allocating Memory... ERROR!");   clearArray(array1); return 1;   }


    if (insertElement(&array1, &size1, 13)  ==  NULL)   {   puts("Reallocating Memory... ERROR!");  }
    if (insertElement(&array2, &size2, 97)  ==  NULL)   {   puts("Reallocating Memory... ERROR!");  }

    printArray(array1, size1);
    printArray(array2, size2);


    clearArray(array1);
    clearArray(array2);


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



int readElem() {
    int elem            =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%d", &elem);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return elem;
}

unsigned int readSize() {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the size of the array: ");

        inputArgument = scanf("%u", &size);

        clearStandardInput();
    } while (inputArgument != 1 || size == 0 || size > UINT_MAX);

    return size;
}



int* buildArray1(unsigned int size) {
    assert(size != 0);

    // void* malloc(size_t size);
    // Parameters:
    //      size    - number of bytes to allocate
    // Return Value:
    //      Success:    Returns the pointer to the beginning of newly allocated memory.
    //                  To avoid a memory leak, the returned pointer must be deallocated
    //                  with free() or realloc().
    //      Failure:    Returns a null pointer.

    // Allocates size bytes of uninitialized storage.

    // If allocation succeeds, returns a pointer that is suitably
    // aligned for any object type with fundamental alignment.

    // If size is zero, the behavior of malloc is implementation-defined. For example, a null pointer 
    // may be returned. Alternatively, a non-null pointer may be returned; but such pointer should not
    // be dereferenced, and should be passed to free to avoid memory leaks.

    int* array = (int*)(malloc(size * sizeof(int)));

    if (array != NULL) {
        inputArray(array, size);
        printArray(array, size);
    }

    return array;
}

int* buildArray2(unsigned int size) {
    assert(size != 0);

    // void* calloc(size_t num, size_t size);
    // Parameters:
    //      num     - number of objects
    //      size    - size of each object
    // Return Value:
    //      Success:    Returns the pointer to the beginning of newly allocated memory.
    //                  To avoid a memory leak, the returned pointer must be deallocated
    //                  with free() or realloc().

    // Allocates memory for an array of num objects of size and
    // initializes all bytes in the allocated storage with zero.

    // If allocation succeeds, returns a pointer to the lowest (first) bytes in the allocated
    // memory block that is suitably aligned for any object type with fundamental alignment.

    // If size is zero, the behavior is implementation defined (null pointer may be returned,
    // or some non-null pointer may be returned that may not be used to access storage).

    int* array = (int*)(calloc(size, sizeof(int)));

    if (array != NULL) {
        inputArray(array, size);
        printArray(array, size);
    }

    return array;
}

void clearArray(int* array) {
    assert(array != NULL);

    // void free(void* ptr);
    // Parameters:
    //      ptr     -   pointer to the memory to deallocate
    // Return Value: (none)

    // Deallocates the space previously allocated by malloc(), calloc() or realloc().

    // If ptr is a null pointer, the function does nothing.

    // The behavior is undefined if the value of ptr does not equal a value returned by malloc(), calloc(), realloc().
    
    // The behavior is undefined if the memory area referred to by ptr has already been deallocated,
    // that is, free() or realloc() has already been called with ptr as the argument and no calls to
    // malloc(), calloc() or realloc() resulted in a pointer equal to ptr afterwards.

    // The behavior is undefined after free() returns, an access is made through the pointer ptr
    // (unless another allocation function happened to result in a pointer value equal to ptr).

    free(array);

    array = NULL;
}


void inputArray(int* array, unsigned int size) {
    assert(array    != NULL );
    assert(size     != 0    );

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const int* array, unsigned int size) {
    assert(array    != NULL );
    assert(size     != 0    );

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}



int* insertElement(int** array, unsigned int* size, int element) {
    assert(array != NULL);
    assert(*size != 0   );

    // void* realloc(void* ptr, size_t new_size);
    // Parameters:
    //       ptr    -   pointer to the memory area to be reallocated
    //  new_size    -   new size of the array in bytes
    // Return Value:
    //      Success:    Returns the pointer to the beginning of newly allocated memory.
    //                  To avoid a memory leak, the returned pointer must be deallocated
    //                  with free or realloc. The original pointer ptr is invalidated and
    //                  any access to it is undefined behavior (even if reallocation was
    //                  in-place).
    //      Failure:    Returns a null pointer. The original pointer ptr remains valid
    //                  and may need to be deallocated with free or realloc.

    // Reallocates the given area of memory. If ptr is not NULL, it must be previously allocated by malloc,
    // calloc or realloc and not yet freed with a call of free or realloc. Otherwise, the results are undefined.

    // The reallocation is done by either:
    //  a) expanding or contracting the existing area pointed to by ptr, if possible. The contents of the area remain unchanged 
    // up to the lesser of the new and old sizes. If the area is expanded, the contents of the new part of the array are undefined.
    //  b) allocating a new memory block of size new_size bytes, copying memory area with size equal to the lesser of the new and
    // old sizes, and freeing the old block.

    // If there is not enough memory, the old memory block is not freed and null pointer is returned.

    // If ptr is NULL, the behavior is the same as calling malloc(new_size).

    // Otherwise,
    //  if new_size is zero, the behavior is implementation defined (null pointer may be returned (in which case the old memory 
    // block may or may not be freed), or some non-null pointer may be returned that may not be used to access storage).
    //  if new_size is zero, the behavior is undefined.

    int* result = (int*)(realloc(*array, (*size + 1) * sizeof(int)));

    if (result == NULL) {
        return NULL;
    }

    result[*size] = element;

    *array  =   result      ;
    *size   =   *size + 1   ;
    
    return result;
}
