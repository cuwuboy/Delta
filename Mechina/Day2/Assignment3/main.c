/*------------------------------------------------------
* Filename: main.c
* Description: Calculate prices of packages
* Author: Yoav Malka
-------------------------------------------------------*/

#include <stdio.h>

#define CONST_DELIVERY_PRICE 5.5
#define DELIVERY_KG_BONUS 11
#define DELIVERY_SCM_BONUS 0.03
#define DELIVERY_SIZE_BONUS 0.01

int main() {
    int width, length, weight;
    printf("Enter package width (mm): ");
    scanf("%d", &width);
    printf("\n");

    printf("Enter package length (mm): ");
    scanf("%d", &length);
    printf("\n");

    printf("Enter package width (g): ");
    scanf("%d", &weight);
    printf("\n");

    float width_in_cm = (float)width/10;
    float length_in_cm = (float)length/10;
    float weight_in_kg = (float)weight/1000;
    float size_in_scm = width_in_cm*length_in_cm;

    printf("The size of the 2D package %.2f (cm^2)\n", size_in_scm);
    printf("The wight of the package %.3f (kg)\n", weight_in_kg);

    float price = CONST_DELIVERY_PRICE + DELIVERY_KG_BONUS*weight_in_kg + 
        DELIVERY_SCM_BONUS*size_in_scm + DELIVERY_SIZE_BONUS*(size_in_scm/weight_in_kg);

    printf("The delivery price is %.2f nis\n", price);

    return 0;
}