#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strlowcase(char *str)
{
  for (size_t i = 0; str[i] != '\0'; ++i)
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] + 32;
  return (str);
}

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

int main(void)
{
  char s1[46] = "hey, how are you? 42WORds forty-two; fifty+one";

  printf("Result should be Hey, How Are You? 42words Forty-Two; Fifty+One = %s\n", my_strcapitalize(s1));
  printf("Result should be 0 = %d\n", strcmp("Hey, How Are You? 42words Forty-Two; Fifty+One", my_strcapitalize(s1)));
  return (0);
}
