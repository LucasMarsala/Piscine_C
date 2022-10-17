#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define size_t unsigned short int

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

int my_show_word_array(char * const *tab)
{
  for (size_t i = 0; tab[i] != NULL; ++i) {
    my_putstr(tab[i]);
    my_putchar('\n');
  }
}

int main(void)
{
  char *test_word_array[] = {"The ", "Answer", "to", "the", "Great", "Question...",
    "Of", "Life,", "the", "Universe", "and", " Everything...", "Is...", "Forty-two,", 0};

  my_show_word_array(test_word_array);
  return (0);
}
