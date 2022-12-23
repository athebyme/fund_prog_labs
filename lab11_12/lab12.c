#include <stdio.h>
#include "lab12.h"
int lab12(int argc, char** argv){
    // lab 12

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    char line[256];
    int line_number = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        line_number++;
        if (line_number % 2 == 0) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}