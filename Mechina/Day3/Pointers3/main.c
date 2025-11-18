/*------------------------------------------------------
* Filename: main.c
* Description: Const pointers
* Author: Yoav Malka
-------------------------------------------------------*/
#include <stdio.h>

int main(){
    const int channel = 5;
    printf("Chanel no. %d\n", channel);

    printf("Please enter new channel number:\n");
    int new_channel;
    if(scanf("%d",&new_channel)!=1){
        printf("error :(");
        return -1;
    }

    int* const ptr = &channel;
    *ptr = new_channel;

    printf("New channel is no. %d",channel);

    return 0;
}