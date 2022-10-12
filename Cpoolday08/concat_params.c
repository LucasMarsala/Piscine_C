#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// #define NULL ((void*)0)
#define size_t unsigned short int

void my_putchar(char c)
{
  write(1, &c, 1);
}

int my_putstr(char const *str)
{
  for (int i = 0; str[i] != '\0'; ++i)
    my_putchar(str[i]);
  return (0);
}

int my_strlen(char const *str)
{
  int i = 0;

  for (; str[i] != '\0'; ++i);
  return (i);
}

int calculate_length_params(int ac, char **av)
{
  size_t size;

  for (size_t i = 0; i < ac; ++i)
    size += my_strlen(av[i]);
  return (size);
}
char *concat_params(int ac, char **av)
{
  size_t size = calculate_length_params(ac, av);
  size_t len = 0;
  char *str;

  str = malloc(sizeof(char) * (size + ac));
  if (str == NULL)
    return (NULL);
  for (size_t l = 0; l < ac; ++l) {
    for (size_t c = 0; av[l][c] != '\0'; ++c) {
      str[len] = av[l][c];
      ++len;
    }
    if (l < (ac - 1)) {
      str[len] = '\n';
      ++len;
    }
  }
  str[(len + ac)] = '\0';
  return (str);
}

int main(int ac, char **av)
{
  my_putstr(concat_params(ac, av));
  return (0);
}
