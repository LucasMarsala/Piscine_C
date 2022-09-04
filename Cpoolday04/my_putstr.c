#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

int my_putstr(char const *str)
{
  for (int i = 0; str[i] != '\0'; ++i)
    my_putchar(str[i]);
  return (0);
}

int main(void)
{
  char *s1 = "Hello les amis !";
  char *s2 = "Zebi triste";

  my_putstr(s1);
  my_putchar('\n');
  my_putstr(s2);
  my_putchar('\n');
  return (0);
}
