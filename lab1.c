#include "lab1.h"
#include <stdio.h>

int lab1(){
    printf("\n-----------------\n\n\nLab 1\n");
    int _int;
    float _f;
    printf("Enter int num: ");
    scanf("%d", &_int);
    printf("You entered %d num",_int);

    printf("\nEnter real num: ");
    scanf("%f",&_f);
    printf("You entered %.2f num", _f);
    return 0;
}