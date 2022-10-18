#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define size_t unsigned short int

typedef struct linked_list {
  void *data;
  struct linked_list *next;
} linked_list_t;

linked_list_t *my_params_to_list(int, char * const *);
int my_list_size(linked_list_t const *begin);
void my_rev_list(linked_list_t **begin);
void my_show_list(linked_list_t *ptr);

 #endif
