#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>



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
    fclose(filename);
}

void clearMemory(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
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

int main()

{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    long ltime = time(NULL) / 2;
    srand(ltime);
    FILE *input = fopen("input.txt", "w");
    int n;
    printf("¬ведите n\n");
    scanf("%d", &n);
    clock_t start = clock();

    int **matrix1 = createMatrix(n);

    printToFile(input, matrix1, n);
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

    int num, ai;
    int a[10];
    int b[100];
    printf("¬ведите числа дл€ поиска, введите 10 дл€ остановки: ");
    scanf("%d", &num);
    while (num != 10)
    {
        scanf("%d", &num);
        a[ai] = num;
        ai += 1;
    }
    
    for (int i = 0; i < ai; i++) printf("%d ", a[i]);

    return 0;
}