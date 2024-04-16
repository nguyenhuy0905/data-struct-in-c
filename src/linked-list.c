#include "header/linked-list.h"
#include "header/err-handler.h"
#include <asm-generic/errno-base.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct {
  node *next;
} linked_list_iterator;

/* private. Client code only has access to the struct linked_list
 * and none of these instance variables*/
struct _linked_list {
  node *head;
  node *tail;
  unsigned int length;
  linked_list_iterator *iter;
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
    printf("\n\033[31mMemory allocation error. Maybe you ran out of memory?\n\n");
    errno = ENOMEM;
    DIAGNOSTIC_INFO(__func__);
    exit(1);
  }
  return new;
}

node *_node_get(linked_list *self, unsigned int index) {
  if (self->length <= index || index < 0) {
    printf("\n\033[31mAccessing memory out of bounds\nMinimum 0, maximum %d, accessing index %d\n\n",
           self->length - 1, index);
    errno = ERANGE;
    DIAGNOSTIC_INFO(__func__);
    exit(1);
  }
  node *ret = self->head;
  while (index > 0) {
    if(ret == NULL){
      printf("\n\033[31mNull pointer\nAt index %d\n\n", index);
      errno = EFAULT;
      DIAGNOSTIC_INFO(__func__);
      exit(1);
    }
    ret = ret->next;
    index--;
  }
  return ret;
}

/* iterator operations */

/* linked list operations */

/**
 * @brief Assign default values for the newly made list
 */
void _linked_list_init(linked_list *self) {
  self->head = NULL;
  self->tail = NULL;
  self->length = 0;
  self->iter = NULL;
}

/**
 * @brief Check whether the linked list passed in is NULL
 *
 * @return the linked list if not null, or crash the program otherwise
 */
linked_list *_check_null(linked_list *self, const char *func){
  if(self != NULL) return self;
  printf("\n\033[31mNull pointer\n\n");
  errno = EFAULT;
  DIAGNOSTIC_INFO(func);
  exit(1);
  return NULL;
}

/* public methods */

linked_list *linked_list_new() {
  linked_list *new = (linked_list *)malloc(sizeof(linked_list));
  // this should never happen unless you have no big enough memory chunk left
  if (new == NULL) {
    printf("\n\033[31mMemory allocation error. Maybe you ran out of memory?\n\n");
    errno = ENOMEM;
    DIAGNOSTIC_INFO(__func__);
    linked_list_free(new);
    exit(1);
  }
  if (_before_head == NULL) {
    _before_head = _node_new(0);
  }

  _linked_list_init(new);
  return new;
}

void linked_list_free(linked_list *self) {
  _check_null(self, __func__);
  node *to_free = self->head;
  // free all nodes stored inside the linked list
  while ((to_free = _node_free(to_free)) != NULL)
    ;
  free(_before_head);
  _before_head = NULL;

  free(self);
  self = NULL;
}

node *linked_list_append(linked_list *self, int value) {
  _check_null(self, __func__);
  return linked_list_insert(self, self->length, value);
}

node *linked_list_insert(linked_list *self, unsigned int index, int value) {
  _check_null(self, __func__);
  if (self->length < index || index < 0) {
    printf("\033[31mAccessing memory out of bounds\nMinimum 0, maximum %d, accessing %d\n\n",
           self->length, index);
    errno = ERANGE;
    DIAGNOSTIC_INFO(__func__);
    linked_list_free(self);
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
  if (prev == NULL) {
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
  // insert to head when the list isn't empty
  if (prev == _before_head) {
    new->next = self->head;
    self->head = new;
    self->length++;
    return new;
  }
  // insert in the middle
  new->next = prev->next;
  prev->next = new;
  self->length++;
  return new;
}

int linked_list_remove(linked_list *self, unsigned int index) {
  _check_null(self, __func__);
  if (self->length <= index || index < 0) {
    printf("\033[31mAccessing memory out of bounds\nMinimum 0, maximum %d, accessing %d\n\n",
           self->length - 1, index);
    errno = ERANGE;
    DIAGNOSTIC_INFO(__func__);
    linked_list_free(self);
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

int linked_list_get_value(linked_list *self, unsigned int index) {
  _check_null(self, __func__);
  return _node_get(self, index)->data;
}

unsigned int linked_list_get_length(linked_list *self){
  _check_null(self, __func__);
  return self->length;
}

void linked_list_print(linked_list *self) {
  _check_null(self, __func__);
  node *curr = self->head;
  printf("The linked list is as follow:\n");
  while (curr != NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
}

int linked_list_iteraton_next(linked_list *self){
  _check_null(self, __func__);
  return self->iter->next->data;
}

void linked_list_start_iteration(linked_list *self){
  _check_null(self, __func__);
  if(self->iter == NULL){
    self->iter = (linked_list_iterator*)malloc(sizeof(linked_list_iterator));
  }
  self->iter->next = self->head;
}

void linked_list_end_iteraton(linked_list *self){
  _check_null(self, __func__);
  if(self->iter == NULL)
    return;
  free(self->iter);
  self->iter = NULL;
}
