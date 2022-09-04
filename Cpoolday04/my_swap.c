#include <stdio.h>

void my_swap(int *a, int *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

int main(void)
{
  int a = 10;
  int b = 3;

  printf("a = %d b = %d\n", a, b);
  my_swap(&a, &b);
  printf("after swap a = %d b = %d\n", a, b);
  my_swap(&a, &b);
  printf("after swap a = %d b = %d\n", a, b);
  return (0);
}
