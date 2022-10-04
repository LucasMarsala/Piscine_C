#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char const *str)
{
  int i = 0;

  for (; str[i] != '\0'; ++i);
  return (i);
}

int check_str(char *str, char const *to_find, int pos)
{
  for (size_t i = 0; str[pos] != '\0' && to_find[i] != '\0'; ++pos) {
    if (str[pos] != to_find[i])
      return (-1);
    ++i;
  }
  return (0);
}

int find_first_pos(char *str, char const *to_find)
{
  int i = 0;

  for (size_t first = 0; str[i] != '\0'; ++i)
    if (to_find[first] == str[i])
      return (i);
  return (-1);
}

char *move_pointer(char *str, int pos)
{
  size_t i = 0;

  while (i < pos) {
    ++i;
    ++str;
  }
  return (str);
}

char *my_strstr(char *str, char const *to_find)
{
  int pos = find_first_pos(str, to_find);

  if ((my_strlen(to_find) > my_strlen(str)) || pos == -1)
    return (NULL);
  else if (check_str(str, to_find, pos) == -1)
    return (NULL);
  return (move_pointer(str, pos));
}

int main(void)
{
  printf("Result should be %s = %s\n", strstr("HelloCava?", "Cavazertyuiop"), my_strstr("HelloCava?", "Cavazertyuiop"));
  printf("Result should be %s = %s\n", strstr("HelloCava?", "Zaza"), my_strstr("HelloCava?", "Zaza"));
  printf("Result should be %s = %s\n", strstr("HelloCa?", "Cava"),  my_strstr("HelloCa?", "Cava"));
  printf("Result should be %s = %s\n", strstr("HelloCava?", "Cava"),  my_strstr("HelloCava?", "Cava"));
  return (0);
}
