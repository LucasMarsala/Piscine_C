#include <stdio.h>
#include <stdlib.h>

int get_length(char const *str)
{
  int i = 0;

  for (; str[i] != '\0'; ++i);
  return (i);
}


char *my_strncpy(char *dest, char const *src, int n)
{
  int i = 0;
  int length = get_length(src);

  if (n > length)
    dest[length] = '\0';
  for (; src[i] != '\0' && i < n; ++i)
    dest[i] = src[i];
  return (dest);
}

int main(void)
{
  char src[11] = "HelloCava?";
  char *dest = malloc(sizeof(char) * 6);

  if (dest == NULL)
    return (1);
  printf("Result should be HelloCava? = %s\n",   my_strncpy(dest, src, 6));
  printf("%s\n", dest);
  return (0);
}
