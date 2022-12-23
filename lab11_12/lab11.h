#ifndef UNTITLED_LAB11_H
#define UNTITLED_LAB11_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point p1;
    Point p2;
    Point p3;
    Point p4;
} Square;

double square_area(Square* s);
double square_perimeter(Square* s);
int lab11();
#endif