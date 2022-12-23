#include <stdio.h>
#include <stdlib.h>
#include "lab5.h"
int task1(){
    int N1, N2;
    printf("%s","Enter rows num: ");
    scanf("%d", &N1);
    printf("%s","Enter cols num: ");
    scanf("%d", &N2);

    printf("%s", "\n");


    int m [N1][N2];
    for(int i = 0; i < N2; i++){
        printf("Enter %d'th num :", i+1);
        scanf("%d", &m[0][i]);
        m[1][i] = i + 1;
    }
    for(int i = 0; i < N1; i++){
        for(int j = 0; j < N2; j++){
            printf("%d | ", m[i][j]);
        }
        printf("%c",'\n');
    }

    return 0;
}
int print(const int *m, int rows, int cols){
    for(int i = 0; i < rows; i++){
        printf("|%c",' ');
        for(int j = 0; j < cols; j++){
            printf("%d ",*(m + i*cols + j));
        }
        printf("|%c", '\n');
    }
    return 0;
}
int init_matrix (int * m, int rows, int cols){
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            int t;
            scanf(" %d", &t);
            *(m + y*cols + x) = t;
        }
    }
    return 0;
}



int make_mult(int * m1, int * m2, int rows1, int cols1, int rows2, int cols2, int *res){
    int z;
    if(cols1 == cols2 && rows1 == rows2) {
        z = cols1;
    }else{
        z = cols1 - 1;
    }
    for(int y = 0; y < rows1; y++) {
        for (int k = 0; k < cols2; k++) {
            int sum = 0;
            for (int x = 0; x < cols1; x++) {
                sum += (*m1 + y * cols1 + x) * (*m2 + x * cols2 + k);
            }
            *(res + y*(z) + k) = sum;
        }
    }
    return 0;
}

int task2(){
    int rows1, cols1;
    printf("Enter sizes of 1 matrix\n");
    scanf(" %d", &rows1);
    scanf(" %d", &cols1);
    int *m1 = calloc(rows1*cols1,sizeof(int));
    printf("Enter 1 matrix\n");
    init_matrix((int *) m1, rows1, cols1);
    printf("%s", "\n");

    printf("Enter sizes of 2 matrix\n");
    int rows2, cols2;
    scanf("%d", &rows2);
    scanf("%d", &cols2);
    int *m2 = calloc(rows2*cols2,sizeof(int));
    printf("Enter 1 matrix\n");
    init_matrix((int *) m2, rows2, cols2);

    if(cols1 == rows2){
        int *res = calloc(rows1*cols2, sizeof(int));
        make_mult((int *) m1, (int *) m2, rows1, cols1, rows2, cols2, res);
        printf("The result\n");
        print(res,rows1,cols2);
    }else{
        printf("Error. Not Correct Matrix");
        return 0;
    }



    return 0;
}

int lab5(){
    //task1();
    task2();
    return 0;
}