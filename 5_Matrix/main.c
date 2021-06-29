#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include "main.h"


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int n;

	printf("¬ведите размерность матриц\n");
	scanf("%d", &n);

	double **first = (double **)malloc(n * sizeof(double *));
	double **second = (double **)malloc(n * sizeof(double *));

	for (int i = 0; i < n; i++)
	{
		first[i] = (double *)malloc(n * sizeof(int));
		second[i] = (double *)malloc(n * sizeof(int));
	}

	printf("¬ведите элементы первой матрицы\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("¬ведите элемент [%d][%d]\n", i, j);
			scanf("%lf", &first[i][j]);
		}
	}

	printf("¬ведите элементы второй матрицы\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("¬ведите элемент [%d][%d]\n", i, j);
			scanf("%lf", &second[i][j]);
		}
	}

	char sign;
	while ((sign = getchar()) != '\n')
		putchar(sign);

	printf("¬ведите знак +, - или *\n");
	scanf("%c", &sign);

	double **result;

	if (sign == '+')
		result = add(first, second, n);
	else if (sign == '-')
		result = diff(first, second, n);
	else if (sign == '*')
		result = mul(first, second, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%lf ", result[i][j]);
		}
		printf("\n");
	}

	
	system("pause");

	return 0;
}