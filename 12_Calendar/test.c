#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

void weekday(int year, int month, int day);

bool isVis(int year)
{
    if (year % 4 != 0 || year % 100 == 0 & year % 400 != 0)
        return false;
    return true;
}

void month(int year, int m)
{
    int f;
    if (isVis(year) == true) f = 29; else f = 28;
    int days[12] =
        {
            31, f, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 1; i < days[m - 1] + 1; i++)
    {   
        printf("%d ", i);
        weekday(year, m, i);
    }
}


void weekday(int year, int month, int day)
{
    if (month < 3)
    {
        month += 10;
        year -= 1;
    }
    else
        month -= 2;

    int weekday = (day + 31 * month / 12 + year + year / 4 - year / 100 + year / 400) % 7;
    if (weekday == 0)
        weekday = 7;
    char *days[] =
        {
            "Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};

    printf("%s\n", days[weekday - 1]);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char str[11];
    char *istr;
    char sep[10] = ".";
    int N = 0;
    int nums[3];

    printf("Введите дату в формате\nгггг.мм.дд – для получения дня недели\nгггг.мм - для получения календаря за месяц\nгггг - для получения календаря за год\nnow для получения текущей даты\n");
    fgets(str, 11, stdin);

    istr = strtok(str, sep);

    while (istr != NULL)
    {
        nums[N] = atoi(istr);
        N++;
        istr = strtok(NULL, sep);
    }

    weekday(nums[0], nums[1], nums[2]);

    month(nums[0], nums[1]);

    if (isVis(2021))
    {
        printf("Високосный");
    }

    printf("\n");

    system("pause");

    return 0;
}