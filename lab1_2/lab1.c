#include "lab1.h"
#include <stdio.h>
#include <stdint.h>

void sout_(char *text [], char format [3]){
    printf(format, text);
}

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

int extra_task(int variant){
    int x = INT32_MAX + variant;
    //sout(x, "%d");
    return 0;
}