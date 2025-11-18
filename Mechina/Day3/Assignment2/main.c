/*------------------------------------------------------
* Filename: main.c
* Description: Assignment 2 - Encryption in C
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>

#define MESSAGE_LEN 26
#define BACKWARDS_NUM_SHIFTS 5
#define FORWARDS_NUM_SHIFTS 4
#define MULTIPLIED_VALUE 7
#define INCREASING_VALUE 5

/*------------------------------------------------------
* Function Name - switch_halves
*
* Function Purpose - swap the halves of the given array
* Parameters –  int* array - given encoded array
*               int size   - the given array size
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/
void switch_halves(int *array, const int size) {
    int i, tmp;
    int half = size/2;

    for(i=0;i<size/2;i++){
        tmp = array[i];
        array[i] = array[i+half];
        array[i+half] = tmp;
    }
}

/*------------------------------------------------------
* Function Name - decrease_by_previous
*
* Function Purpose - decrease the values of of each cell by their previous cell
* Parameters –  int* array - given encoded array
*               int size   - the given array size
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/
void decrease_by_previous(int *array, int size) {
    int i;
    for(i=1;i<size;i++){
        array[i] -= array[i-1];
    }
}

/*------------------------------------------------------
* Function Name - circular_shift_forwards_once
*
* Function Purpose - circular shift forwards the array values once
* Parameters –  int* array - given encoded array
*               int size   - the given array size
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/
void circular_shift_forwards_once(int *array, int size) {
    int i;
    int last_value = array[size-1];
    for(i=size-1;i>0;i--)
        array[i] = array[i-1];
    array[0] = last_value;
}

/*------------------------------------------------------
* Function Name - divide_even_indexes_cells
*
* Function Purpose - divide all cells values in even indexes by a specific value
* Parameters –  int* array - given encoded array
*               int size   - the given array size
*               int num    - the value to divide all array cells values with

* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/
void divide_even_indexes_cells(int *array, int size, int num) {
    int i;
    for(i=0;i<size;i+=2)
        array[i] /= num;
}

/*------------------------------------------------------
* Function Name - circular_shift_backwards_once
*
* Function Purpose - circular shift backwards the array values once
* Parameters –  int* array - given encoded array
*               int size   - the given array size
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/
void circular_shift_backwards_once(int *array, int size) {
    int i;
    int first_value = array[0];
    for(i=0;i<size-1;i++)
        array[i] = array[i+1];
    array[size-1] = first_value;
}

/*------------------------------------------------------
* Function Name - decrease_from_all
*
* Function Purpose - decrease from all arrays cells values a specific value
* Parameters –  int* array - given encoded array
*               int size   - the given array size
*               int num    - the value to decrease from all array cells values

* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/
void decrease_from_all(int *array, int size, int num) {
    int i;
    for(i=0;i<size;i++)
        array[i] -= num;
}

int main() {
    int encoded_message[] = {921,842,884,953,834,837,914,915,936,948,864,780,542,116,928,925,372,365,911,909,937,959,945,940,891,886};

    switch_halves(encoded_message, MESSAGE_LEN);

    decrease_by_previous(encoded_message, MESSAGE_LEN);

    for(int i=0;i<BACKWARDS_NUM_SHIFTS;i++) circular_shift_forwards_once(encoded_message, MESSAGE_LEN);
    
    divide_even_indexes_cells(encoded_message, MESSAGE_LEN, MULTIPLIED_VALUE);

    for(int i=0;i<FORWARDS_NUM_SHIFTS;i++) circular_shift_backwards_once(encoded_message, MESSAGE_LEN);

    decrease_from_all(encoded_message, MESSAGE_LEN, INCREASING_VALUE);

    for(int i=0;i<MESSAGE_LEN;i++)
        printf("%c",encoded_message[i]);

    return 0;
}