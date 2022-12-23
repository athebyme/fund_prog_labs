#include "lab2.h"
#include <stdio.h>
#include <math.h>
const int C_ITERS = 10;

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
    x = fmod(M_PI/180 * x, M_PI*2);
    float r_cos = 1;
    int isPlus = 1; // если 0 то +, если 1 то -
    for(int i = 2; i <= C_ITERS; i+=2) {
        if (isPlus == 0) {
            r_cos +=  pow(x, i) / (float) calculate_fact(i);
            isPlus = 1;
        } else {
            r_cos -= pow(x, i) / (float) calculate_fact(i);
            isPlus = 0;
        }
    }
    return r_cos;
}

float sine(float x){
    x = fmod(M_PI/180 * x, M_PI*2);
    float r_sin = x;
    int isPlus = 1; // если 0 то +, если 1 то -
    for(int i = 3; i <= C_ITERS; i+=2) {
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


float z1_math(float a){
    float z =(float) cosf(a) + sinf(a) + cosf(3*a) + sinf(3*a);
    return z;
}
float z2_math(float a){
    float z = 2 * sqrtf(2) * cosf(a) * sinf(M_PI/4 + 2 * a);
    return z;
}
float own_z1(float a){
    float z = cosine(a) + sine(a) + cosine(3*a) + sine(3*a);
    return z;
}

int lab2(){
    printf("\n-----------------\n\n\nLab 2\n");
    float a, z1, z2, z3;
    printf("Enter real num: ");
    scanf("%f", &a);
    printf("sin: %f\ncos: %f\n", sine(a), cosine(a));
    z1 = z1_math(a);
    z2 = own_z1(a);
    z3 = z2_math(a);
    printf("res_math_1: %f\nres_own cos/sin: %f\nres_math_2: %f", z1,z2,z3);
    return 0;
}
