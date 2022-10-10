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
  return (0);
}
