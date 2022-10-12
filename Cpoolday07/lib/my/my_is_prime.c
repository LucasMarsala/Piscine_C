#include <stdio.h>

int my_is_prime(int n)
{
  for (int i = 2; i < n; ++i) {
    if ((n % i) == 0)
      return (0);
  }
  return (1);
}
