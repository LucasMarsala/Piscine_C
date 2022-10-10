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

int my_print_comb(void)
{
  char b = '1';
  char c = '2';

  for (char a = '0'; a <= '7'; ++a) {
    for (; b <= '8'; ++b) {
      for (; c <= '9'; ++c)
        if ((a != b) && (a != c) && (b != c) && (a < b) && (b < c))
          display_characters(a, b, c);
      c = '0';
    }
    b = '0';
  }
  return (0);
}

int main(void)
{
  my_print_comb();
  return (0);
}
