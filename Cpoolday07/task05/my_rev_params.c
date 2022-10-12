#define NULL ((void*)0)
#define size_t unsigned short int

int main(int ac, char **av)
{
  for (size_t i = ac; i > 0; --i) {
    my_putstr(av[i - 1]);
    my_putchar('\n');
  }
  return (0);
}
