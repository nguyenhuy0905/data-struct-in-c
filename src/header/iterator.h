#ifndef _ITERATOR_H_
#define _ITERATOR_H_
typedef struct _iterator iterator;

iterator *iterator_new();
void iterator_set_list(void *list_type);
void iterator_set_next_function(iterator *self, void *(*next)(void));
void *iterator_next(iterator *self);
#endif // !_ITERATOR_H_
