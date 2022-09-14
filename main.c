#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lab1(){
    printf("\n-----------------\n\n\nLab 1\n");
    int _int;
    float _f;
    printf("Enter int num: ");
    scanf("%d", &_int);
    printf("You entered %d num",_int);
    printf("\nEnter float num: ");
    scanf("%f",&_f);
    printf("You entered %.2f num", _f);
    return 0;
}

int lab2(){
    printf("\n-----------------\n\n\nLab 2\n");
    float a, z1, z2;
    printf("Enter float num: ");
    scanf("%f", &a);
    z1 = cosf(a) + sinf(a) + cosf(3*a) + sinf(3*a);
    printf("res 1: %f", z1);
    z2 = 2 * sqrtf(2) * cosf(a) * sinf(M_PI/4 + 2 * a);
    printf("\nres 2: %f", z2);
    return 0;
}
int main() {
    system("chcp 1251");
    lab1();
    lab2();
}
