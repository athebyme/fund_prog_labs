#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lab1(){
    printf("\n-----------------\n");
    printf("\n\n������������ ������ 1\n");
    int _int;
    float _f;
    printf("������� ����� �����: ");
    scanf("%d", &_int);
    printf("�� ����� �����: %d",_int);
    printf("\n������� ������������ �����: ");
    scanf("%f",&_f);
    printf("�� ����� ����� %.2f", _f);
    return 0;
}

int lab2(){
    printf("\n-----------------\n");
    printf("\n\n������������ ������ 2\n");
    float a;
    printf("������� �����: ");
    scanf("%f", &a);
    float z1, z2;
    z1 = cosf(a) + sinf(a) + cosf(3*a) + sinf(3*a);
    printf("res z1: %f", z1);
    z2 = 2 * sqrtf(2) * cosf(a) * sinf(M_PI/4 + 2 * a);
    printf("\nres z2: %f", z2);
    return 0;
}
int main() {
    system("chcp 1251");
    lab1();
    lab2();
}
