#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

bool isVis(int year)
{
    if (year % 4 != 0 || year % 100 == 0 & year % 400 != 0)
        return false;
    return true;
}

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (isVis(2020) == false)
    {
        printf("2021 Не високосный");
    }
    if (isVis(2021) == true)
    {
        printf("2020 Високосный");
    }

    system("pause");
    return 0;
}