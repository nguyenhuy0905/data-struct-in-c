#ifndef _DATASTRUCT_IN_C_LINKED_LIST_H_
#define _DATASTRUCT_IN_C_LINKED_LIST_H_

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
typedef struct _linked_list_node linked_list_node;

/**
 * @typedef _linked_list_iterator
 * @brief An iterator that runs across the linked list
 *
 */
typedef struct _linked_list_iterator linked_list_iterator;

/**
 * @brief Create a new instance of linked list
 */
linked_list *linked_list_new();

/**
 * @brief free the linked list passed in
 */
void linked_list_free(linked_list *self);

/**
 * @brief Add a node to the end of the list
 *
 * @return The newly created node inside the list
 */
linked_list_node *linked_list_append(linked_list *self, int value);

/**
 * @brief Add a node to the position specified in the list
 *
 * @param index: position to insert
 * @param value: value to insert
 * @return The pointer to the newly created node inside the list
 */
linked_list_node *linked_list_insert(linked_list *self, unsigned int index, int value);

/**
 * @brief Remove the node at the specified position in the list
 *
 * @param index: position to remove
 * @return The value of the node just removed
 */
int linked_list_remove(linked_list *self, unsigned int index);

/**
 * @brief Get the length of the list
 */
unsigned int linked_list_get_length(linked_list *self);

/**
 * @brief Get the value stored at the specified index in the list
 *
 * @param index: position to get value from
 */
int linked_list_get_value(linked_list *self, unsigned int index);

/**
 * @brief Override the value at the specified position in the list
 *
 * @param index: the index to modify value
 * @param value: the new value at the specified position
 * @return The pointer to the node just modified
 */
linked_list_node *linked_list_set_value(linked_list *self, unsigned int index, int value);

/**
 * @brief Print out the order inside the list
 */
void linked_list_print(linked_list *self);

/**
 * @brief Set up an iterator for the list
 *
 * @return The pointer to the iterator just set up
 */
linked_list_iterator *linked_list_start_iteration(linked_list *self);

/**
 * @brief Write the value of the next node pointed to by the iterator to the
 * paramter passed in, and increment the iterator by one position. Iterator is
 * destroyed if the list has reached the end or if the iterator meets a NULL
 * node
 *
 * @param out: the variable to write the value in
 * @return The pointer to the iterator, or NULL if the pointer is destroyed
 */
linked_list_iterator *linked_list_iteraton_next(linked_list *self, int *out);

/**
 * @brief End the iteration by destroying the iterator. This method should only
 * be called if the iteration is ended early
 */
void linked_list_end_iteration(linked_list *self);

#endif // _LINKED_LIST_H_
