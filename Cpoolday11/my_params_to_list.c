#include "linked_list.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
  linked_list_t *ptr;
  linked_list_t *tmp = NULL;

  for (size_t i = 0; i < ac; ++i) {
    ptr = malloc(sizeof(linked_list_t));
    if (ptr == NULL)
      return (NULL);
    ptr->data = av[i];
    ptr->next = tmp;
    tmp = ptr;
  }
  return (ptr);
}
