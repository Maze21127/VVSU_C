#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "main.h"

int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  int a, b, c;

  printf("Введите a: ");
  scanf("%d", &a);

  printf("Введите b: ");
  scanf("%d", &b);

  printf("Введите c: ");
  scanf("%d", &c);

  if (isexist(a, b, c))
  {
    double square = calculate_s(a, b, c);
    int p = calculate_perim(a, b, c);
    printf("Площадь = %lf\n", square);
    printf("Периметр = %d\n", p);
  }
  else printf("Такого треугольника не бывает\n");

  system("pause");
  
  return 0;
}
