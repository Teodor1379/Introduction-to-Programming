#include <stdio.h>

int isLeapYear(long long year) {
    return  (year > 0)                  &&
            (   (year % 400 == 0)       ||
                (
                    (year % 100 != 0)   &&
                    (year % 4   == 0)
                )
            );
}

int validateDate(long long day, long long month, long long year) {
    switch(month) {
        case 1:     return day >= 1 && day <= 31;
        case 2:     return day >= 1 && day <= 28 + isLeapYear(year);
        case 3:     return day >= 1 && day <= 31;
        case 4:     return day >= 1 && day <= 30;
        case 5:     return day >= 1 && day <= 31;
        case 6:     return day >= 1 && day <= 30;
        case 7:     return day >= 1 && day <= 31;
        case 8:     return day >= 1 && day <= 31;
        case 9:     return day >= 1 && day <= 30;
        case 10:    return day >= 1 && day <= 31;
        case 11:    return day >= 1 && day <= 30;
        case 12:    return day >= 1 && day <= 31;
        default:    return 0;
    }
}

int main() {
    long long day   =   0;
    long long month =   0;
    long long year  =   0;

    printf("Enter the date in format DD MM YYYY: ");

    scanf("%lld %lld %lld", &day, &month, &year);

    if (validateDate(day, month, year)) {
        puts("The date is VALID!");
    } else {
        puts("The date is INVALID!");
    }
    
    return 0;
}
