#include <stdlib.h>
#include <stdio.h>

int fib(long long int x)
{
    if (x == 0) return 0;
    if (x == 1) return 1;
    return fib(x - 1) + fib(x - 2);
}

int main()
{
    long long int n = 100;

    printf("%lld\n", fib(n));

    system("pause");
    return 0;
}