/*------------------------------------------------------
* Filename: main.c
* Description: Median & Memory allocation
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

/*------------------------------------------------------
* Function Name - display
*
* Function Purpose - displays the integer series
* Parameters –  int* ptr - pointer to a series of integers
*               int size - the size of the integer series
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/

void display(int* ptr, int size) {
    if(ptr == NULL || size == 0) {
        printf("Error!");
        return;
    }

    printf("All the values you entered:\n");
    int i = 0;
    for(;i<size;i++){
        printf("[%d] = %d\n", i, ptr[i]);
    }
}

/*------------------------------------------------------
* Function Name - display
*
* Function Purpose - sorts the integer series
* Parameters –  int* ptr - pointer to a series of integers
*               int size - the size of the integer series
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/

void sort(int* ptr, int size){
    if(ptr == NULL || size == 0) {
        printf("Error!");
        return;
    }

    int i=0, j=0,tmp=0;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(ptr[i]>ptr[j]) {
                tmp = ptr[j];
                ptr[j] = ptr[i];
                ptr[i] = tmp;
            }
        }
    }
}

/*------------------------------------------------------
* Function Name - display
*
* Function Purpose - displays the median of the integer series
* Parameters –  int* ptr - pointer to a series of integers
*               int size - the size of the integer series
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/

void print_median(int* ptr, int size) {
    if(ptr == NULL || size == 0) {
        printf("Error!");
        return;
    }

    printf("The madien is: ");
    if(size % 2 == 0)
        printf("%.1f", (ptr[size/2] + ptr[size/2 - 1])/2);
    else
        printf("%d", ptr[size/2]);
    printf(".\n");
}

int main(){
    int* ptr = (int*)malloc(MAX_SIZE*sizeof(int));
    if(ptr == NULL){
        printf("Error :(");
        return -1;
    }

    printf("Enter as many values (integers) as you want.\n");
    printf("When finished enter anything that isnt an integer:\n");

    int size = 0;
    while(1) {
        if(size >= MAX_SIZE) {
            int* ptr_copy = (int*)realloc(ptr, ((size % MAX_SIZE) + 1)*sizeof(int));
            if(ptr_copy == NULL) {
                printf("Ends loop after scanning %d values. Not enough space in memory.\n", size);
                break;
            }
        }
        printf("# ");
        if(scanf("%d",&ptr[size]) != 1) {
            printf("Closes loop.\n");
            break;
        }
        size++;
    }
    printf("\n----------\n\n");
    display(ptr,size);
    printf("\n");
    sort(ptr, size);
    print_median(ptr, size);

    free(ptr);
    return 0;
}