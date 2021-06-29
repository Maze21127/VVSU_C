#include <iostream>
#include <windows.h>

using namespace std;

int comp(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int sum(int *nums, int size)
{
    int answer = 0;
    for (int i = 0; i < size; i++)
        answer += nums[i];
    return answer;
}

void erdoes(int *nums, int size)
{
    if (sum(nums, size) % 2 != 0)

    {
        cout << endl
             << "—умма степеней вершин не четна€, графа не существует" << endl;
        return;
    }
    for (int k = 1; k < size; k++)
    {
        int tsum = 0;
        for (int i = 0; i < k; i++)
            tsum += nums[i];
        int mas[100];
        int mi = 0;
        for (int x = k; x < size; x++)
        {
            mas[mi] = (nums[x] < k) ? nums[x] : k;
            mi++;
        }
        cout << endl;
        int right = k * (k - 1) + sum(mas, mi);
        if (tsum >= right)
        {
            cout << "√рафа не существует" << endl;
            return;
        }
        cout << "Ёлемент " << k << endl
             << "—лева " << tsum << ", —права " << k * (k - 1) << "+" << sum(mas, mi) << "=" << right << ", " << right << ">" << tsum << ", провер€ем дальше" << endl;
    }
    cout << endl
         << "√раф существует" << endl
         << endl;
    return;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true)
    {   
        char str[200] = "";
        char *istr, *istr2;

        int *nums;
        int N = 0;

        cout << endl
             << "¬ведите степенную последовательность: ";
        fgets(str, 200, stdin);

        istr2 = strtok(str, " ");
        N = 0;

        while (istr2 != NULL)
        {
            nums[N] = atoi(istr2);
            N++;
            istr2 = strtok(NULL, " ");
        }

        for (int q = 0; q < N; q++);
        qsort(nums, N, sizeof(int), comp);
        for (int q = 0; q < N; q++);

        erdoes(nums, N);
    }
}
