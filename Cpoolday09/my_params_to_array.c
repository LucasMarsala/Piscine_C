#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my_params_to_array.h"

#define size_t unsigned short int

int my_strlen(char const *str)
{
  int i = 0;

  for (; str[i] != '\0'; ++i);
  return (i);
}

char *my_strcpy(char *dest, char const *src)
{
  size_t i = 0;

  for (; src[i] != '\0'; ++i)
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}

char *my_strdup(char const *src)
{
  char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

  if (str == NULL)
    return (NULL);
  my_strcpy(str, src);
  return (str);
}

struct info_param *my_params_to_array(int ac, char **av)
{
  struct info_param *info = malloc(sizeof(struct info_param) * (ac + 1));
  size_t i = 0;

  if (info == NULL)
    return (NULL);
  for (; i < ac; i++) {
    info[i].length = my_strlen(av[i]);
    info[i].str = av[i];
    info[i].copy = my_strdup(av[i]);
    info[i].word_array = my_str_to_word_array(av[i]);
  }
  info[i].length = 0;
  info[i].str = NULL;
  info[i].copy = NULL;
  info[i].word_array = NULL;
  return (info);
}

int main(int ac, char **av)
{
  struct info_param *info = my_params_to_array(ac, av);

  if (info == NULL)
    return (-1);
  for (size_t i = 0; i < ac; ++i) {
    printf("%d\n", info[i].length);
    printf("%s\n", info[i].str);
    printf("%s\n", info[i].copy);
  }
  return (0);
}
