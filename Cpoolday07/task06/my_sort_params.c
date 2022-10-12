#include <stdio.h>

#define NULL ((void*)0)
#define size_t unsigned short int

void my_swap_string(char **a, char **b)
{
  char *c;

  c = *a;
  *a = *b;
  *b = c;
}

void display_array(char const **tab)
{
  for (size_t i = 0; av[i] != NULL; ++i) {
    my_putstr(av[i]);
    my_putchar('\n');
  }
}

void sort_params(char **av)
{
  for (size_t i = 1; av[i] != NULL; ++i) {
    for (size_t l = 0; av[i][l] != '\0' && av[i - 1][l] != '\0'; ++l) {
      if (my_strcmp(av[i], av[i - 1]) < 0) {
        my_swap_string(&av[i], &av[i - 1]);
        check = 1;
      }
    }
    if (check == 1) {
      i = 0;
      check = 0;
    }
  }
}

int main(int ac, char **av)
{
  int check = 0;

  if (ac < 2) {
    my_putstr(av[0]);
    my_putchar('\n');
    return (0);
  }
  sort_params(av);
  display_array(av);
  return (0);
}
