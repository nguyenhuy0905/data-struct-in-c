#include "header/iterator.h"
#include <stdlib.h>

struct _iterator {
  void *list;
  void *current;
  void *(*next)(void);
};

iterator *iterator_new() { return (iterator *)malloc(sizeof(iterator)); }

void *iterator_next(iterator *self) { return self->next; }

void iterator_set_next_function(iterator *self, void *(*next)(void)) {
  self->next = next;
}
