#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int x = 0;
  int result = 0;

  printf("¬ведите число дл€ получени€ единичных бит: ");
  scanf("%d", &x);

  while (x)
  {
    result++;
    x &= x - 1;
  }
  printf("%d\n", result);
  system("pause");
  return 0;
}