#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_str_isupper(char const *str)
{
  if (str == NULL)
    return (1);
  for (size_t i = 0; str[i] != '\0'; ++i)
    if (!(str[i] >= 'A' && str[i] <= 'Z'))
      return (0);
  return (1);
}
