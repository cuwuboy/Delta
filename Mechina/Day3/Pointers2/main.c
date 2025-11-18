/*------------------------------------------------------
* Filename: main.c
* Description: Learn about pointers in C
* Author: Yoav Malka
-------------------------------------------------------*/
#include <stdio.h>

#define LEN 10

/*------------------------------------------------------
* Function Name - sort_pointer_array
*
* Function Purpose - sort a pointers array by the pointed values
* Parameters –  None
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/
void sort_pointer_array(int** ptrs, int* ints) {
    int i=0,j=0;
    int *tmp = NULL;
    for(;i<LEN-1;i++){
        for(j=i+1;j<LEN;j++){
            if(*(ptrs[i]) > *(ptrs[j])) {
                tmp = ptrs[i];
                ptrs[i] = ptrs[j];
                ptrs[j] = tmp;
            }
        }
    }
}

/*------------------------------------------------------
* Function Name - print_array_by_pointers
*
* Function Purpose - show the pointed values in array
* Parameters –  None
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/
void print_array_by_pointers(int** ptrs, int size) {
    for(int i=0;i<size;i++) printf("%d  ",*(ptrs[i]));
    printf("\n");
}

int main(){
    int ints[LEN];
    int* ptrs[LEN];

    printf("Please enter %d integers:\n", LEN);
    for(int i=0;i<LEN;i++) {
        if(scanf(" %d", &ints[i])!=1) {
            printf("ERROR!");
            return -1;
        }
        ptrs[i] = &ints[i];
    }

    printf("-- BEFORE: --\n");
    print_array_by_pointers(ptrs,LEN);
    sort_pointer_array(ptrs,ints);
    printf("-- AFTER: --\n");
    print_array_by_pointers(ptrs,LEN);

    return 0;
}