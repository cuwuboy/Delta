/*------------------------------------------------------
* Filename: b.c
* Description: Turn a string number into a number+36
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>

#define MAXSIZE 26

/*------------------------------------------------------
* Function Name - string_to_integer
*
* Function Purpose - return integer that is shown in given string
* Parameters –  char *str - given string to convert to integer
*
* Return Values - int num - the integer that is shown in given string str
*
* Author - Yoav Malka
-------------------------------------------------------*/
int string_to_integer(char *str) {
    int i=0;
    int num=0;
    while(str[i]!='\0' && i<MAXSIZE) {
        if(!(str[i]>='0' && str[i]<='9')){
            printf("Not a number");
            return -1;
        }

        num *= 10;
        num += str[i] - 48;
        i++;
    }
    return num;
}

int main() {
    char str[MAXSIZE];
    printf("Enter string number:\n");
    if(scanf("%s", &str) != 1) {
        printf("Bad input :(");
        return -1;
    }
    int res = string_to_integer(str);

    if(res == -1)
        return -1;

    res += 36;
    printf("\nResult = %d\n", res);
    return 0;
}