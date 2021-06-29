#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

int capitalize(char *str);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char str[128] = "";
    printf("¬ведите строку: ");
    fgets(str, 128, stdin);
    capitalize(str);
    printf("%s", str);

    system("pause");
    return 0;
}

int capitalize(char *str)
{
    int k = strlen(str);
    for (int i = 0; i < k; i++)
    {
        if (str[i] == 'a' || str[i] == 'b')
            str[i] = toupper(str[i]);
    }
    return k;
}