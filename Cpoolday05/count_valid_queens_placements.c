#include <stdio.h>
#include <unistd.h>

// void print_tab(int const n, char tab[n][n + 1], int const size)
// {
//   for (int l = 0; l < n; ++l)
//     printf("%s\n", tab[l]);
// }
//
// int verify_placement(int n, char tab[n][n + 1], int *pos)
// {
//   for (int l = pos[0]; l < n; ++l)
//     for (int c = pos[1]; c < n; ++c)
//       tab[l][c] =
// }

// int place_queens(int n, char tab[n][n + 1], int size)
// {
//   int pos[2];
//
//   for (int l = 0; l < n; ++l) {
//     pos[0] = l;
//     for (int c = 0; c < n; ++c) {
//       pos[1] = c;
//       if (verify_placement(n, tab, pos) == 0) {
//         tab[l][c] = 'Q';
//       }
//     }
//   }
//   print_tab(n, tab, (n*n));
//   return (0);
// }

// int count_valid_queens_placements(int n)
// {
//   int chessboard_size = n * n;
//   char tab[n][n + 1];
//
//   for (int l = 0; l < n; ++l) {
//     for (int c = 0; c < n; ++c)
//       tab[l][c] = 'o';
//     tab[l][n] = '\0';
//   }
//   // tab[0][0] = 'Q';
//   print_tab(n, tab, chessboard_size);
//   return (count(tab));
//   // return (place_queens(n, tab, chessboard_size));
// }

void print_tab(char *tab, int n)
{
  int length = (n * n);

  for (int i = 0; tab[i] != '\0'; ++i) {
    if (i > 0 && ((n % i) != 0)) {
      // printf("i = %d\n", i);
      // printf("(l mod i) = %d\n", (length % i));
      printf("%c ", tab[i]);
    } else
      printf("%c", '\n');
  }
}

int check_right(char *tab, int n, int pos)
{
  for (int i = (pos % n); i < n; ++i) {
    if (tab[pos] == 'Q')
      return (1);
  }
  return (0);
}

int check_left(char *tab, int n, int pos)
{
  for (; (pos % n) > 0; --pos) {
    if (tab[pos] == 'Q')
      return (1);
  }
  return (0);
}

// int check_up()
// int check_down()
// int check_diag()
int count(char *tab, int n, int pos)
{
  int count = 0;
  printf("N = %d\n", n);
  //printf("Right = %d, Left = %d\n", check_right(tab, n, pos), check_left(tab, n, pos));
  // if (check_right(tab, n, pos) == 0 && check_left(tab, n, pos) == 0) {
  //   tab[pos] = 'Q';
  //   ++count;
  // }
  print_tab(tab, n);
  return (count);
}

int count_valid_queens_placements(int n)
{
  int length = (n * n);
  char tab[(length + 1)];

  for (int i = 0; i < length; ++i)
    tab[i] = 'o';
  tab[length] = '\0';
  return (count(tab, n, 0));
}

int main(void)
{
  count_valid_queens_placements(5);
  return (0);
}
