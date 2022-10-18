#include "linked_list.h"

linked_list_t *give_last_element(linked_list_t **begin)
{
  linked_list_t *tmp = *begin;
  linked_list_t *res;

  if ((*begin) == NULL)
    return (NULL);
  else if (my_list_size(tmp) == 1) {
    *begin = NULL;
    return (tmp);
  }
  while (tmp->next->next != NULL)
    tmp = tmp->next;
  res = tmp->next;
  tmp->next = NULL;
  return (res);
}

void my_rev_list(linked_list_t **begin)
{
  linked_list_t *last = give_last_element(begin);
  linked_list_t *first = last;
  int size = my_list_size(*begin);

  while (*begin) {
    last->next = give_last_element(begin);
    last = last->next;
  }
  *begin = first;
}
