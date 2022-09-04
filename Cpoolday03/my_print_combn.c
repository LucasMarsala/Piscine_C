#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

void display_characters(char a, char b, char c)
{
  if (a == '7' && b == '8' && c == '9') {
    my_putchar(a);
    my_putchar(b);
    my_putchar(c);
  } else {
    my_putchar(a);
    my_putchar(b);
    my_putchar(c);
    my_putchar(',');
    my_putchar(' ');
  }
}

int my_print_combn(int n)
{
  return (0);
}

int main()
{
  my_print_combn(3);
  return (0);
}
