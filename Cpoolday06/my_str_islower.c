#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_str_islower(char const *str)
{
  if (str == NULL)
    return (1);
  for (size_t i = 0; str[i] != '\0'; ++i)
    if (!(str[i] >= 'a' && str[i] <= 'z'))
      return (0);
  return (1);
}

int main(void)
{

  printf("Result should be 1 %d\n", my_str_islower("azetyuiop"));
  printf("Result should be 0 %d\n", my_str_islower("azetyuiopA"));
  printf("Result should be 0 %d\n", my_str_islower("12345678"));
  printf("Result should be 1 %d\n", my_str_islower(""));
  printf("Result should be 0 %d\n", my_str_islower("1234ety78"));
  return (0);
}
