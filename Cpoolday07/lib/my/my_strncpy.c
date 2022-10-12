#include <stdio.h>
#include <stdlib.h>

size_t get_length(char const *str)
{
  size_t i = 0;

  for (; str[i] != '\0'; ++i);
  return (i);
}

char *my_strncpy(char *dest, char const *src, int n)
{
  size_t i = 0;
  size_t length = get_length(src);

  if (n > length)
    dest[length] = '\0';
  for (; src[i] != '\0' && i < n; ++i)
    dest[i] = src[i];
  return (dest);
}
