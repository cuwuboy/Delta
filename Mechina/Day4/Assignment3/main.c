/*------------------------------------------------------
* Filename: main.c
* Description: Remove Dup
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

/*------------------------------------------------------
* Function Name - RemoveDup1
*
* Function Purpose - remove duplicates in integers array
* Parameters –  int* arr - original array
*               int size - original array size
*               int* new_size - pointer to new array size (to change its value)
*
* Return Values - int* pointer to the dynamically allocated array
*
* Author - Yoav Malka
-------------------------------------------------------*/

int* RemoveDup1(int* arr, int size, int* new_size) {
    int* new_arr = (int*)malloc(size*sizeof(int));
    if(new_arr == NULL) {
        printf("Error!\n");
        return NULL;
    }

    new_arr[0] = arr[0];
    *new_size = 1;

    for(int i = 1; i < size; i++){
        if(arr[i] != arr[i-1]) {
            new_arr[(*new_size)] = arr[i];
            (*new_size)++;
        }
    }

    return new_arr;
}

/*------------------------------------------------------
* Function Name - RemoveDup2
*
* Function Purpose - remove duplicates in integers array
* Parameters –  int* arr - original array
*               int size - original array size
*               int* new_arr - pointer to the new array (to change its values)
*
* Return Values - int the new array size
*
* Author - Yoav Malka
-------------------------------------------------------*/

int RemoveDup2(int* arr, int size, int* new_arr) {
    new_arr = (int*)malloc(size*sizeof(int));
    if(new_arr == NULL) {
        printf("Error!\n");
        return -1;
    }

    (new_arr)[0] = arr[0];
    int new_size = 1;

    for(int i = 1; i < size; i++){
        if(arr[i] != arr[i-1]) {
            (new_arr)[new_size] = arr[i];
            new_size++;
        }
    }

    return new_size;
}

/*------------------------------------------------------
* Function Name - RemoveDup3
*
* Function Purpose - remove duplicates in integers array
* Parameters –  int* arr - original array
*               int size - original array size
*               int* new_size - pointer to new array size (to change its value)
*               int* new_array - pointer to the new array (to change its values)
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/

void RemoveDup3(int* arr, int size, int* new_arr, int* new_size) {
    new_arr = (int*)malloc(size*sizeof(int));
    if(new_arr == NULL) {
        printf("Error!\n");
        return;
    }

    (new_arr)[0] = arr[0];
    (*new_size) = 1;
    for(int i = 1; i < size; i++){
        if(arr[i] != arr[i-1]) {
            printf("%d",arr[i]);
            (new_arr)[(*new_size)] = arr[i];
            (*new_size)++;
        }
        printf("\n");
    }
}

/*------------------------------------------------------
* Function Name - PrintArr
*
* Function Purpose - display both arrays
* Parameters –  int* arr - original array
*               int size - original array size
*               int* new_size - pointer to new array size (to change its value)
*               int* new_array - pointer to the new array (to change its values)
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/

void PrintArr(int* arr, int* new_arr, int size, int new_size) {
    printf("Original Array (%d cells): ",size);
    for(int i = 0;i < size;i++)
        printf("%d  ", arr[i]);

    printf("\nNew Array (%d cells): ",new_size);
    for(int i = 0;i < new_size;i++)
        printf("%d  ", new_arr[i]);
    printf("\n");
}

int main(){
    //given arr is sorted;
    int size = SIZE, new_size = 0;
    int arr[SIZE] = {1,1,1,2,3,3,4,4,4};

    int* new_arr;

    new_arr = RemoveDup1(arr, size, &new_size);
    PrintArr(arr,new_arr,size,new_size);
    free(new_arr);

    printf("\n---------\n\n");
    new_size = RemoveDup2(arr, size, new_arr);
    PrintArr(arr,new_arr,size,new_size);
    free(new_arr);

    printf("\n---------\n\n");
    RemoveDup3(arr, size, new_arr, &new_size);
    PrintArr(arr,new_arr,size,new_size);
    free(new_arr);

    printf("\n---------\n\n");
    RemoveDup3(arr, size, new_arr, &new_size);
    PrintArr(arr,new_arr,size,new_size);
    free(new_arr);
    int* arr_ver_4 = (int*)malloc(SIZE*sizeof(int));
    arr_ver_4[0] = 1;
    arr_ver_4[1] = 1;
    arr_ver_4[2] = 1;
    arr_ver_4[3] = 2;
    arr_ver_4[4] = 3;
    arr_ver_4[5] = 3;
    arr_ver_4[6] = 4;
    arr_ver_4[7] = 4;
    arr_ver_4[8] = 4;
    RemoveDup3(arr_ver_4, size, new_arr, &new_size);
    PrintArr(arr_ver_4,new_arr,size,new_size);
    free(new_arr);
    free(arr_ver_4);

    return 0;
}