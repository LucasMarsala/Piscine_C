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

int main(void)
{
  // char src[11] = "HelloCava?";
  // char *dest = malloc(sizeof(char) * 6);
  //
  // if (dest == NULL)
  //   return (1);
  char dest[7];
  char const *src = "Hello";
  printf("Result should be HelloCava? = %s\n",   my_strncpy(dest, src, 2));
  // printf("Result should be HelloCava? = %s\n",   my_strncpy(dest, src, 6));
  printf("%s\n", dest);
  return (0);
}
