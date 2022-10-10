#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

void my_putstr(char const *str)
{
  for (size_t i = 0; str[i] != '\0'; ++i)
    my_putchar(str[i]);
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

void display_nbr(int n, int length)
{
  char str[length];

  str[length] = '\0';
  for (int i = length - 1; length > 0; --i) {
    str[i] = (n % 10) + '0';
    n /= 10;
    --length;
  }
  for (int i = 0; str[i] != '\0'; ++i)
    my_putchar(str[i]);
}

int my_put_nbr(int n)
{
  int length = calculate_length_int(n);

  if (n < 0) {
    my_putchar('-');
    n *= -1;
  }
  if (length == 0)
    my_putchar((n + '0'));
  else
    display_nbr(n, length);
  my_putchar('\n');
  return (0);
}

int my_strlen(char const *str)
{
  size_t i = 0;

  for (; str[i] != '\0'; ++i);
  return (i);
}

int strcmp(char const *s1, char const *s2)
{
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  for (size_t i = 0; s1[i] != '\0'; ++i) {
    if (s1[i] != s2[i])
      return (1);
  }
  return (0);
}

int check_base(char const *base)
{
  if (strcmp("01", base) == 0)
    return (0);
  else if (strcmp("0123456789", base) == 0)
    return (2);
  else if (strcmp("0123456789ABCDEF", base) == 0)
    return (3);
  return (1);
}

void my_revputstr(char const *str)
{
  size_t i = my_strlen(str);

  for (; i > 0; --i)
    my_putchar(str[i - 1]);
}

void display_to_binary(int nbr)
{
  int check = 0;
  size_t i = 0;
  int len = calculate_length_int(nbr);
  char str[len + 1];

  if (nbr < 0) {
    check = 1;
    nbr *= -1;
  }
  for (; nbr != 0; nbr /= 2) {
    str[i] = ((nbr % 2) + '0');
    ++i;
  }
  str[i] = '\0';
  (check = 0) ? (check = 0) : my_putchar('-');
  my_revputstr(str);
  my_putchar('\n');
}

void display_to_decimal(int nbr)
{
  my_put_nbr(nbr);
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
  int check = 0;
  size_t i = 0;
  int len = calculate_length_int(nbr);
  char str[len + 1];

  if (nbr < 0) {
    check = 1;
    nbr *= -1;
  }
  for (; nbr != 0; nbr /= 16) {
    change_character(&str[i], nbr);
    ++i;
  }
  str[i] = '\0';
  (check = 0) ? (check = 0) : my_putchar('-');
  my_revputstr(str);
  my_putchar('\n');
}

int my_putnbr_base(int nbr, char const *base)
{
  switch (check_base(base)) {
    case 0:
      display_to_binary(nbr);
      break;
    case 2:
      display_to_decimal(nbr);
      break;
    case 3:
      display_to_hexa(nbr);
      break;
    default:
      return (1);
  }
  return (0);
}

int main(void)
{
  printf("Result should be 1010 = \n");
  my_putnbr_base(10, "01");
  printf("Result should be 10 = \n");
  my_putnbr_base(10, "0123456789");
  printf("Result should be 5464E = \n");
  my_putnbr_base(345678, "0123456789ABCDEF");
  printf("Result should be 1010 = \n");
  my_putnbr_base(-389, "01");
  printf("Result should be -110000101 = \n");
  my_putnbr_base(-83173, "0123456789");
  printf("Result should be -BF58 = \n");
  my_putnbr_base(-48984, "0123456789ABCDEF");
  return (0);
}
