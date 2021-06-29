#include <stdio.h>
#include <windows.h>



int count(int n, int key, int cnt)
{
    if (n < 10)
    {
        if (n == key)
            cnt += 1;
    return cnt;
    }

    

    if (n % 10 == key)
    {
        cnt += 1;
    }
    
    return count(n / 10, key, cnt);
}

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
    printf("Введите число\n");
    scanf("%d", &num);

    print(num);
    printf("\n");
    printf("%d\n", rev(num));

        int cnt = 0;
        int i;

        scanf("%d", &i);
        cnt = count(num, i, cnt);

        printf("Цифр %d в числе %d: %d\n", i, num, cnt);

    system("pause");
    return 0;
}