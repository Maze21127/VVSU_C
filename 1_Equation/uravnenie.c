#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double x1, x2, x, d, a, b, c;
    int ans = -1;
    bool check = true;

    do
    {

        printf("������� a: ");
        scanf("%lf", &a);
        printf("������� b: ");
        scanf("%lf", &b);
        printf("������� c: ");
        scanf("%lf", &c);

        d = b * b - 4 * a * c;

        if (d > 0)
        {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            printf("x1 = %.2lf  \n", x1);
            printf("x2 = %.2lf  \n", x2);
        }

        if (d == 0)
        {
            x = (-b + sqrt(d)) / (2 * a);
            printf("x = %.2lf", x);
        }
        if (d < 0)
            printf("������ ��� \n");

        check = false;
        while ((c = getchar()) != '\n')
            putchar(c);

        printf("����������? (y/n): ");
        ans = getchar();
        if (ans == 'y')
            check = true;

    } while (check);

    getchar();
    return 0;
}
