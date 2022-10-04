#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strlowcase(char *str)
{
  for (size_t i = 0; str[i] != '\0'; ++i)
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] + 32;
  return (str);
}

int main(void)
{
  char s1[6] = "HeLLo";
  char s2[5] = "zeBi";
  char s3[11] = "AZERTYUIOP";
  char s4[11] = "HelloCaVA?";

  printf("Result should be hello = %s\n", my_strlowcase(s1));
  printf("Result should be zebi = %s\n",  my_strlowcase(s2));
  printf("Result should be azertyuiop = %s\n", my_strlowcase(s3));
  printf("Result should be hellocava? = %s\n", my_strlowcase(s4));
  return (0);
}
