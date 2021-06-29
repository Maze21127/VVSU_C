#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>

int sum(int **matrix, int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result += matrix[i][j];
        }
    }
    return result;
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
    int n;
    printf("Введите n\n");
    clock_t start = clock();
    scanf("%d", &n);


    int **matrix1 = createMatrix(n);
    int **matrix2 = createMatrix(n);

    int counter = 0;
    while (sum(matrix1, n) != sum(matrix2, n))
    {
        matrix1 = createMatrix(n);
        matrix2 = createMatrix(n);
        counter += 1;
    }
    printf("Было создано матриц %d \n", counter);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    FILE *output = fopen("output.txt", "w");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(output, "%d ", matrix1[i][j]);
        }
        fprintf(output, "\n");
    }
    fprintf(output, "\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(output, "%d ", matrix2[i][j]);
        }
        fprintf(output, "\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(matrix1[i]);
        free(matrix2[i]);
    }

    free(matrix1);
    free(matrix2);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Затраченное время равно %f секунд\n", time_spent);
    system("pause");
    return 0;
}
