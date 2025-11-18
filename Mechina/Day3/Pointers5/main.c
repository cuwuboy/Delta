/*------------------------------------------------------
* Filename: main.c
* Description: struct pointers
* Author: Yoav Malka
-------------------------------------------------------*/
#include <stdio.h>
#include "main.h"

#define KIDS 5

int main(){
    kid_t kids[]={{"kid0",0},
                {"kid1",NULL},
                {"kid2",NULL},
                {"kid3",NULL},
                {"kid4",NULL}};

    int n,m;
    //kid n blames kid m
    printf("enter the blame list:\n");
    for(int i=0;i<KIDS;i++){
        if(scanf("%d,%d",&n,&m)==1 || n<0 || n>KIDS || m<0 || m>KIDS) {
            printf("Bad Input!");
            return -1;
        }
        kids[n].blames = &kids[m];
    }

    for(int i=0;i<KIDS;i++) printf("%s blames %s\n",kids[i],kids[i].blames->name);

    return 0;
}