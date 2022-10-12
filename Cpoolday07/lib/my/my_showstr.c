#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int calculate_size_int(int n)
{
    int i = 0;

    while (n != 0) {
      n /= 10;
      ++i;
    }
    return (i);
}

void change_character_lowcase(char *str, int nbr)
{
  switch ((nbr % 16)) {
    case 10:
      *str = 'a';
      break;
    case 11:
      *str = 'b';
      break;
    case 12:
      *str = 'c';
      break;
    case 13:
      *str = 'd';
      break;
    case 14:
      *str = 'e';
      break;
    case 15:
      *str = 'f';
      break;
    default:
      *str = ((nbr % 16) + '0');
  }
}

void my_revputstr(char const *str)
{
  size_t i = my_strlen(str);

  for (; i > 0; --i)
    my_putchar(str[i - 1]);
}

void char_to_hexa(char const c)
{
  size_t i = 0;
  int nbr = c;
  int len = calculate_size_int(nbr);
  char str[len + 1];

  for (; nbr != 0; nbr /= 16) {
    change_character_lowcase(&str[i], nbr);
    ++i;
  }
  str[i] = '\0';
  my_putchar('\\');
  my_putchar('0');
  my_revputstr(str);
}

int my_showstr(char const *str)
{
  for (size_t i = 0; str[i] != '\0'; ++i) {
    if ((str[i] >= ' ' && str[i] <= '~'))
      my_putchar(str[i]);
    else
      char_to_hexa(str[i]);
  }
  return (0);
}
