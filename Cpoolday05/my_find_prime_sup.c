#include <stdio.h>

int my_is_prime(int n)
{
  for (int i = 2; i < n; ++i) {
    if ((n % i) == 0)
      return (0);
  }
  return (1);
}

int my_find_prime_sup(int n)
{
  for (; n < 2147483647; ++n) {
    if (my_is_prime(n) == 1)
      return (n);
  }
  return (1);
}

int main(void)
{
  printf("86 is prime, result should be 89, result = %d\n", my_find_prime_sup(86));
  printf("90 is prime, result should be 97, result = %d\n", my_find_prime_sup(90));
  return (0);
}
