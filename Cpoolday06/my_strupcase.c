#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strupcase(char *str)
{
  for (size_t i = 0; str[i] != '\0'; ++i)
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] - 32;
  return (str);
}

int main(void)
{
  char s1[6] = "Hello";
  char s2[5] = "zebi";
  char s3[11] = "AZErtyUIop";
  char s4[9] = "HelloCa?";

  printf("Result should be HELLO = %s\n", my_strupcase(s1));
  printf("Result should be ZEBI = %s\n",  my_strupcase(s2));
  printf("Result should be AZERTYUIOP = %s\n", my_strupcase(s3));
  printf("Result should be HELLOCA? = %s\n", my_strupcase(s4));
  return (0);
}
