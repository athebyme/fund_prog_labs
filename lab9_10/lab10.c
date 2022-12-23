#include <math.h>
#include <malloc.h>
#include <stdio.h>
#include "lab10.h"
#define SQR(x) ((x) * (x))

typedef struct {
    double x;
    double y;
} Point;

double** createDistanceArray(Point* points, int n) {
    double** distances = (double**) malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        distances[i] = (double*) malloc((n - 1) * sizeof(double));
    }

    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double dx = points[i].x - points[j].x;
                double dy = points[i].y - points[j].y;
                distances[i][k++] = sqrt(SQR(dx) + SQR(dy));
            }
        }
    }

    return distances;
}
int lab10(){
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);

    Point* points = (Point*) malloc(n * sizeof(Point));

    for (int i = 0; i < n; i++) {
        printf("Enter coordinates of point %d: ", i + 1);
        scanf("%lf%lf", &points[i].x, &points[i].y);
    }

    double** distances = createDistanceArray(points, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            printf("%.2f ", distances[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(distances[i]);
    }
    free(distances);
    free(points);

    return 0;
}