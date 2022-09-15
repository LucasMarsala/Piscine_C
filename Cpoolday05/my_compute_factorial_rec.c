#include <stdio.h>

int my_compute_factorial_rec(int n)
{
  if (n < 0)
    return (0);
  else if (n == 0)
    return (1);
  else
    return (n * my_compute_factorial_rec(n - 1));
  return (n);
}

int main(void)
{
  printf("10! should be 3628800, result = %d\n", my_compute_factorial_rec(10));
  return (0);
}
