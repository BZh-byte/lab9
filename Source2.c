#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

int main(void)
{
    char chislo[1024];
    int povtor, i, dlina, cif, kol3, povtorPos, chet, bol5;
    int summaNechet, summa7, summaChetBezPos, odinak, ravno;
    int summaNechetRaz, summaChetRaz;
    int vtoraya, posled, predposled;
    unsigned long long proizBez0;

    SetConsoleOutputCP(65001);
    do {
        printf("Введите неотрицательное целое число: ");
        if (scanf("%1023s", chislo) != 1) return 1;
        dlina = (int)strlen(chislo);
        for (i = 0; i < dlina; i++) {
            if (!isdigit((unsigned char)chislo[i])) break;
        }
        if (i != dlina) {
            printf("Ошибка: вводите только цифры.\n");
        }
        else {
            kol3 = povtorPos = chet = bol5 = 0;
            summaNechet = summa7 = summaChetBezPos = 0;
            odinak = ravno = 0;
            summaNechetRaz = summaChetRaz = 0;
            proizBez0 = 1;
            for (i = 0; i < dlina; i++) {
                cif = chislo[i] - '0';
                if (cif == 3) kol3++;
                if (i > 0 && cif == chislo[i - 1] - '0') odinak++;
                if (cif % 2 == 0) chet++;
                if (cif > 5) bol5++;
                if (cif % 2 != 0) summaNechet += cif;
                if (cif >= 7) summa7 += cif;
                if (cif != 0) proizBez0 *= (unsigned long long)cif;
                if (i != dlina - 1 && cif % 2 == 0) summaChetBezPos += cif;
                if ((dlina - i) % 2 == 1) summaNechetRaz += cif;
                else summaChetRaz += cif;
            }
            posled = chislo[dlina - 1] - '0';
            predposled = dlina >= 2 ? chislo[dlina - 2] - '0' : 0;
            vtoraya = dlina >= 2 ? chislo[1] - '0' : 0;
            printf("1) Количество цифр 3: %d\n", kol3);
            printf("2) Число повторений последней цифры: ");
            for (i = 0; i < dlina; i++)
                if (chislo[i] - '0' == posled) povtorPos++;
            printf("%d\n", povtorPos);
            printf("3) Количество четных цифр: %d\n", chet);
            printf("4) Количество цифр больше 5: %d\n", bol5);
            printf("5) Сумма нечетных цифр: %d\n", summaNechet);
            printf("6) Сумма цифр >= 7: %d\n", summa7);
            printf("7) Произведение ненулевых цифр: %llu\n", proizBez0);
            if (dlina >= 2)
                printf("8) Произведение второй и предпоследней: %d\n", vtoraya * predposled);
            else printf("8) Нужно минимум две цифры.\n");
            printf("9) Сумма четных цифр, кроме последней: %d\n", summaChetBezPos);
            printf("10) Количество соседних одинаковых пар: %d\n", odinak);
            if (dlina % 2 == 0) {
                ravno = 1;
                for (i = 0; i < dlina / 2; i++)
                    if (chislo[i] != chislo[i + dlina / 2]) ravno = 0;
                printf("11) Половины числа равны: %s\n", ravno ? "да" : "нет");
            }
            else printf("11) Длина нечетная: две равные половины невозможны.\n");
            printf("12) Произведение сумм цифр нечетных и четных разрядов: %d\n",
                summaNechetRaz * summaChetRaz);
            printf("Примечание: произведение в пункте 7 может переполниться.\n");
        }
        printf("\nПродолжить? (1 - да, 0 - нет): ");
        if (scanf("%d", &povtor) != 1) return 1;
    } while (povtor == 1);
    return 0;
}