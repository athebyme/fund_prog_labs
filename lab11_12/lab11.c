#include "lab11.h"
#include <math.h>

double square_area(Square s) {
    double side = sqrt(pow(s.p2.x - s.p1.x, 2) + pow(s.p2.y - s.p1.y, 2));
    return side * side;
}

double square_perimeter(Square s) {
    double side = sqrt(pow(s.p2.x - s.p1.x, 2) + pow(s.p2.y - s.p1.y, 2));
    return side * 4;
}

int lab11(){
    Square s;
    printf("Enter x and y coordinates for point 1: ");
    scanf("%d %d", &s.p1.x, &s.p1.y);
    printf("Enter x and y coordinates for point 2: ");
    scanf("%d %d", &s.p2.x, &s.p2.y);
    printf("Enter x and y coordinates for point 3: ");
    scanf("%d %d", &s.p3.x, &s.p3.y);
    printf("Enter x and y coordinates for point 4: ");
    scanf("%d %d", &s.p4.x, &s.p4.y);

    double area = square_area(s);
    double perimeter = square_perimeter(s);
    printf("Area: %f\n", area);
    printf("Perimeter: %f\n", perimeter);
}
