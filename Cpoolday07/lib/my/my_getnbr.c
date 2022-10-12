#include <stdio.h>

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
      if ((value == 2147483647 || value == -2147483648) && check_is_neg(str) != 0)
        return (value);
      value *= 10;
      ++pos;
    }
  value /= 10;
  if (check_is_neg(str) == 1)
    value *= -1;
  return (value);
}
