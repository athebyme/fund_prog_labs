#include <stdio.h>
#include "lab4.h"
long inRange(long left, int right, int number) {
    long a = (right - number) & 2147483648;
    long b = (number - left) & 2147483648;
    return a + b;
}

int lab4(){
    int x = 127;
    int x1 = ~((x&0xAAAFFF)-(x|7));
    int x2 = (((x|0xFF)-128)+x)^0x8;

    printf("x: %d \nx1: %d\nx2: %d\n", x,x1,x2);
    printf("Left : ");
    scanf("%d", &x1);
    printf("Right : ");
    scanf("%d", &x2);

    printf("Enter num: ");
    scanf("%d", &x);

    if(!inRange(x1, x2, x)){
        printf("%s", "Num IS in the interval");
    }else{
        printf("%s", "! Num IS NOT in the interval !");
    }
    return 0;
}