#include <stdio.h>

#define SIZE 15

int main(){
    int arr[SIZE];
    
    int num_incs, num_decs = 0;

    int i=0;
    printf("Please enter %d values:\n",SIZE);
    for(i=0;i<SIZE;i++) {
        scanf("%d",&arr[i]);

        if(i>0){
            if(arr[i-1]<arr[i]) num_incs++;
            if(arr[i-1]>arr[i]) num_decs++;
        }
    }
    if(num_incs == SIZE-1) printf("The array is increasing");
    else if(num_decs == SIZE-1) printf("The array is decreasing");
    else if (num_decs==0 && num_incs==0) printf("The array is constant");
    else printf("The array is messed up");
    
    return 0;
}