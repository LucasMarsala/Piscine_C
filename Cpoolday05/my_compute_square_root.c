#include <stdio.h>

int my_compute_square_root(int n)
{
  for (int i = 1; i <= n; ++i)
    if ((i * i) == n)
      return (i);
  return (0);
}

int main(void)
{
  printf("Square root of 36 sould be 6 = %d\n", my_compute_square_root(36));
  printf("Square root of 10 sould be 0 = %d\n", my_compute_square_root(10));
  printf("Square root of 1 sould be 1 = %d\n", my_compute_square_root(1));
  printf("Square root of -10 sould be 0 = %d\n", my_compute_square_root(-10));
  printf("Square root of 184156 sould be 0 = %d\n", my_compute_square_root(184156));
  printf("Square root of 184156 sould be 0 = %d\n", my_compute_square_root(1841565678));
  return (0);
}
