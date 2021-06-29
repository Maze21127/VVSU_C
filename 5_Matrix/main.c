#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include "main.h"


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int n;

	printf("������� ����������� ������\n");
	scanf("%d", &n);

	double **first = (double **)malloc(n * sizeof(double *));
	double **second = (double **)malloc(n * sizeof(double *));

	for (int i = 0; i < n; i++)
	{
		first[i] = (double *)malloc(n * sizeof(int));
		second[i] = (double *)malloc(n * sizeof(int));
	}

	printf("������� �������� ������ �������\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("������� ������� [%d][%d]\n", i, j);
			scanf("%lf", &first[i][j]);
		}
	}

	printf("������� �������� ������ �������\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("������� ������� [%d][%d]\n", i, j);
			scanf("%lf", &second[i][j]);
		}
	}

	char sign;
	while ((sign = getchar()) != '\n')
		putchar(sign);

	printf("������� ���� +, - ��� *\n");
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