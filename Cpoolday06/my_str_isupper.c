#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_str_isupper(char const *str)
{
  if (str == NULL)
    return (1);
  for (size_t i = 0; str[i] != '\0'; ++i)
    if (!(str[i] >= 'A' && str[i] <= 'Z'))
      return (0);
  return (1);
}

int main(void)
{

  printf("Result should be 0 %d\n", my_str_isupper("azetyuiop"));
  printf("Result should be 0 %d\n", my_str_isupper("azetyuiopA"));
  printf("Result should be 0 %d\n", my_str_isupper("12345678"));
  printf("Result should be 1 %d\n", my_str_isupper(""));
  printf("Result should be 1 %d\n", my_str_isupper("HELLO"));
  printf("Result should be 0 %d\n", my_str_isupper("1234ety78"));
  return (0);
}
