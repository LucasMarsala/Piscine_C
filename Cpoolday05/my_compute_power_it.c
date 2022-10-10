#include <stdio.h>

int my_compute_power_it(int n, int pow)
{
  if (pow < 0)
    return (1);
  else if (pow == 0)
    return (1);
  else
    for (int i = n; pow > 1; --pow) {
      n *= i;
    }
  return (n);
}

int main(void)
{
  printf("5^5 should be 3125, result = %d\n", my_compute_power_it(5, 5));
  return (0);
}
