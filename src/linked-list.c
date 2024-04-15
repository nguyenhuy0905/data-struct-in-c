#include "header/linked-list.h"
#include <stdio.h>
#include <stdlib.h>

/* private. Client code only has access to the struct linked_list
 * and none of these instance variables*/
struct _linked_list{
  node *head; 
  node *tail;
  unsigned int length;
};

/* private. Client code only has access to the struct node
 * and none of these instance variables*/
struct _node{
  node *next;
  int data;
};

/* private methods */

/* node operations */
/**
 * @brief Free all node instances stored inside the linked list
 *
 * @param self 
 * @return the next node to be removed, or NULL if all nodes have been removed
 */
node *_free_node(node *self){
  node *next = self->next;
  free(self);
  // in case someone accidentally access the node after free
  self = NULL;
  return next;
}

/* @brief: utility function to create a new node */
node *_node_new(int data){
  node *new = (node*)malloc(sizeof(node));

  if(new == NULL){
    printf("Error: memory allocation error. Maybe you ran out of memory?\n");
    exit(1);
  }
  return new;
}

/* linked list operations */

/**
 * @brief Assign default values for the newly made list
 */
void _linked_list_init(linked_list *self){
  self->head = NULL;
  self->tail = NULL;
  self->length = 0;
}

/* public methods */

linked_list *linked_list_new(){
  linked_list *new = (linked_list*)malloc(sizeof(linked_list));
  // this should never happen unless you have no big enough memory chunk left
  if(new == NULL){
    printf("Error: memory allocation error. Maybe you ran out of memory?\n");
    exit(1);
  }

  _linked_list_init(new);
  return new;
}

void linked_list_free(linked_list *self){
  node *to_free = self->head; 
  // free all nodes stored inside the linked list
  while((to_free = _free_node(to_free)) != NULL);

  free(self);
  self = NULL;
}

node *linked_list_append(linked_list *self, int value){
  node *new = _node_new(value);
  new->next = NULL;

  if(self->head == NULL){
    self->head = new;
    self->tail = new;
    self->length++;
  }

  
  return new;
}
