#include <stdio.h>
#include <windows.h>


int rev(int n)
{
    if (n < 10)
        return n;

    printf("%d ", n % 10);
    return rev(n / 10);
}

void print(int n)
{
    if (n)
    {
        print(n / 10);
        printf("%d ", n % 10);
    }
}

int main(void)
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int num;
    printf("¬ведите число\n");
    scanf("%d", &num);

    print(num);
    printf("\n");
    printf("%d\n", rev(num));


    system("pause");
    return 0;
}