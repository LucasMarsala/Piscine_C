#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my_params_to_array.h"

#define size_t unsigned short int

int my_show_param_array(struct info_param const *par)
{
  for (size_t i = 0; par[i].str != NULL; ++i) {
    printf("%d\n", par[i].length);
    printf("%s\n", par[i].str);
    printf("%s\n", par[i].copy);
    for (size_t a = 0; par[i].word_array[a] != NULL; ++i)
      printf("%s\n", par[i].word_array[a]);
  }
}

int main(int ac, char **av)
{
  struct info_param *info = my_params_to_array(ac, av);

  if (info == NULL)
    return (-1);
  my_show_param_array(info);
  return (0);
}
