#include <stdio.h>
#include <unistd.h>

void my_swap(int *a, int *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

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

int main(void)
{
  int array[14] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 12, 34, 13};

  printf("%s\n", "Voici les valeurs du tableau");
  for (int i = 0; i < 14; ++i)
    printf("%d\n", array[i]);
  my_sort_int_array(array, 14);
  printf("%s\n", "Voici les valeurs du tableau trié");
  for (int i = 0; i < 14; ++i)
    printf("%d\n", array[i]);
  return (0);
}
