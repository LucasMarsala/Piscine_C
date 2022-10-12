#include <stdio.h>

char *my_strcat(char *dest, char const *src)
{
  int length = (my_strlen(src) - 1);
  size_t i = 0;

  for (; src[i] != '\0' ; ++i)
    dest[(length + i)] = src[i];
  dest[(length + i)] = '\0';
  return (dest);
}
