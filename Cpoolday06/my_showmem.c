#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

int calculate_length_int(int n)
{
    int i = 0;

    while (n != 0) {
      n /= 10;
      ++i;
    }
    return (i);
}

int my_strlen(char const *str)
{
  size_t i = 0;

  for (; str[i] != '\0'; ++i);
  return (i);
}

void my_revputstr(char const *str)
{
  size_t i = my_strlen(str);

  for (; i > 0; --i)
    my_putchar(str[i - 1]);
}

void change_character(char *str, int nbr)
{
  switch ((nbr % 16)) {
    case 10:
      *str = 'A';
      break;
    case 11:
      *str = 'B';
      break;
    case 12:
      *str = 'C';
      break;
    case 13:
      *str = 'D';
      break;
    case 14:
      *str = 'E';
      break;
    case 15:
      *str = 'F';
      break;
    default:
      *str = ((nbr % 16) + '0');
  }
}

void display_to_hexa(int nbr)
{
  size_t i = 0;
  int len = calculate_length_int(nbr);
  char str[len + 1];

  if (nbr < 0)
    nbr *= -1;
  for (; nbr != 0; nbr /= 16) {
    change_character(&str[i], nbr);
    ++i;
  }
  str[i] = '\0';
  my_revputstr(str);
}

void my_putstr(char const *str)
{
    for (size_t i = 0; str[i] != '\0'; ++i) {
      my_putchar(str[i]);
    }
}

void print_address(char const *str)
{
  my_putstr("Je suis l'adresse:");
}

void display_content(char const *str, size_t i)
{
  display_to_hexa(str[i]);
}

void my_special_putstr(char const *str)
{
  for (size_t i = 0; str[i] != '\0'; ++i) {
    my_putchar(str[i]);
    ++str;
  }
}

int my_showmem(char const *str, int size)
{
  char tmp[16];

  print_address(str);
  for (size_t i = 0; str[i] != '\0'; ++i) {
    if ((i % 16) == 0 && i > 2) {
      my_putchar(' ');
      my_special_putstr(tmp);
      tmp[16];
      my_putchar('\n');
      print_address(str);
      my_putchar(' ');
    } else if (((i % 2) == 0))
      my_putchar(' ');
    display_content(str, i);
    tmp[i] = str[i];
  }
  return (0);
}

int main(void)
{
  my_showmem("hey guys show mem is cool you can do some pretty neat stuff", 59);
  return (0);
}
