#include <stdio.h>
#include <stdlib.h>

void my_swap(char *a, char *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

size_t my_strlen(char const *str)
{
  size_t i = 0;

  for (; str[i] != '\0'; ++i);
  return (i);
}

char *my_revstr(char *str)
{
  size_t length = my_strlen(str) - 1;
  size_t mid = length / 2;

  for (size_t i = 0; i != mid; ++i) {
    my_swap(&str[i], &str[length]);
    --length;
  }
  return (str);
}

int main(void)
{
  char *s1 = strdup("Hello les amis !");
  char *s2 = strdup("Zebi triste");
  char *s3 = strdup("abcde");
  char *s4 = strdup("");


  printf("The first string should be displayed as follow = %s\n", "! sima sel olleH");
  printf("S1 = %s\n", my_revstr(s1));
  printf("The second string should be displayed as follow = %s\n", "etsirt ibeZ");
  printf("S2 = %s\n", my_revstr(s2));
  printf("The third string should be displayed as follow %s\n", "edcba");
  printf("S4 = %s\n", my_revstr(s3));
  printf("The fourth string should display an empty string %s\n", "");
  printf("S4 = %s\n", my_revstr(s4));
  return (0);
}
