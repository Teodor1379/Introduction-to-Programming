#include <stdio.h>



int main() {
    int dayOfWeek = 0;

    printf("Enter the day of the week: ");
    
    if (scanf("%d", &dayOfWeek) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    switch (dayOfWeek) {
        case 1: printf("Monday!\n");                break;
        case 2: printf("Tuesday!\n");               break;
        case 3: printf("Wednesday!\n");             break;
        case 4: printf("Thursday!\n");              break;
        case 5: printf("Friday!\n");                break;
        case 6: printf("Saturday!\n");              break;
        case 7: printf("Sunday!\n");                break;
        default: printf("Well... I don't know!\n"); break;
    }

    
    switch (dayOfWeek) {
        case 1:
        case 3:
        case 5:
        case 7:
            printf("Odd Day!\n");

            break;
        case 2:
        case 4:
        case 6:
            printf("Even Day!\n");

            break;

        default:
            printf("Well... I still don't know!\n");

            break;
    }

    
    return 0;
}
