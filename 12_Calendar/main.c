#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void y_calendar(int year)
{
    time_t now;
    struct tm *timeinfo;

    int m, i, j;
    char *month[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
                     "Июль", "Август", "Сентябрь", "Октябрь", "Нояюрь", "Декабрь"};

    time(&now);
    timeinfo = localtime(&now);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = 0;
    m = -1;

    while (m < 12)
    {
        for (i = 1; i < 33; i++)
        {
            timeinfo->tm_mday = i;
            mktime(timeinfo);

            if (timeinfo->tm_mon > m)
            {
                printf("\n                        %s\n", month[timeinfo->tm_mon]);
                printf("_______________________________\n");
                printf("  Вс  Пн  Вт  Ср  Чт  Пт  Сб\n");
                printf("_______________________________\n");
                for (j = 0; j < (timeinfo->tm_wday); j++)
                    printf("    ");
                m++;
                break;
            }

            if (m == 11 && timeinfo->tm_mon == 0)
            {
                m++;
                break;
            }

            printf("%4d", timeinfo->tm_mday);

            if (timeinfo->tm_wday == 6)
                printf("\n");
        }
    }
    printf("\n");
}

void m_calendar(int m, int year)
{
    time_t now;
    struct tm *timeinfo;

    int j;
    char *month[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
                     "Июль", "Август", "Сентябрь", "Октябрь", "Нояюрь", "Декабрь"};

    time(&now);
    timeinfo = localtime(&now);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = m - 1;

    printf("\n                        %s, %d\n", month[m - 1], year);
    printf("_______________________________\n");
    printf("  Вс  Пн  Вт  Ср  Чт  Пт  Сб\n");
    printf("_______________________________\n");

    for (int i = 1; i < 32; i++)
    {
        timeinfo->tm_mday = i;
        mktime(timeinfo);

        if (timeinfo->tm_mon == m)
            break;

        if (i == 1)
        {
            for (int j = 0; j < (timeinfo->tm_wday); j++)
                printf("    ");
        }

        printf("%4d", timeinfo->tm_mday);

        if (timeinfo->tm_wday == 6)
            printf("\n");
    }
    printf("\n");
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
    if (weekday == 0) weekday = 7;
    
    char *days[] =
        {
            "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};
    
    printf("%s\n", days[weekday - 1]);
}

void now()
{
    time_t time_now = time(NULL);
    printf("%s", ctime(&time_now));
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

    if (nums[0] == 0)
        now();
    else
    {
        switch (N)
        {
        case 1:
            y_calendar(nums[0]);
            break;
        case 2:
            m_calendar(nums[1], nums[0]);
            break;
        case 3:
            weekday(nums[0], nums[1], nums[2]);
        }
    }

    printf("\n");

    system("pause");
    getchar();
    return 0;
}