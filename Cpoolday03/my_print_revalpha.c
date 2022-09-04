#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

int my_print_revalpha(void)
{
  for (char c = 'z'; c >= 'a'; --c)
    my_putchar(c);
  return (0);
}

int main()
{
  my_print_revalpha();
  return (0);
}
