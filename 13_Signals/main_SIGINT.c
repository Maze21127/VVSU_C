#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <windows.h>

void sig_sigint(int sig)
{
    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%s", "прервано через SIGINT");
    exit(0);
}

void sig_sigabrt(int sig)
{
    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%s", "прервано через SIGABRT");
    exit(0);
}

void sig_sigfpe(int sig)
{
    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%s", "прервано через SIGFPE");
    exit(0);
}

void sig_sigill(int sig)
{
    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%s", "прервано через SIGILL");
    exit(0);
}

void sig_sigsegv(int sig)
{
    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%s", "прервано через SIGSEGV");
    exit(0);
}

void sig_sigterm(int sig)
{
    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%s", "прервано через SIGTERM");
    exit(0);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    signal(SIGINT, sig_sigint);
    signal(SIGABRT, sig_sigabrt);
    signal(SIGFPE, sig_sigfpe);
    signal(SIGILL, sig_sigill);
    signal(SIGSEGV, sig_sigsegv);
    signal(SIGTERM, sig_sigterm);

    int N = 0;
    while (N != 5000)
    {
        printf("%d", N);
        N++;
    }

    raise(SIGINT);
        
    system("pause");
    return 0;
}