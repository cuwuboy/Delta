/*------------------------------------------------------
* Filename: a.c
* Description: Turn a string number into a number+36
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> 

#define MAXSIZE 26

int main() {
    char str[MAXSIZE];
    printf("Enter string number:\n");
    if(scanf("%s", &str) != 1) {
        printf("Bad input :(");
        return -1;
    }
    if(!atoi(str)) {
        printf("Not a number");
        return -1;
    }
    int  res = atoi(str) + 36;
    printf("\nResult = %d\n", res);
    return 0;
}