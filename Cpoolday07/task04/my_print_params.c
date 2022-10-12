#define NULL ((void*)0)
#define size_t unsigned short int

int main(int ac, char **av)
{
  for (size_t i = 0; av[i] != NULL; ++i) {
    my_putstr(av[i]);
    my_putchar('\n');
  }
  return (0);
}
