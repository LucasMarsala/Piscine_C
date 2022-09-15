#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
  for (int i = 0; s1[i] != '\0' || s2[i] != '\0' && n > 0; ++i) {
    if (s1[i] != s2[i]) {
      return (s1[i] - s2[i]);
    }
    --n;
  }
  return (0);
}

int main(void)
{
  printf("Result should be %d = %d\n", strncmp("HelloCava?", "Cavazertyuiop", 4), my_strncmp("HelloCava?", "Cavazertyuiop", 2));
  printf("Result should be %d = %d\n", strncmp("HelloCava?", "Zaza", 4), my_strncmp("HelloCava?", "Zaza", 4));
  printf("Result should be %d = %d\n", strncmp("HelloCa?", "HelloCa?", 3), my_strncmp("HelloCa?", "HelloCa?", 3));
  printf("Result should be %d = %d\n", strncmp("HelloCa?", "HelloCa?a", 2), my_strncmp("HelloCa?", "HelloCa?a", 2));
  printf("Result should be %d = %d\n", strncmp("HelloCa?", "HelloCa?a", 10), my_strncmp("HelloCa?", "HelloCa?a", 10));
  return (0);
}
