/*------------------------------------------------------
* Filename: main.h
* Description: interface to represent kid structure
* Author: Yoav Malka
-------------------------------------------------------*/
#include <stdio.h>

#define MAX_NAME 26

typedef struct kid_s{
    char name[MAX_NAME];
    struct kid_s* blames;
} kid_t;