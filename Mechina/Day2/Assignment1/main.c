/*------------------------------------------------------
* Filename: main.c
* Description: Find maximum value
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>

int main() {
    int x = 5;                  //1
    int y = 9;                  //2
    int z = (x>=y)*x + (y>x)*y; //3
    printf("%d", z);            //4

    return 0;
}