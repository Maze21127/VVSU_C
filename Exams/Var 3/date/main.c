#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int numberDay(int day, int month, int year) {

    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;

    int jdn = day + ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045;
    return jdn;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE *input = fopen("input.txt", "r");
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int dayStart, monthStart = 1, yearStart = 1900;
    int dayEnd, monthEnd, yearEnd;
    
    dayStart = timeinfo->tm_mday;
    monthStart += timeinfo->tm_mon;
    yearStart += timeinfo->tm_year;

    printf("dayStart = %d\n", dayStart);
    printf("monthStart = %d\n", monthStart);
    printf("yearStart = %d\n", yearStart);

    fscanf(input, "%d%d%d", &dayEnd, &monthEnd, &yearEnd);
    fclose(input);

    printf("День - %d\n", dayEnd);
    printf("Месяц - %d\n", monthEnd);
    printf("Год - %d\n", yearEnd);

    printf("%d\n", numberDay(dayEnd, monthEnd, yearEnd) - numberDay(dayStart, monthStart, yearStart));

    
    system("pause");
    return 0;
}
