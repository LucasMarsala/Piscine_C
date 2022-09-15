#include <stdio.h>
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
  int i = 0;

  for (; src[i] != '\0'; ++i)
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}

int main(void)
{
  char src[11] = "HelloCava?";
  char dest[11];

  printf("Result should be HelloCava? = %s\n",   my_strcpy(dest, src));
  return (0);
}
