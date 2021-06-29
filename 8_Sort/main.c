#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

struct Humen *my_sort_birthyear(struct Humen *h);
struct Humen *my_sort_name(struct Humen *h);
struct Humen *my_sort_sirname(struct Humen *h);
struct Humen *my_sort_sex(struct Humen *h);
struct Humen *my_sort_height(struct Humen *h);

struct Humen
{
    char name[20];
    char sirname[20];
    int birthyear;
    char sex[3];
    int height;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE *file = fopen("input.txt", "r");

    struct Humen input[7];
    struct Humen *output;
    int i = 0;

    while (!feof(file))
    {
        fscanf(file, "%s", input[i].name);
        fscanf(file, "%s", input[i].sirname);
        fscanf(file, "%d", &input[i].birthyear);
        fscanf(file, "%s", input[i].sex);
        fscanf(file, "%d", &input[i].height);
        i++;
    }
    for (i = 0; i < 7; i++)
    {
        printf("%d. %s", i + 1, input[i].name);
        printf(" %s", input[i].sirname);
        printf(" %d", input[i].birthyear);
        printf(" %s", input[i].sex);
        printf(" %d", input[i].height);
        printf("\n");
    }
    printf("\n");

    output = my_sort_sirname(input);

    for (i = 0; i < 7; i++)
    {
        printf("%d. %s", i + 1, output[i].name);
        printf(" %s", output[i].sirname);
        printf(" %d", output[i].birthyear);
        printf(" %s", output[i].sex);
        printf(" %d", output[i].height);
        printf("\n");
    }

    system("pause");

    return 0;
}

struct Humen *my_sort_birthyear(struct Humen *h)
{
    struct Humen tmp;
    int N = 6;
    for (int i = N; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (h[j].birthyear > h[j + 1].birthyear)
            {
                tmp = h[j];
                h[j] = h[j + 1];
                h[j + 1] = tmp;
            }
        }
    }
    return h;
}

struct Humen *my_sort_name(struct Humen *h)
{
    struct Humen tmp;
    int N = 6;
    for (int i = N; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (strcmp(h[j].name, h[j + 1].name) > 0)
            {
                tmp = h[j];
                h[j] = h[j + 1];
                h[j + 1] = tmp;
            }
        }
    }
    return h;
}

struct Humen *my_sort_sirname(struct Humen *h)
{
    struct Humen tmp;
    int N = 6;
    for (int i = N; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (strcmp(h[j].sirname, h[j + 1].sirname) > 0)
            {
                tmp = h[j];
                h[j] = h[j + 1];
                h[j + 1] = tmp;
            }
            if (strcmp(h[j].sirname, h[j + 1].sirname) == 0)
            {
                if (strcmp(h[j].name, h[j + 1].name) > 0)
                {
                    tmp = h[j];
                    h[j] = h[j + 1];
                    h[j + 1] = tmp;
                }
            }
        }
    }
    return h;
}

struct Humen *my_sort_sex(struct Humen *h)
{
    struct Humen tmp;
    int N = 6;
    for (int i = N; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (strcmp(h[j].sex, h[j + 1].sex) > 0)
            {
                tmp = h[j];
                h[j] = h[j + 1];
                h[j + 1] = tmp;
            }
        }
    }
    return h;
}

struct Humen *my_sort_height(struct Humen *h)
{
    struct Humen tmp;
    int N = 6;
    for (int i = N; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (h[j].height > h[j + 1].height)
            {
                tmp = h[j];
                h[j] = h[j + 1];
                h[j + 1] = tmp;
            }
        }
    }
    return h;
}
