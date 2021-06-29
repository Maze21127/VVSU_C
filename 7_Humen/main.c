#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

struct Humen *my_sort(struct Humen *h);

struct Humen
{

    char name[15];
    char sirname[15];
    int birthyear;
};

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE *file = fopen("input.txt", "r");

    struct Humen input[4];
    struct Humen *output;
    int i = 0;

    while (!feof(file))
    {
        fscanf(file, "%s", input[i].name);
        fscanf(file, "%s", input[i].sirname);
        fscanf(file, "%d", &input[i].birthyear);
        i++;
    }
    for (i = 0; i < 4; i++)
    {
        printf("%d. %s", i + 1, input[i].name);
        printf(" %s", input[i].sirname);
        printf(" %d", input[i].birthyear);
        printf("\n");
    }
    printf("\n");
    output = my_sort(input);

    for (i = 0; i < 4; i++)
    {
        printf("%d. %s", i + 1, output[i].name);
        printf(" %s", output[i].sirname);
        printf(" %d", output[i].birthyear);
        printf("\n");
    }

    system("pause");
    return 0;
}

struct Humen *my_sort(struct Humen *h)
{
    struct Humen tmp;
    int N = 4;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (h[i].birthyear > h[j].birthyear)
            {
                tmp = h[j - 1];
                h[j - 1] = h[j];
                h[j] = tmp;
            }
        }
    }
    return h;
}
