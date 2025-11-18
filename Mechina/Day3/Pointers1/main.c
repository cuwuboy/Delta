/*------------------------------------------------------
* Filename: main.c
* Description: Learn about pointers in C
* Author: Yoav Malka
-------------------------------------------------------*/
#include <stdio.h>

#define LEN 8

int main(){
    char chars[LEN];
    int ints[LEN];

    printf("Please enter %d characters:\n", LEN);
    for(int i=0;i<LEN;i++) {
        if(scanf(" %c", &chars[i])!=1) {
            printf("ERROR!");
            return -1;
        }
    }

    printf("Please enter %d integers:\n", LEN);
    for(int i=0;i<LEN;i++) {
        if(scanf(" %d", &ints[i])!=1) {
            printf("ERROR!");
            return -1;
        }
    }
    
    printf("PRINT USING []:\n");
    for(int i=0;i<LEN;i++)
        printf("INTS[%d] = %d | ADDRESS = %p\n", i, ints[i], &ints[i]);
    printf("\n");
    for(int i=0;i<LEN;i++)
        printf("CHARS[%d] = %c | ADDRESS = %p\n", i, chars[i], &chars[i]);

    printf("PRINT USING *():\n");
    for(int i=0;i<LEN;i++)
        printf("INTS[%d] = %d | ADDRESS = %p\n", i, *(ints+i), (ints+i));
    printf("\n");
    for(int i=0;i<LEN;i++)
        printf("CHARS[%d] = %c | ADDRESS = %p\n", i, *(chars+i), (chars+i));

    return 0;
}