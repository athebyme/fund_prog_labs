#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include "lab9_10/lab9.h"

int main() {
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    lab9_b();

    return 0;
}