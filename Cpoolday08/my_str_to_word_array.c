#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define size_t unsigned short int

int check_is_non_alphanum(char c)
{
  if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    return (-1);
  return (0);
}

size_t count_words(char const *str)
{
  size_t nb = 0;
  size_t i = 0;
  int check = 0;

  for (; str[i] != '\0'; ++i) {
    if ((check_is_non_alphanum(str[i]) == -1) && check == 0) {
      check = 1;
      nb++;
    } else
      check = 1;
  }
  if (check_is_non_alphanum(str[i]) == 0)
    nb++;
  return (nb);
}

// int *count_size_words(size_t nb, char const *str)
// {
//   size_t pos = 0;
//   size_t check = 0;
//   int *size = malloc(sizeof(int) * (nb));
//
//   if (size == NULL)
//     return (NULL);
//   for (size_t i = 0; str[i] != '\0'; ++i) {
//     if (check_is_non_alphanum(str[i]) == -1) {
//       size[pos] = check;
//       pos++;
//       check = 0;
//     } else
//       check++;
//   }
//   return (size);
// }

// char **fill_tab(char **tab, char const *str, size_t nb)
// {
//   size_t i = 0;
//   size_t c;
//
//   for (size_t l = 0; l <= nb; ++l) {
//     c = 0;
//     for (; str[i] != '\0'; ++c) {
//       if (check_is_non_alphanum(str[i]) == -1) {
//         tab[l][c] = '\0';
//         ++i;
//         break;
//       } else {
//         tab[l][c] = str[i];
//       }
//       ++i;
//     }
//   }
//
//   return (tab);
// }

void display_size_words(int *size_words, size_t nbr_words)
{
  for (size_t i = 0; i < nbr_words; ++i)
    printf("%d\n", size_words[i]);
}

char **my_str_to_word_array(char const *str)
{
  size_t nbr_words;
  int *size_words;
  char **tab;

  if (str == NULL || str[0] == '\0')
    return (NULL);
  nbr_words = count_words(str);
  printf("nbr words = %d\n", nbr_words);
  // size_words = count_size_words(nbr_words, str);
  // display_size_words(size_words, nbr_words);
  // tab = malloc(sizeof(char *) * (nbr_words + 2));
  // if (tab == NULL)
  //   return (NULL);
  // if (tab == NULL)
  //   return (NULL);
  // tab[nbr_words] = NULL;
  // for (size_t i = 0; i <= nbr_words; ++i) {
  //   tab[i] = malloc(sizeof(char) * (size_words[i] + 2));
  //   if (tab[i] == NULL)
  //     return (NULL);
  //   tab[i][0] = '\0';
  // }
  // free(size_words);
  return (NULL);
  // return (fill_tab(tab, str, nbr_words));
}

int main(void)
{
  // char *str = "Hello les amis";
  char *str = "Hello les amis";
  char **tab = my_str_to_word_array(str);

  if (tab == NULL)
    return (-1);
  for (size_t i = 0; tab[i] != NULL; ++i)
    printf("%s\n", tab[i]);
  for (size_t i = 0; tab[i] != NULL; ++i)
    free(tab[i]);
  free(tab);
  return (0);
}
