#include <stdio.h>

int my_compute_factorial_it(int n)
{
  if (n < 0)
    return (0);
  else if (n == 0)
    return (1);
  else
    for (int i = (n - 1); i > 1; --i)
      n *= i;
  return (n);
}

int main(void)
{
  printf("5! should be 120, result = %d\n", my_compute_factorial_it(5));
  return (0);
}
