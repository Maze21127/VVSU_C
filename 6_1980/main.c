#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define N 80

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    FILE *file = fopen("input.txt", "r");
    ;
    FILE *output = fopen("output.txt", "w");
    char arr[N];

    while (fgets(arr, N, file) != NULL)
    {
        int tlen = strlen(arr) - 5;
        char year[5];
        year[0] = arr[tlen];
        year[1] = arr[tlen + 1];
        year[2] = arr[tlen + 2];
        year[3] = arr[tlen + 3];
        year[4] = 0;
        int i = atoi(year);
        if (i > 1980)
            fprintf(output, "%s", arr);
    }

    printf("\n");
    fclose(output);
    fclose(file);
}
