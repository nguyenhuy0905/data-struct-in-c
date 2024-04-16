#include "header/linked-list.h"
#include <stdio.h>
#include <stdlib.h>

/* private. Client code only has access to the struct linked_list
 * and none of these instance variables*/
struct _linked_list {
  node *head;
  node *tail;
  unsigned int length;
};

/* private. Client code only has access to the struct node
 * and none of these instance variables*/
struct _node {
  node *next;
  int data;
};

/* private static variables */
static node *_before_head = NULL;

/* private methods */

/* node operations */
/**
 * @brief Free all node instances stored inside the linked list
 *
 * @param self
 * @return the next node to be removed, or NULL if all nodes have been removed
 */
node *_node_free(node *self) {
  node *next = self->next;
  free(self);
  // in case someone accidentally access the node after free
  self = NULL;
  return next;
}

/* @brief: utility function to create a new node */
node *_node_new(int data) {
  node *new = (node *)malloc(sizeof(node));

  if (new == NULL) {
    printf("Error: memory allocation error. Maybe you ran out of memory?\n");
    exit(1);
  }
  return new;
}

node *_node_get(linked_list *self, int index) {
  if (self->length <= index) {
    printf("Error, accessing memory out of bounds\nMaximum %d, accessing %d\n",
           self->length - 1, index);
    exit(1);
  }
  node *ret = self->head;
  while (index > 0) {
    ret = ret->next;
    index--;
  }
  return ret;
}

/* linked list operations */

/**
 * @brief Assign default values for the newly made list
 */
void _linked_list_init(linked_list *self) {
  self->head = NULL;
  self->tail = NULL;
  self->length = 0;
}

/* public methods */

linked_list *linked_list_new() {
  linked_list *new = (linked_list *)malloc(sizeof(linked_list));
  // this should never happen unless you have no big enough memory chunk left
  if (new == NULL) {
    printf("Error: memory allocation error. Maybe you ran out of memory?\n");
    exit(1);
  }
  if (_before_head == NULL) {
    _before_head = _node_new(0);
  }

  _linked_list_init(new);
  return new;
}

void linked_list_free(linked_list *self) {
  node *to_free = self->head;
  // free all nodes stored inside the linked list
  while ((to_free = _node_free(to_free)) != NULL)
    ;

  free(self);
  self = NULL;
}

node *linked_list_append(linked_list *self, int value) {
  return linked_list_insert(self, self->length, value);
}

node *linked_list_insert(linked_list *self, int index, int value) {
  if (self->length < index) {
    printf("Error, accessing memory out of bounds\nMaximum %d, accessing %d\n",
           self->length, index);
    exit(1);
  }
  _before_head->next = self->head;
  node *new = _node_new(value);
  new->data = value;
  node *prev;
  if (index == 0)
    prev = _before_head;
  else
    prev = _node_get(self, index - 1);
  // this should be the case when there is yet a node (aka, insert to head)
  if (prev == _before_head) {
    new->next = NULL;
    self->head = new;
    self->tail = new;
    self->length++;
    return new;
  }
  // insert to tail
  if (prev == self->tail) {
    new->next = NULL;
    self->tail->next = new;
    self->tail = new;
    self->length++;
    return new;
  }
  // insert in the middle
  new->next = prev->next;
  prev->next = new;
  self->length++;
  return new;
}

int linked_list_remove(linked_list *self, int index) {
  if (self->length <= index) {
    printf("Error, accessing memory out of bounds\nMaximum %d, accessing %d\n",
           self->length - 1, index);
    exit(1);
  }
  _before_head->next = self->head;
  node *rm_prev;
  if (index == 0)
    rm_prev = _before_head;
  else
    rm_prev = _node_get(self, index - 1);
  int ret = rm_prev->next->data;
  node *new_next = rm_prev->next->next;
  free(rm_prev->next);
  rm_prev->next = new_next;
  if (rm_prev == _before_head)
    self->head = rm_prev->next;
  self->length--;
  if (self->length == 1)
    self->tail = rm_prev->next;
  return ret;
}

int linked_list_get_value(linked_list *self, int index) {
  return _node_get(self, index)->data;
}

void linked_list_print(linked_list *self) {
  node *curr = self->head;
  printf("The linked list is as follow:\n");
  while (curr != NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
}
