#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "main.h"

int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  int a, b, c;

  printf("������� a: ");
  scanf("%d", &a);

  printf("������� b: ");
  scanf("%d", &b);

  printf("������� c: ");
  scanf("%d", &c);

  if (isexist(a, b, c))
  {
    double square = calculate_s(a, b, c);
    int p = calculate_perim(a, b, c);
    printf("������� = %lf\n", square);
    printf("�������� = %d\n", p);
  }
  else printf("������ ������������ �� ������\n");

  system("pause");
  
  return 0;
}
