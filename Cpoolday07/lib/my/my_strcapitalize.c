#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcapitalize(char *str)
{
  int check = 0;

  str = my_strlowcase(str);
  for (size_t i = 0; str[i] != '\0'; ++i) {
    if ((str[i] >= 'a' && str[i] <= 'z') && check == 0) {
      str[i] = str[i] - 32;
      check = 1;
    } else if (str[i] >= '0' && str[i] <= '9')
      check = 1;
    else if (!(str[i] >= 'a' && str[i] <= 'z') && check > 0)
      check = 0;
  }
  return (str);
}
