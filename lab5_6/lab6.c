#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"
int lab6(){
    float a [4];
    for(int i =0; i<4;++i){
        float t;
        scanf("%f",&t);
        *(a+i) = t;
    }
    for(int i =0; i<4;++i){
        printf("%.2f ", *(a+i));
    }


    printf("\nTask2\n");
    float *b = calloc(4, sizeof(float));
    if(b!=NULL){
        for(int i =0; i<4;++i){
            float t;
            scanf("%f",&t);
            *(a+i) = t;
        }
        for(int i =0; i<4;++i){
            printf("%.2f ", *(a+i));
        }
    }

    return 0;
}