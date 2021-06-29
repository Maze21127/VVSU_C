#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    clock_t start = clock();
    FILE *input = fopen("input.txt", "w");
    int n;
    printf("n = \n");
    scanf("%d", &n);

    int *vector = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        vector[i] = (rand() % 150);
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(input, "%d ", vector[i]);
    }
    fprintf(input, "\n");
    fclose(input);
    free(vector);

    FILE *output = fopen("output.txt", "w");
    input = fopen("input.txt", "r");
    for (int i = 0; i < n; i++)
    {
        int number;
        fscanf(input, "%d", &number);

        if (number % 5 == 0 && number % 7 == 0)
        {
            fprintf(output, "%s", "ÐŸÐ¯Ð¢Ð¬Ð¡Ð•ÐœÐ¬ ");
        }
        else if (number % 5 == 0)
        {
            fprintf(output, "%s", "ÐŸÐ¯Ð¢Ð¬ ");
        }
        else if (number % 7 == 0)
        {
            fprintf(output, "%s", "Ð¡Ð•ÐœÐ¬ ");
        }
        else
        {
            fprintf(output, "%d ", number);
        }
    }
    fclose(input);
    input = fopen("input.txt", "r");

    vector = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        fscanf(input, "%d", &vector[i]);
    }

    int M;
    printf("m = \n");
    scanf("%d", &M);

    int rows = 0;
    rows = n / M;

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(M * sizeof(int));
    }

    for (int i = 0, k = 0; i < rows; i++)
    {
        for (int j = 0; j < M; j++, k++)
        {
            matrix[i][j] = vector[k];
        }
    }

    int rows_sum;
    int column_sum;
    for (int i = 0, k = 0; i < rows; i++)
    {
        for (int j = 0; j < M; j++, k++)
        {
            matrix[i][j] = vector[k];
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        rows_sum = 0;
        for (int j = 0; j < M; j++)
        {
            rows_sum += matrix[i][j];
        }
        printf("Ñóììà %d ñòðîêè = %d\n", i, rows_sum);
    }

    for (int i = 0; i < M; i++)
    {
        column_sum = 0;
        for (int j = 0; j < rows; j++)
        {
            column_sum += matrix[j][i];
        }
        printf("Ñóììà %d êîëîíêè = %d\n", i, column_sum);
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Çàòðà÷åíî âðåìåíè %f\n", time_spent);

    system("pause");

    return 0;
}
