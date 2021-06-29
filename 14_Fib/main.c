#include <setjmp.h>
#include <stdio.h>
#include <windows.h>

jmp_buf mainTask, FibTask;

void fib(void);
int main(void)
{
    long i = 1;
    if (!setjmp(mainTask))
    {
        fib();
    }
    for (int j = 0; j < 9; j++)
    {
        if (!setjmp(mainTask))
        {
            longjmp(FibTask, 1);
        }
    }
    system("pause");
}
void fib(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    static int c = 0;
    static long i = 1;
    static long j = 1;

    long k = 0;
    while(1)
    {
        k = i + j;
        if (i <= j)
        {
            i = k;
        }
        else
        {
            j = k;
        }
        c++;
        printf("%d число фиббоначи: %ld\n", c, k);
        if (!setjmp(FibTask))
            longjmp(mainTask, 1);
    }

}