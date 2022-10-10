#include <unistd.h>
#include <stdio.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

void function(int n)
{
  printf("%d\n", n);
  char nbrs[n + 1];

  nbrs[n] = '\0';
  for (int i = 0; nbrs[i] != '\0'; ++i) {
    nbrs[i] = (i + '0');
    printf("%d\n", i);
    my_putchar(nbrs[i]);
  }
  printf("%s\n", nbrs);
}

int my_print_combn(int n)
{
  if (n == 0 || n > 10)
    return (1);
  else if (n == 1)
    for (int i = 0; i <= 9; ++i)
      my_putchar((i + '0'));
  else
    function(n);
  return (0);
}

int main(void)
{
  my_print_combn(0);
  my_putchar('\n');
  my_print_combn(1);
  my_putchar('\n');
  my_print_combn(3);
  my_putchar('\n');
  my_print_combn(12);
  return (0);
}
