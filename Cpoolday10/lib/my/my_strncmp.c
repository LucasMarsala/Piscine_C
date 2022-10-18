#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
  for (int i = 0; (s1[i] != '\0' || s2[i] != '\0') && n > 0; ++i) {
    if (s1[i] != s2[i]) {
      return (s1[i] - s2[i]);
    }
    --n;
  }
  return (0);
}
