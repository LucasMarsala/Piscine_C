#include <stdio.h>

int my_find_prime_sup(int n)
{
  for (; n < 2147483647; ++n) {
    if (my_is_prime(n) == 1)
      return (n);
  }
  return (1);
}
