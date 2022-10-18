#include <stdio.h>

int my_compute_square_root(int n)
{
  for (int i = 1; i <= n; ++i)
    if ((i * i) == n)
      return (i);
  return (0);
}
