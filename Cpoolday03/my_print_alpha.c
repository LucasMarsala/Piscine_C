#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

int my_print_alpha(void)
{
  for (char c = 'a'; c <= 'z'; ++c)
    my_putchar(c);
  return (0);
}

int main()
{
  my_print_alpha();
  return (0);
}
