#include <stdio.h>

int my_compute_power_rec(int n, int pow)
{
  if (pow < 0)
    return (1);
  else if (pow == 0)
    return (1);
  else
    return (n * my_compute_power_rec(n , --pow));
  return (n);
}

int main(void)
{
  printf("6^5 should be 7776, result = %d\n", my_compute_power_rec(6, 5));
  return (0);
}
