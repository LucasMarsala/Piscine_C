#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

void display_characters(char a, char b, char c, char d)
{
  if (a == '9' && b == '8' && c == '9' && d == '9') {
    my_putchar(a);
    my_putchar(b);
    my_putchar(' ');
    my_putchar(c);
    my_putchar(d);
  } else {
    my_putchar(a);
    my_putchar(b);
    my_putchar(' ');
    my_putchar(c);
    my_putchar(d);
    my_putchar(',');
    my_putchar(' ');
  }
}

int my_print_comb2(void)
{
  char b = '0';
  char c = '0';
  char d = '0';

  for (char a = '0'; a <= '9'; ++a) {
    for (; b <= '9'; ++b) {
      for (; c <= '9'; ++c) {
        for (; d <= '9'; ++d)
        if ((b != d) && (b < d))
          display_characters(a, b, c, d);
        d = '0';
      }
      c = '0';
    }
    b = '0';
  }
  return (0);
}

int main()
{
  my_print_comb2();
  return (0);
}
