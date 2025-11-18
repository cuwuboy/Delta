/*------------------------------------------------------
* Filename: main.c
* Description: Detect if a series represented by an array is
increasing/decreasing/constant/messed up
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>

#define SIZE 15

int main(){
    int arr[SIZE];
    
    int num_incs = 0 , num_decs = 0;
    int i=0;

    printf("Please enter %d values:\n",SIZE);

    for(i=0; i<SIZE; i++) {
        if (scanf("%d", &arr[i]) == 1) {}
        else {
            printf("Invalid input! :(");
            return -1;
        }

        if(i>0){
            if(arr[i-1]<arr[i]) num_incs++;
            if(arr[i-1]>arr[i]) num_decs++;
        }
    }
    if(num_incs == SIZE-1)
        printf("The array is increasing");
    else if(num_decs == SIZE-1)
        printf("The array is decreasing");
    else if (num_decs==0 && num_incs==0)
        printf("The array is constant");
    else
        printf("The array is messed up");
    
    return 0;
}