#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

void clearMemory(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}


void printToFile(FILE *filename, int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(filename, "%d ", matrix[i][j]);
        }
        fprintf(filename, "\n");
    }
}

void printToScreen(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


bool isEqual(int **first, int **second, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (first[i][j] != second[i][j]) return false;
        }
    }
    return true;
}

int **createMatrix(int n)
{

    int **matrix = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

int **trans(int **matrix, int n)
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
            result[i][j] = matrix[j][i];
        }
    }
    return result;
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

    int **matrix1 = createMatrix(n);

    printToFile(input, matrix1, n);
    fclose(input);

    clearMemory(matrix1, n);

    FILE *inp = fopen("input.txt", "r");

    matrix1 = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        matrix1[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(inp, "%d", &matrix1[i][j]);
        }
    }

    int **matrix2 = createMatrix(n);
    int **result_add = add(matrix1, matrix2, n);
    int **result_mul = mul(matrix1, matrix2, n);

    FILE *output = fopen("output.txt", "w");

    printToFile(output, result_add, n);
    printToFile(output, result_add, n);
    fclose(output);
    clearMemory(result_add, n);
    clearMemory(result_mul, n);

    int count = 0;
    while (isEqual(matrix1, matrix2, n))
    {
        matrix2 = createMatrix(n);
        count += 1;
        clearMemory(matrix2, n);
        if (count % 10000000 == 0) printf("%d\n", count);
    }

    FILE *twins = fopen("1.txt", "w");

    printToFile(twins, matrix2, n);
    fprintf(twins, "\n");
    printToFile(twins, matrix2, n);
    fprintf(twins, "Итераций: %d", count);
    fclose(twins);

    printToScreen(matrix1, n);
    printf("\n");
    int **m_trans = trans(matrix1, n);
    printToScreen(m_trans, n);
    clearMemory(matrix1, n);
    clearMemory(matrix2, n);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Затраченное время равно %f секунд\n", time_spent);

    system("pause");
    return 0;
}
