#include <stdio.h>
#include <unistd.h>

int check_value(int a, int b)
{
  if (a > b)
    return (1);
  return (0);
}

void my_sort_int_array(int *array, int size)
{
  for (int i = 0; i < (size - 1); ++i) {
    if (check_value(array[i], array[i + 1]) == 1) {
      my_swap(&array[i], &array[i + 1]);
      i = -1;
    }
  }
}
