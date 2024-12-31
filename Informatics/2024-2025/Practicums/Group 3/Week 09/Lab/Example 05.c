#include <assert.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



unsigned int    readElem(                   );
unsigned int    readIndx(unsigned int size  );
unsigned int    readSize(                   );



void inputArray(        unsigned int array[], unsigned int size);
void printArray(const   unsigned int array[], unsigned int size);



void buildPrefixSums(const unsigned int array[], unsigned int result[], unsigned int size);
void buildSuffixSums(const unsigned int array[], unsigned int result[], unsigned int size);



int main() {
    unsigned int array[MAX_CAPACITY]    = { 0 };

    unsigned int prefixSums[MAX_CAPACITY]   = { 0 };
    unsigned int suffixSums[MAX_CAPACITY]   = { 0 };


    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    
    buildPrefixSums(array, prefixSums, size);
    buildSuffixSums(array, suffixSums, size);

    printArray(prefixSums, size);
    printArray(suffixSums, size);


    unsigned int index1 = readIndx(size);
    unsigned int index2 = readIndx(size);

    unsigned int minIndex = (index1 < index2) ? index1 : index2;
    unsigned int maxIndex = (index1 > index2) ? index1 : index2;

    printf("The prefix sum is: %d\n", (minIndex == 0       ) ? prefixSums[maxIndex] : prefixSums[maxIndex] - prefixSums[minIndex - 1]);
    printf("The suffix sum is: %d\n", (maxIndex == size - 1) ? suffixSums[minIndex] : suffixSums[minIndex] - suffixSums[maxIndex + 1]);


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readElem() {
    unsigned int elem   =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%u", &elem);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return elem;
}

unsigned int readIndx(unsigned int size) {
    unsigned int indx   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the index: ");

        inputArgument = scanf("%u", &indx);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || indx >= size);

    return indx;
}

unsigned int readSize() {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the size of the array: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX_CAPACITY);

    return size;
}



void inputArray(unsigned int array[], unsigned int size) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const unsigned int array[], unsigned int size) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%u ", array[i]);
    }

    putchar('\n');
}




void buildPrefixSums(const unsigned int array[], unsigned int result[], unsigned int size) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

    result[0] = array[0];

    for (unsigned int i = 1; i < size; ++i) {
        result[i] = result[i - 1] + array[i];
    }
}

void buildSuffixSums(const unsigned int array[], unsigned int result[], unsigned int size) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

    result[size - 1] = array[size - 1];

    for (unsigned int i = size - 2; /* i >= 0 */; --i) {
        if (i > size) {
            break;
        }

        result[i] = result[i + 1] + array[i];
    }
}
    