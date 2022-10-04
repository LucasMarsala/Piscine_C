#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_str_isprintable(char const *str)
{
  if (str == NULL)
    return (1);
  for (size_t i = 0; str[i] != '\0'; ++i)
    if (!(str[i] >= ' ' && str[i] <= '~'))
      return (0);
  return (1);
}

int main(void)
{

  printf("Result should be 1 %d\n", my_str_isprintable("azetyuiop"));
  printf("Result should be 1 %d\n", my_str_isprintable("azetyuiopA"));
  printf("Result should be 1 %d\n", my_str_isprintable("12345678"));
  printf("Result should be 1 %d\n", my_str_isprintable(""));
  printf("Result should be 1 %d\n", my_str_isprintable("1234ety78"));
  printf("Result should be 0 %d\n", my_str_isprintable("1234ety78"));
  return (0);
}
