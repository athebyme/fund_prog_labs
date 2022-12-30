#include "lab7.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>

enum Weekday{
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};

int lab7_a() {
    printf("%d", July);
    return 0;
}


//-----------------------------


struct Square{
    double side;
};

double square_circle_rad(struct Square* sq){
    return sq->side / sqrt(2);
}

int lab7_b(){
    float side;
    printf("%s","Enter square side: ");
    scanf("%f", &side);
    struct Square sq = {side};
    printf("Radius of the circle around this square is: %f", square_circle_rad(&sq));

    return 0;
}

//-----------------------------

struct laserPrinter{
    int8_t isReady: 1;
    int8_t lowToner: 1;
    int8_t printerDrumOK: 1;
    int8_t noPaper: 1;
};

union Bit{
    unsigned int value;
    struct laserPrinter bitfield;
};

int lab7_c(){
    union Bit c;
    scanf("%x", &c.value);
    printf("isReady: %d\nlowToner: %d\nprinterDrumOK: %d\nNo paper: %d", c.bitfield.isReady, c.bitfield.lowToner, c.bitfield.noPaper, c.bitfield.printerDrumOK);
    return 0;
}