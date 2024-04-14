#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct _linked_list linked_list;

typedef struct _node node;

linked_list *linked_list_new();

void linked_list_free(linked_list *self);

node *linked_list_append(linked_list *self, int value);

node *linked_list_insert(linked_list *self, int value, int position);

int linked_list_remove(linked_list *self, node index);

unsigned int linked_list_get_length(linked_list *self);

#endif // _LINKED_LIST_H_
