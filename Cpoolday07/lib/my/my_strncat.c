#include <stdio.h>

char *my_strncat(char *dest, char const *src, int nb)
{
  int length = (my_strlen(src) - 1);
  size_t i = 0;

  for (; src[i] != '\0' && i < nb; ++i)
    dest[(length + i)] = src[i];
  if (nb != 0)
    dest[(length + i)] = '\0';
  return (dest);
}
