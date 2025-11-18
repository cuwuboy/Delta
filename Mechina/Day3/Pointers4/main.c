/*------------------------------------------------------
* Filename: main.c
* Description: Median calculation and memory allocation
* Author: Yoav Malka
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 20
#define FACTOR 2

int main(){
    //part a
    int *arr = (int*)malloc(DEFAULT_SIZE*sizeof(int));
    int size = 0, ceiling = DEFAULT_SIZE;

    printf("Enter as many numbers as you want :)\n");
    int val = 0;
    while(1) {
        if(size>=ceiling) {
            ceiling *= FACTOR;
            int *arr_copy = realloc(arr, ceiling*sizeof(int));
            if(arr_copy == NULL){
                printf("Error! reached max of %d dynamically allocated cells.\n",size);
                free(arr);
                size--;
                break;
            }
            arr = arr_copy;
        }

        printf("\n# ");
        if(scanf("%d",&arr[size]) != 1) {
            printf("End of input loop.");
            break;
        }
        size++;
    }
    printf("All values scanned:\n");
    for(int i=0;i<size;i++) printf("#%d : %d\n",i,arr[i]);

    //part b
    int i=0,j=0;
    for(;i<size-1;i++) {
        for(j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                int tmp=arr[j];
                arr[j]=arr[i];
                arr[i]=tmp;
            }
        }
    }
    if(size%2==0) printf("Median = %.1f",(arr[size/2-1]+arr[size/2])/2);
    else printf("Median = %d",arr[size/2]);

    free(arr);

    return 0;
}