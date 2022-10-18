#include <string.h>

void my_swap_char(char *a, char *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

char *my_revstr(char *str)
{
  size_t length = my_strlen(str) - 1;

  for (size_t i = 0; i < length ; ++i) {
    my_swap_char(&str[i], &str[length]);
    --length;
  }
  return (str);
}
