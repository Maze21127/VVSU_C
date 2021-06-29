#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N, M, i, j;
	int sum = 0, magic;
	bool magic_b = true;
	printf("Введите размерность матрицы\n");
	scanf("%d", &N);
	if (N > 1)
		magic = (N * (N * N + 1)) / 2;
	int A[N][N];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("Введите элемент матрицы [%d][%d]\n", i, j);
			scanf("%d", &A[i][j]);
		}
		printf("\n");
	}
	if (N > 1)
		magic = (N * (N * N + 1)) / 2;
	else
		magic = A[0][0];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < N; i++)
	{
		sum += A[i][i];
	}
	if (sum == magic && N > 2)
	{
		sum = 0;
		for (i = 0; i < N; i++)
		{
			sum += A[i][N - 1 - i];
		}
		if (sum == magic)
		{
			for (i = 0; i < N; i++)
			{
				sum = 0;
				for (j = 0; j < N; j++)
				{
					sum += A[i][j];
				}
				if (sum != magic)
				{
					magic_b = false;
					break;
				};
			}
		}
	}
	else if (N == 2)
	{
		printf("Матрица 2х2 не может быть магической\n");
		magic_b = false;
		exit(0);
	}
	else if (N == 1)
	{
		printf("Матрица 1х1 всегда магическая\n");
		magic_b = false;
		exit(0);
	}
	if (magic_b)
		printf("It's Magic \n");
	else
		printf("It's not Magic \n");
	

	
	return 0;
}
