#include <stdio.h>

int my_strlen(char const *str)
{
  int i = 0;

  for (; str[i] != '\0'; ++i);
  return (i);
}

int main(void)
{
  char *s1 = "Hello les amis !";
  char *s2 = "Zebi triste";

  printf("%s\n", "S1 should be equal to 16");
  printf("S1 = %d\n", my_strlen(s1));
  printf("%s\n", "S2 should be equal to 11");
  printf("S2 = %d\n", my_strlen(s2));
  printf("%s\n", "S3 should be equal to 0");
  printf("S3 = %d\n", my_strlen(""));
  return (0);
}
