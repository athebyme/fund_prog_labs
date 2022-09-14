#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lab1(){
    system("chcp 1251");
    printf("\n-----------------\n");
    printf("\n\nЛабораторная работа 1\n");
    int _int;
    float _f;
    printf("Введите целое число: ");
    scanf("%d", &_int);
    printf("Вы ввели число: %d",_int);
    printf("\nВведите вещественное число: ");
    scanf("%f",&_f);
    printf("Вы ввели число %.2f", _f);
    return 0;
}

int lab2(){
    system("chcp 1251");
    printf("\n-----------------\n");
    printf("\n\nLab 2\n");
    float a;
    printf("Введите вещественное число: ");
    scanf("%f", &a);
    float z1, z2;
    z1 = cosf(a) + sinf(a) + cosf(3*a) + sinf(3*a);
    printf("res z1: %f", z1);
    z2 = 2 * sqrtf(2) * cosf(a) * sinf(M_PI/4 + 2 * a);
    printf("\nres z2: %f", z2);
    return 0;
}
int main() {
    lab1();
    lab2();
}
