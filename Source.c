#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

int main(void)
{
    int i, j;
    SetConsoleOutputCP(65001);

    printf("Задание 1. Таблица Пифагора:\n");
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++)
            printf("%4d", i * j);
        printf("\n");
    }

    printf("\nЛевый нижний треугольник:\n");
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= i; j++)
            printf("%4d", i * j);
        printf("\n");
    }

    printf("\nИндивидуальный вариант 8:\n");
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++)
            printf("%4d", i * 10);
        printf("\n");
    }
    return 0;
}
