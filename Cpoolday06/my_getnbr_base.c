#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

int find_position_first_digits(char const *str)
{
  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] >= '0' && str[i] <= '9')
      return (i);
  }
  return (-1);
}

int count_max_digits(char const *str)
{
  int pos = find_position_first_digits(str);
  int check = 0;

  if (pos == -1)
    return (-1);
  for (; str[pos] != '\0'; ++pos) {
    if (str[pos] >= '0' && str[pos] <= '9') {
      ++check;
    } else {
      return (check);
    }
  }
  return (check);
}

int check_is_neg(char const *str)
{
  int pos = find_position_first_digits(str);

  if (pos == -1)
    return (-1);
  else if (pos >= 1 && str[pos - 1] == '-')
    return (1);
  return (0);
}

int my_getnbr(char const *str)
{
  int pos = find_position_first_digits(str);
  int max = count_max_digits(str);
  int value = 0;

  if (pos == -1 || max > 10)
    return (0);
  else
    for (int i = 0; i != max; ++i) {
      value += str[pos] - '0';
      if (value == 2147483647 || value == -2147483648 && check_is_neg(str) != 0)
        return (value);
      value *= 10;
      ++pos;
    }
  value /= 10;
  if (check_is_neg(str) == 1)
    value *= -1;
  return (value);
}

void my_swap(char *a, char *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

size_t my_strlen(char const *str)
{
  size_t i = 0;

  for (; str[i] != '\0'; ++i);
  return (i);
}

char *my_revstr(char *str)
{
  size_t length = my_strlen(str) - 1;
  size_t mid = length / 2;

  for (size_t i = 0; i != mid; ++i) {
    my_swap(&str[i], &str[length]);
    --length;
  }
  return (str);
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

int my_compute_power_it(int n, int pow)
{
  if (pow < 0)
    return (1);
  else if (pow == 0)
    return (1);
  else
    for (int i = n; pow > 1; --pow) {
      n *= i;
    }
  return (n);
}

int binary_to_int(char const *str)
{
  int check = 0;
  int tmp = 0;
  size_t len;

  if (str[0] == '-') {
    check++;
    str++;
  }
  len = my_strlen(str);
  if (len == 0)
    return (-1);
  for (size_t i = 0; str[i] != '\0'; ++i) {
    tmp += ((str[i] - '0') * my_compute_power_it(2, (len - 1)));
    --len;
  }
  if (check == 1)
    tmp *= -1;
  return (tmp);
}

int get_value_hexa(char c)
{
  switch (c) {
    case 'A':
      return (10);
    case 'B':
      return (11);
    case 'C':
      return (12);
    case 'D':
      return (13);
    case 'E':
      return (14);
    case 'F':
      return (15);
    default:
      return (c - '0');
  }
}

int hexa_to_int(char const *str)
{
  int check = 0;
  int tmp = 0;
  size_t len;

  if (str[0] == '-') {
    check++;
    str++;
  }
  len = my_strlen(str);
  if (len == 0)
    return (-1);
  for (size_t i = 0; str[i] != '\0'; ++i) {
    tmp += (get_value_hexa(str[i]) * my_compute_power_it(16, (len - 1)));
    --len;
  }
  if (check == 1)
    tmp *= -1;
  return (tmp);
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

int my_getnbr_base(char const *str, char const *base)
{
  switch (check_base(base)) {
    case 0:
      return (binary_to_int(str));
    case 2:
      return (my_getnbr(str));
    case 3:
      return (hexa_to_int(str));
    default:
      return (1);
  }
}

int main(void)
{
  printf("The result should be 123 = %d\n", my_getnbr_base("1111011", "01"));
  printf("The result should be -123 = %d\n", my_getnbr_base("-1111011", "01"));
  printf("The result should be 10 = %d\n", my_getnbr_base("1010", "01"));
  printf("The result should be 6 = %d\n", my_getnbr_base("110", "01"));
  printf("The result should be 0 = %d\n", my_getnbr_base("0", "01"));
  printf("The result should be 2147483647 = %d\n", my_getnbr_base("1111111111111111111111111111111", "01"));
  printf("The result should be -2147483648 = %d\n", my_getnbr_base("-10000000000000000000000000000000", "01"));
  my_putchar('\n');
  printf("The result should be 38 = %d\n", my_getnbr_base("38", "0123456789"));
  printf("The result should be 0 = %d\n", my_getnbr_base("0", "0123456789"));
  printf("The result should be -38 = %d\n", my_getnbr_base("-38", "0123456789"));
  printf("The result should be 2147483647 = %d\n", my_getnbr_base("2147483647", "0123456789"));
  printf("The result should be -2147483648 = %d\n", my_getnbr_base("-2147483648", "0123456789"));
  printf("The result should be -1 = %d\n", my_getnbr_base("-2147483649", "0123456789"));
  my_putchar('\n');
  printf("The result should be 23813 = %d\n", my_getnbr_base("5D05", "0123456789ABCDEF"));
  printf("The result should be 38821 = %d\n", my_getnbr_base("97A5", "0123456789ABCDEF"));
  printf("The result should be 0 = %d\n", my_getnbr_base("0", "0123456789ABCDEF"));
  printf("The result should be -38 = %d\n", my_getnbr_base("-26", "0123456789ABCDEF"));
  printf("The result should be 2147483647 = %d\n", my_getnbr_base("7FFFFFFF", "0123456789ABCDEF"));
  printf("The result should be -2147483648 = %d\n", my_getnbr_base("-80000000", "0123456789ABCDEF"));
  printf("The result should be -1 = %d\n", my_getnbr_base("-1", "0123456789ABCDEF"));
  return (0);
}
