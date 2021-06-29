#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
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

int main(void)
{
	setlocale(LC_ALL, "Rus");

	char str[200] = "";
    char newstr[200] = "";
    char *istr, *istr2;

    int *nums;
    int N = 0;
    printf("¬ведите строку чисел: ");

    fgets(str, 200, stdin);
    strcpy(newstr, str);

    istr = strtok(str, " ");

    while (istr != NULL)
    {
        N++;
        istr = strtok(NULL, " ");
    }

    nums = (int *)malloc(N * sizeof(int));

    istr2 = strtok(newstr, " ");
    N = 0;

    while (istr2 != NULL)
    {
        nums[N] = atoi(istr2);
        N++;
        istr2 = strtok(NULL, " ");
    }

	int nn = nums[0];
	for (int i = 0; i < N - 1; i++) nums[i] = nums[i+1]; 


	printf("%d\n", add_num(nn, nums));
	//printf("%d\n", avg(nums));
	//printf("%d\n", max(nums));


	system("pause");
	return 0;
}