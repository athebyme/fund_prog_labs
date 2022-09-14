#include "lab2.h"
#include <stdio.h>
#include <math.h>
const int C_ITERS = 10;
const int C_ITERS_PI = 20;

long int calculate_fact(int n){
    long int res = 1;
    for(int i = 1; i < n; i++) res += res*i;
    return res;
}
float calculate_degree(float x, int degree){
    float res = 1;
    for(int i=0; i < degree; i++) res *= x;
    return res;
}

float cosine(float x){
    float r_cos = 1;
    int isPlus = 0; // если 0 то +, если 1 то -
    for(int i = 2; i <= C_ITERS; i+=2) {
        if (isPlus == 0) {
            r_cos +=  calculate_degree(x, i) / (float) calculate_fact(i);
            isPlus = 1;
        } else {
            r_cos -= calculate_degree(x, i) / (float) calculate_fact(i);
            isPlus = 0;
        }
    }
    return r_cos;
}

float sine(float x){
    float r_sin = x;
    int isPlus = 1; // если 0 то +, если 1 то -
    for(int i = 2; i <= C_ITERS; i+=2) {
        if (isPlus == 0) {
            r_sin +=  calculate_degree(x, i) / (float) calculate_fact(i);
            isPlus = 1;
        } else {
            r_sin -= calculate_degree(x, i) / (float) calculate_fact(i);
            isPlus = 0;
        }
    }
    return r_sin;
}

int lab2(){
    printf("\n-----------------\n\n\nLab 2\n");
    float a, z1, z2, z3;
    printf("Enter real num: ");
    scanf("%f", &a);
    float rads = M_PI/180 * a;
    z1 = cosf(a) + sinf(a) + cosf(3*a) + sinf(3*a);
    printf("res 1: %.3f", z1);
    z3 = cosine(rads) + sine(rads) + cosine(3*rads) + sine(3*rads);
    printf("\nown cos/sin res 1: %.3f\n\n", z1);
    z2 = 2 * sqrtf(2) * cosf(a) * sinf(M_PI/4 + 2 * a);
    printf("\nres 2: %.3f", z2);
    return 0;
}
