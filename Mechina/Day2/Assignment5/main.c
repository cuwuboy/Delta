/*------------------------------------------------------
* Filename: parta.c
* Description: Draw a hanukia
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>

int main() {
    int num = 0;
    scanf("%d", &num);
    printf("\n\n");
    int index = 1;
    printf(" %c   ",(('#'*(index<=num)) + (' '*(num<index))));
    index++;
    printf(" %c   ",(('#'*(index<=num)) + (' '*(num<index))));
    index++;
    printf(" %c   ",(('#'*(index<=num)) + (' '*(num<index))));
    index++;
    printf(" %c   ",(('#'*(index<=num)) + (' '*(num<index))));
    index++;
    printf(" %c   ",(('#'*(index<=num)) + (' '*(num<index))));
    index++;
    printf(" %c   ",(('#'*(index<=num)) + (' '*(num<index))));
    index++;
    printf(" %c   ",(('#'*(index<=num)) + (' '*(num<index))));
    index++;
    printf(" %c   ",(('#'*(index<=num)) + (' '*(num<index))));
    index++;
    printf(" %c   ",(('#'*(index<=num)) + (' '*(num<index))));
    index++;

    printf("\n###  ###  ###  ###  ### ###  ###  ###\n");
    printf("###  ###  ###  ###  ### ###  ###  ###\n");
    printf("###  ###  ###  ###  ### ###  ###  ###\n");
    printf("###  ###  ###  ###  ### ###  ###  ###\n");
    printf("#####################################\n");
    printf("                 | |\n");
    printf("                 | |\n");
    printf("                 | |\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");

    return 0;
}