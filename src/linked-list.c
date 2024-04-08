#include "header/linked-list.h"
#include "header/iterator.h"
#include <stdio.h>
#include <stdlib.h>

struct _linked_list {
  node *head;
  node *tail;
  unsigned int length;
  iterator *iter;
};

struct _node {
  node *next;
  int value;
};

linked_list *linked_list_new() {
  linked_list *new = malloc(sizeof(linked_list));
  new->head = NULL;
  new->tail = NULL;
  new->iter = NULL;
  new->length = 0;
  return new;
}

node *linked_list_append(linked_list *self, int value) {
  node *new = malloc(sizeof(node));
  new->value = value;
  if (self->head == NULL) {
    self->head = new;
    self->tail = new;
  }
  new->next = NULL;
  self->length++;
  return new;
}

void linked_list_iterate(linked_list *self, void (*iterate_action)(void **),
                         void **args) {
  if (self->iter == NULL) {
    self->iter = iterator_new();
  }
  while (iterator_next(self->iter) != NULL) {
    iterate_action(args);
  }
}
