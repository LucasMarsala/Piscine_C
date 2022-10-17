#include <stdlib.h>
#include <stdio.h>

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

int main(void)
{
  char *str = my_strdup("Hello");
  printf("%s\n", str);
  str[0] = 'B';
  printf("%s\n", str);
  free(str);
  return (0);
}
