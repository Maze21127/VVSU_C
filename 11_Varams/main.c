#include <stdio.h>
#include <stdarg.h>
#include <locale.h>

int add_num(int n, ...)
{
	int res = 0;
	va_list list;
	va_start(list, n);
	int i = 0;
	for (i; i < n; i++)
		res += va_arg(list, int);
	va_end(list);
	return res;
}

int avg(int n, ...)
{
	int res = 0;
	va_list list;
	va_start(list, n);
	int i = 0;
	for (i; i < n; i++)
		res += va_arg(list, int);
	va_end(list);
	return res / n;
}

int max(int n, ...)
{
	int max = 0;
	int n_start = n;
	va_list list;
	va_start(list, n);
	int i = 0;
	for (i; i < n; i++)
	{
		if (i == n_start)
			max = va_arg(list, int);
		int tmp = va_arg(list, int);
		if (tmp > max)
			max = tmp;
	}
	va_end(list);
	return max;
}

int main(void)
{
	setlocale(LC_ALL, "Rus");
	printf("%d\n", add_num(4, 6, 19, -6, 5));
	printf("%d\n", avg(4, 6, 19, -6, 5));
	printf("%d\n", max(4, 6, 19, -6, 5));

	getchar();
	return 0;
}