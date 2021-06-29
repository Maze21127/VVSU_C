#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>

void getMinimalIndex(int **matrix, int n)
{
    int min = 100000;
    int ri = 0;
    int rj = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                ri = i;
                rj = j;
            }
        }
    }
    printf("Минимальный элемент находится под индексом %d %d\n", ri, rj);
}

void countOdd(int **matrix, int n)
{
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] % 2 != 0)
                counter += 1;
        }
    }
    printf("Количество нечетных элементов = %d", counter);
    printf("\n");
}

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
    FILE *input = fopen("input.txt", "w");
    int n;
    printf("Введите n\n");
    scanf("%d", &n);
    clock_t start = clock();

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

    int **result_add = add(first, second, n);
    int **result_mul = mul(first, second, n);

    FILE *output = fopen("output.txt", "w");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(output, "%d ", result_add[i][j]);
        }
        fprintf(output, "\n");
    }
    fprintf(output, "\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(output, "%d ", result_mul[i][j]);
        }
        fprintf(output, "\n");
    }
    fclose(output);

    FILE *out = fopen("output.txt", "r");

    int **firstSwap = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        firstSwap[i] = (int *)malloc(n * sizeof(int));

    printf("Матрица до перестановок\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(out, "%d", &firstSwap[i][j]);
            printf("%d ", firstSwap[i][j]);
        }
        printf("\n");
    }
    printf("\n");   
    for (int i = 0; i + 1 < n * n; i += 2)
    {

        int firstRowNumber = i / n;
        int secondRowNumber = (i + 1) / n;

        int tmp = firstSwap[firstRowNumber][i % n];
        firstSwap[firstRowNumber][i % n] = firstSwap[secondRowNumber][(i + 1) % n];
        firstSwap[secondRowNumber][(i + 1) % n] = tmp;
    }

    printf("Матрица после перестановок\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", firstSwap[i][j]);
        }
        printf("\n");
    }

    getMinimalIndex(firstSwap, n);
    countOdd(firstSwap, n);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Затраченное время равно %f секунд\n", time_spent);

    system("pause");
    return 0;
}
