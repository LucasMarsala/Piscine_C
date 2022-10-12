#include <stdlib.h>
#include <stdio.h>

#define size_t unsigned short int

int my_strlen(char const *str)
{
  int i = 0;

  for (; str[i] != '\0'; ++i);
  return (i);
}

char *my_strdup(char const *src)
{
  size_t i = 0;
  char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

  if (str == NULL)
    return (NULL);
  for (; src[i] != '\0'; ++i)
    str[i] = src[i];
  str[i] = '\0';
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
