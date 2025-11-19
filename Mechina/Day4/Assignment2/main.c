/*------------------------------------------------------
* Filename: main.c
* Description: Dynamic structures
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_TIMES 2
#define HOURS 23
#define MINUTES 59
#define SECONDS 59

typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

/*------------------------------------------------------
* Function Name - display
*
* Function Purpose - displays the time
* Parameters –  int* ptr - pointer to a time object
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/

void display(Time* ptr) {
    printf("%d:%d:%d\n", ptr->hours, ptr->minutes, ptr->seconds);
}

/*------------------------------------------------------
* Function Name - closest_valid_hour
*
* Function Purpose - returns the closest valid value
* Parameters –  int hour - specific hour value
*
* Return Values - int - closest valid value of hours (0-23)
*
* Author - Yoav Malka
-------------------------------------------------------*/

int closest_valid_hour(int hour) {
    if(hour < 0) return 0;
    if(hour > HOURS) return HOURS;
    return hour;
}

/*------------------------------------------------------
* Function Name - closest_valid_minute
*
* Function Purpose - returns the closest valid value
* Parameters –  int minute - specific minutes value
*
* Return Values - int - closest valid value of seconds (0-59)
*
* Author - Yoav Malka
-------------------------------------------------------*/

int closest_valid_minute(int minute) {
    if(minute < 0) return 0;
    if(minute > MINUTES) return MINUTES;
    return minute;
}

/*------------------------------------------------------
* Function Name - closest_valid_second
*
* Function Purpose - returns the closest valid value
* Parameters –  int second - specific seconds value
*
* Return Values - int - closest valid value of seconds (0-59)
*
* Author - Yoav Malka
-------------------------------------------------------*/

int closest_valid_second(int second) {
    if(second < 0) return 0;
    if(second > SECONDS) return SECONDS;
    return second;
}

/*------------------------------------------------------
* Function Name - fix_time
*
* Function Purpose - fixes time if there are issues with its values
* Parameters –  Time* time - pointer to a time object to check
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/

void fix_time(Time* time) {
    time->hours = closest_valid_hour(time->hours);
    time->minutes = closest_valid_minute(time->minutes);
    time->seconds = closest_valid_second(time->seconds);
}

/*------------------------------------------------------
* Function Name - sum_times
*
* Function Purpose - sums up 2 time objects and returns a pointer of the result (allocated)
* Parameters –  Time* time1
*               Time* time2
*
* Return Values - Time* res - sum result of 2 times
*
* Author - Yoav Malka
-------------------------------------------------------*/

Time* sum_times(Time* time1, Time* time2) {

    Time* res = (Time*)malloc(sizeof(Time));
    if(res == NULL) {
        printf("Error!");
        return NULL;
    }

    int hours = time1->hours, minutes = time1->minutes, seconds = time1->seconds;

    seconds += time2->seconds;
    while(seconds > SECONDS) {
        seconds -= SECONDS+1;
        minutes++;
    }

    minutes += time2->minutes;
    while(minutes > MINUTES) {
        minutes -= MINUTES+1;
        hours++;
    }

    hours += time2->hours;
    while(hours > HOURS)
        hours -= HOURS+1;

    res->hours = hours;
    res->minutes = minutes;
    res->seconds = seconds;
    
    return res;
}

int main(){
    Time* ptr = (Time*)malloc(NUM_OF_TIMES*sizeof(Time));
    if(ptr == NULL){
        printf("Error :(");
        return -1;
    }

    printf("Enter values for %d Time objects (hours/minutes/seconds):\n", NUM_OF_TIMES);

    for(int i=0;i<NUM_OF_TIMES;i++){
        printf("\n---- #%d ----\n", (i+1));
        printf("* Hours: ");
        if(scanf("%d", &ptr[i].hours) != 1) {
            printf("Bad input!");
            return -1;
        }
        printf("* Minutes: ");
        if(scanf("%d", &ptr[i].minutes) != 1) {
            printf("Bad input!");
            return -1;
        }
        printf("* Seconds: ");
        if(scanf("%d", &ptr[i].seconds) != 1) {
            printf("Bad input!");
            return -1;
        }

        fix_time(&ptr[i]);
    }

    Time* res_ptr = sum_times(&ptr[0],&ptr[1]);

    printf("\nThe sum result of:\n");
    for(int i=0;i<NUM_OF_TIMES;i++) display(&ptr[i]);

    printf("\nis:\n");
    display(res_ptr);

    free(res_ptr);
    free(ptr);

    return 0;
}