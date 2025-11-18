/*------------------------------------------------------
* Filename: parta.c
* Description: Part A and B of assignment 4
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>

int main() {
    int num = 0;
    scanf("%d", &num);

    if(num<=0) { //ERROR
        printf("\nBad input!\n");
        return -1;
    }

    char sym = '*';
    if(num%2 != 0) {
        if(num%3 == 0) sym = '^';
        else if(num%5 == 0) sym = '%';
        else sym = '@';
    }

    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++)
            printf("%c",sym);
        printf("\n");
    }

    return 0;
}