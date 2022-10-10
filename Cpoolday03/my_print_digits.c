#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

int my_print_digits(void)
{
  for (char c = '0'; c <= '9'; ++c)
    my_putchar(c);
  return (0);
}

int main(void)
{
  my_print_digits();
  return (0);
}
