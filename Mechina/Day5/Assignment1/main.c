/*------------------------------------------------------
* Filename: main.c
* Description: Dynamic String Scanning and Secure C
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

/*------------------------------------------------------
* Function Name - dyn_Scanf
*
* Function Purpose - dynamically scans a string
* Parameters –  None
*
* Return Values - char* - ptr to dynamic allocation of string
*
* Author - Yoav Malka
-------------------------------------------------------*/

char* dyn_scanf(void) {
    //checked define value because someone might have changed it
    if(MAX_SIZE <= 0 || MAX_SIZE >= (INT_MAX - 1)) {
        printf_s("Problematic initial info size.\n");
        return 0;
    }

    size_t norm_size = MAX_SIZE + 1;
    char* ptr = (char*) malloc(norm_size * sizeof(char));
    
    //checked pointer value if theres an error
    if(ptr == NULL) {
        printf_s("Error in declaring initial space.\n");
        return 0;
    }

    //initialize cells
    for(int i = 0; i >= 0 && i < norm_size; i++){
        ptr[i]='\0';
    }
    
    //scan implementation
    register int ch;
    register char* string_reg;
    string_reg = ptr;

    while(--norm_size > 0 && (ch = getc(stdin)) != EOF)
    {
        if((*string_reg++ = ch) == '\n')
            break;
    }
    *string_reg = '\0';

    if(ch != EOF || string_reg != ptr)
        return ptr;

    return NULL;
}

/*------------------------------------------------------
* Function Name - prints_string
*
* Function Purpose - prints safely a dynamically scanned string
* Parameters –  char* - ptr to dynamically allocated string
*
* Return Values - None
*
* Author - Yoav Malka
-------------------------------------------------------*/

void prints_string(char* ptr){
    //checked define value because someone might have changed it
    if(ptr == NULL) {
        printf_s("Error in declaring initial space.\n");
        return;
    }

    //checking numeric values
    if(MAX_SIZE <= 0 && MAX_SIZE > (INT_MAX - 1)) {
        printf_s("Error in maximum length value.");
        return;
    }

    //usign printf_s to securely print the string slowly
    for(int i = 0; i >= 0 && i < (MAX_SIZE + 1); i++){
        printf_s("%c", ptr[i]);
    }
}

int main() {
    //print safely instructions and dynamically scan a string usign a func
    printf_s("Enter a string:\n");
    char* ptr = dyn_scanf();
    
    if(ptr != NULL) {
        //print safely instructions and string usign helper func
        printf_s("\nThe detected string:\n");
        prints_string(ptr);

        //free allocated mem
        free(ptr);
    }
    else {
        printf_s("An error occured...\n");
    }

    return 0;
}