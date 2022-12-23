#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "lab9.h"

int lab9_a(){
    const float rate_included_minutes = 499;
    float rate_rub;
    printf("Enter rate cost in rubs: ");
    scanf("%f", &rate_rub);

    float oneMinuteIncluded = rate_rub / rate_included_minutes;
    const double COEFF_OVER_RATE = oneMinuteIncluded * 1.3;

    int minutes_spoken;
    printf("Enter how many minutes was spoken: ");
    scanf("%d", &minutes_spoken);

    if(minutes_spoken - rate_included_minutes <= 0){
        printf("You have not spoken over your rate. You have to pay %.1f rubs", rate_rub);
    }else{
        printf("You have spoken %.1f minutes over rate\nYou have to overpay %.1f rubs. Overpaying rate for 1 minute: %.1f", minutes_spoken - rate_included_minutes, (minutes_spoken - rate_included_minutes)*COEFF_OVER_RATE, COEFF_OVER_RATE);
    }
    return 0;
}

void captcha(int num, char *s) // num — число, s — указатель на строку
{
    int position = 0; // позиция в строке
    int x[4]; // массив разрядов
    int div = 1000; // делитель на разряды
    int var = num; // частное от деления
    int rest; // остаток от деления
    for (int i = 0; i < 4; i++) {
        rest = (int) (var / div);
        x[i] = rest;
        var = var - rest * div;
        div = div / 10;
    }
    // Тысячи
    switch (x[0]) {
        case 1:
            strcpy(s, "Одна тысяча ");
            break;
        case 2:
            strcpy(s, "Две тысячи ");
            break;
        case 3:
            strcpy(s, "Три тысячи ");
            break;
        case 4:
            strcpy(s, "Четыре тысячи ");
            break;
        case 5:
            strcpy(s, "Пять тысяч ");
            break;
        case 6:
            strcpy(s, "Шесть тысяч ");
            break;
        case 7:
            strcpy(s, "Семь тысяч ");
            break;
        case 8:
            strcpy(s, "Восемь тысяч ");
            break;
        case 9:
            strcpy(s, "Девять тысяч ");
            break;
        default:
            break;
    }
    position = strlen(s);
    // Сотни
    switch (x[1]) {
        case 1:
            strcpy(s + position, "сто ");
            break;
        case 2:
            strcpy(s + position, "двести ");
            break;
        case 3:
            strcpy(s + position, "триста ");
            break;
        case 4:
            strcpy(s + position, "четыреста ");
            break;
        case 5:
            strcpy(s + position, "пятьсот ");
            break;
        case 6:
            strcpy(s + position, "шестьсот ");
            break;
        case 7:
            strcpy(s + position, "семьсот ");
            break;
        case 8:
            strcpy(s + position, "восемьсот ");
            break;
        case 9:
            strcpy(s + position, "девятьсот ");
            break;
        default:
            break;
    }
    position = strlen(s);
    // Десятки
    switch (x[2]) {
        case 1:
            // Числа от 10 до 19
            switch (x[3]) {
                case 0:
                    strcpy(s + position, "десять ");
                    break;
                case 1:
                    strcpy(s + position, "одиннадцать ");
                    break;
                case 2:
                    strcpy(s + position, "двенадцать ");
                    break;
                case 3:
                    strcpy(s + position, "тринадцать ");
                    break;
                case 4:
                    strcpy(s + position, "четырнадцать ");
                    break;
                case 5:
                    strcpy(s + position, "пятнадцать ");
                    break;
                case 6:
                    strcpy(s + position, "шестнадцать ");
                    break;
                case 7:
                    strcpy(s + position, "семнадцать ");
                    break;
                case 8:
                    strcpy(s + position, "восемнадцать ");
                    break;
                case 9:
                    strcpy(s + position, "девятнадцать ");
                    break;
            }
            x[3] = 0;
            position = strlen(s);
            break;
        case 2:
            strcpy(s + position, "двадцать ");
            break;
        case 3:
            strcpy(s + position, "тридцать ");
            break;
        case 4:
            strcpy(s + position, "сорок ");
            break;
        case 5:
            strcpy(s + position, "пятьдесят ");
            break;
        case 6:
            strcpy(s + position, "шестьдесят ");
            break;
        case 7:
            strcpy(s + position, "семьдесят ");
            break;
        case 8:
            strcpy(s + position, "восемьдесят ");
            break;
        case 9:
            strcpy(s + position, "девяносто ");
            break;
        default:
            break;
    }
    position = strlen(s);
    // Единицы
    switch (x[3]) {
        case 1:
            strcpy(s + position, "один ");
            break;
        case 2:
            strcpy(s + position, "два ");
            break;
        case 3:
            strcpy(s + position, "три ");
            break;
        case 4:
            strcpy(s + position, "четыре ");
            break;
        case 5:
            strcpy(s + position, "пять ");
            break;
        case 6:
            strcpy(s + position, "шесть ");
            break;
        case 7:
            strcpy(s + position, "семь ");
            break;
        case 8:
            strcpy(s + position, "восемь ");
            break;
        case 9:
            strcpy(s + position, "девять ");
            break;
        default:
            break;
    }
    position = strlen(s);
}

int lab9_b(){
    printf("Enter the num");
    int num;
    char * result = malloc(100*sizeof (char));
    scanf("%d", &num);
    captcha(num, result);
    printf("%s", result);
    return 0;
}