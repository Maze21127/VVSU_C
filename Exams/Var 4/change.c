#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>

int **swapPairs(int **matrix, int n, int m)
{
    int **result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        result[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i + 1 < n * m; i += 2)
    {

        int firstRowNumber = i / m;
        int secondRowNumber = (i + 1) / m;

        result[firstRowNumber][i % m] = matrix[secondRowNumber][(i + 1) % m];
        result[secondRowNumber][(i + 1) % m] = matrix[firstRowNumber][i % m];
    }
    return result;
}

int **createMatrix(int n, int m)
{

    int **matrix = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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

    clock_t start = clock();
    long ltime = time(NULL) / 2;
    srand(ltime);
    int n, m;
    printf("Введите n\n");
    scanf("%d", &n);
    printf("Введите m\n");
    scanf("%d", &m);

    int **matrix1 = createMatrix(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i + 1 < n * m; i += 2)
    {

        int firstRowNumber = i / m;
        int secondRowNumber = (i + 1) / m;

        int tmp = matrix1[firstRowNumber][i % m];
        matrix1[firstRowNumber][i % m] = matrix1[secondRowNumber][(i + 1) % m];
        matrix1[secondRowNumber][(i + 1) % m] = tmp;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(matrix1[i]);
    }

    free(matrix1);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Затраченное время равно %f секунд\n", time_spent);
    system("pause");
    return 0;
}
