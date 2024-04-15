#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/**
 * @typedef _linked_list
 * @brief A singly-linked list
 *
 */
typedef struct _linked_list linked_list;

/**
 * @typedef _node
 * @brief A node inside the linked list.
 * NEVER assign the node pointer to another linked list,
 * since all nodes in one linked list will be removed when
 * calling linked_list_free()
 *
 */
typedef struct _node node;

/**
 * @brief Create a new instance of linked list
 */
linked_list *linked_list_new();

/**
 * @brief free the linked list passed in
 */
void linked_list_free(linked_list *self);

node *linked_list_append(linked_list *self, int value);

node *linked_list_insert(linked_list *self, int value, int position);

int linked_list_remove(linked_list *self, node index);

unsigned int linked_list_get_length(linked_list *self);

#endif // _LINKED_LIST_H_
