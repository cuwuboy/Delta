/*------------------------------------------------------
* Filename: main.c
* Description: Calculate Gary's age
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>

#define DAYS_IN_MONTH 30
#define DAYS_IN_YEAR 365

int main() {
    printf("Print current date:\n");
    int current_day, current_month, current_year;
    scanf("%d/%d/%d", &current_day, &current_month, &current_year);
    printf("\n");

    printf("Print Gary's Birthday:\n");
    int birth_day, birth_month, birth_year;
    scanf("%d/%d/%d", &birth_day, &birth_month, &birth_year);
    printf("\n");

    int code_current = current_year*DAYS_IN_YEAR + current_month*DAYS_IN_MONTH + current_day;
    int code_birth = birth_year*DAYS_IN_YEAR + birth_month*DAYS_IN_MONTH + birth_day;

    int diff_days = code_current - code_birth;

    printf("Gary's age in days %d\n", diff_days);
    printf("Gary's age in months %f\n", (float)diff_days/DAYS_IN_MONTH);
    printf("Gary's age in years %f\n", (float)diff_days/DAYS_IN_YEAR);

    return 0;
}