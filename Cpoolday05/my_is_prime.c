#include <stdio.h>

int my_is_prime(int n)
{
  for (int i = 2; i < n; ++i) {
    if ((n % i) == 0)
      return (0);
  }
  return (1);
}

int main(void)
{
  printf("5 is prime, result should be 1, result = %d\n", my_is_prime(5));
  printf("4 is not prime, result should be 0, result = %d\n", my_is_prime(4));
  printf("10 is not prime, result should be 0, result = %d\n", my_is_prime(10));
  printf("17 is prime, result should be 1, result = %d\n", my_is_prime(17));
  printf("97 is prime, result should be 1, result = %d\n", my_is_prime(5));
  printf("146 is not prime, result should be 0, result = %d\n", my_is_prime(146));
  return (0);
}
