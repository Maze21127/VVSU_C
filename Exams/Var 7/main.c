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

char generate(int n){
    
    char ar[]={'a', 'б', 'в', 'г', 'д', 'е', 'Є', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ы', 'ь', 'э', 'ю', '€', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    printf("%c\n", ar[0 + rand() % (0 - 42)]);

}
int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    long ltime = time(NULL) / 2;
    srand(ltime);
    FILE *input2 = fopen("input2.txt", "w");
    int n;
    printf("¬ведите n\n");
    scanf("%d", &n);
    clock_t start = clock();

    

    generate(n);
    generate(n);
    generate(n);
    generate(n);
    generate(n);
    generate(n);
    generate(n);





    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("«атраченное врем€ равно %f секунд\n", time_spent);

    system("pause");
    return 0;
}
