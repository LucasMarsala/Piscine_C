#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_str_isnum(char const *str)
{
  if (str == NULL)
    return (1);
  for (size_t i = 0; str[i] != '\0'; ++i)
    if (!(str[i] >= '0' && str[i] <= '9'))
      return (0);
  return (1);
}
