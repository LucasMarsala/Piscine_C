#include "linked_list.h"

int my_list_size(linked_list_t const *begin)
{
  size_t i = 0;
  linked_list_t *tmp = begin;

  for (; tmp != NULL; ++i) {
    tmp = tmp->next;
  }
  return (i);
}
