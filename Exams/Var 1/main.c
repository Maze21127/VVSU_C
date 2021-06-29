#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>

int **add(int **first, int **second, int n)
{
    int **result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        result[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
    return result;
}

int **mul(int **first, int **second, int n)
{
    int **result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        result[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    long ltime = time(NULL) / 2;
    srand(ltime);

    clock_t start = clock();
    FILE *input = fopen("input.txt", "w");
    int n;
    printf("Введите n\n");
    scanf("%d", &n);

    int **first = (int **)malloc(n * sizeof(int *));
    int **second = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        first[i] = (int *)malloc(n * sizeof(int));
        second[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            first[i][j] = (rand() % 100);
            second[i][j] = (rand() % 100);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(input, "%d ", first[i][j]);
        }
        fprintf(input, "\n");
    }

    fprintf(input, "\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(input, "%d ", second[i][j]);
        }
        fprintf(input, "\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(first[i]);
        free(second[i]);
    }

    free(first);
    free(second);
    fclose(input);

    FILE *inp = fopen("input.txt", "r");

    first = (int **)malloc(n * sizeof(int *));
    second = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        first[i] = (int *)malloc(n * sizeof(int));
        second[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(inp, "%d", &first[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(inp, "%d", &second[i][j]);
        }
    }

    int **result = add(first, second, n);
    FILE *output = fopen("output.txt", "w");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(output, "%d ", result[i][j]);
        }
        fprintf(output, "\n");
    }
    fprintf(output, "\n");

    result = mul(first, second, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(output, "%d ", result[i][j]);
        }
        fprintf(output, "\n");
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Затраченное время равно %f секунд\n", time_spent);

    system("pause");
    return 0;
}
