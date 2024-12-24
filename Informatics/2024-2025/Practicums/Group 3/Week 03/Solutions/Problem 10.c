#include <stdio.h>



#define POINTS 20



int main() {
    unsigned int grade = 0;

    printf("Enter the grade: ");

    if (scanf("%u", &grade) != 1) {
        puts("Invalid Input!");

        return 1;
    }

    if (grade < 2 || grade > 6) {
        puts("Invalid Grade!");

        return 2;
    }


    unsigned int points1 = 0;
    unsigned int points2 = 0;
    unsigned int points3 = 0;

    printf("Enter the points of the other 3 Components: ");

    if (scanf("%u %u %u", &points1, &points2, &points3) != 3) {
        puts("Invalid Input!");

        return 1;
    }


    int condition1 = points1 <= 40;
    int condition2 = points2 <= 10;
    int condition3 = points3 <= 30;

    if (!condition1 || !condition2 || !condition3) {
        printf("Invalid Data for Points!");

        return 2;
    }


    unsigned int result = POINTS + points1 + points2 + points3;


    switch (grade) {
        case 2: printf("Available Grade: %s\n", result                 <   50   ? "Yes" : "No");    break;
        case 3: printf("Available Grade: %s\n", result >= 50 && result <=  60   ? "Yes" : "No");    break;
        case 4: printf("Available Grade: %s\n", result >= 61 && result <=  70   ? "Yes" : "No");    break;
        case 5: printf("Available Grade: %s\n", result >= 71 && result <=  80   ? "Yes" : "No");    break;
        case 6: printf("Available Grade: %s\n", result >= 81 && result <= 100   ? "Yes" : "No");    break;
    }

    
    return 0;
}
