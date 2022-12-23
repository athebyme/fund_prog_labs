#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab8.h"

int lab8_a(){
    char *str1 = malloc(100 * sizeof(char));
    strcpy(str1, "Hello");
    char *str2 = "World!";
    int num_chars = 3;
    int len1 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }
    int new_size = len1 + num_chars + 1;

    str1 = realloc(str1, new_size * sizeof(char));
    int i;
    for (i = 0; i < num_chars; i++) {
        str1[len1 + i] = str2[i];
    }
    str1[len1 + i] = '\0';

    printf("Concatenated string: %s\n", str1);

    free(str1);

    return 0;
}


int compare_first_n_chars(char *str1, char *str2, int n) {
    int result = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            result = str1[i] - str2[i];
            break;
        }
    }
    return result;
}

int lab8_b(){
    char *str1 = "Hello";
    char *str2 = "Hello";
    int n = 3;

    int result = compare_first_n_chars(str1, str2, n);
    if (result == 0) {
        printf("The strings are equal.\n");
    } else if (result > 0) {
        printf("String 1 is greater than string 2.\n");
    } else {
        printf("String 2 is greater than string 1.\n");
    }

    return 0;
}

int lab8_c(){
    char *str1 = malloc(100 * sizeof(char));
    char *str2 = malloc(100 * sizeof(char));
    int num_chars;


    printf("Enter the first string: ");
    fgets(str1,100,stdin);

    printf("Enter the second string: ");
    fgets(str2,100,stdin);

    printf("Enter the number of characters to copy: ");
    scanf("%d", &num_chars);

    int len1 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }

    str1 = realloc(str1, (num_chars + len1 + 1) * sizeof (char));

    int i;
    for(i = 0; i < num_chars; ++i){
        str1[len1 + i - 1] = str2[i];
    }

    str1[len1 + num_chars - 1] = '\0';

    printf("Copied string: %s\n", str1);

    return 0;
}

int lab8_d(){
    char *str = malloc(100 * sizeof(char));
    char c;
    printf("Enter line: ");
    fgets(str,100,stdin);
    printf("Enter char to find: ");
    scanf("%c", &c);

    int index = -1;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("The character '%c' was found at index %d.\n", c, index);
    } else {
        printf("The character '%c' was not found in the string.\n", c);
    }

    return 0;
}

int lab8_e(){
    char *str = malloc(100 * sizeof (char));
    char *chars_to_search = malloc(100 * sizeof (char));

    printf("Enter the string: ");
    fgets(str,100,stdin);
    printf("Enter the chars: ");
    fgets(chars_to_search,100,stdin);

    int index = -1;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        int j;
        for (j = 0; chars_to_search[j] != '\0'; j++) {
            if (str[i] == chars_to_search[j]) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            break;
        }
    }

    if (index != -1) {
        printf("One of the characters '%s' was found at index %d.\n", chars_to_search, index);
    } else {
        printf("None of the characters '%s' were found in the string.\n", chars_to_search);
    }

    return 0;
}