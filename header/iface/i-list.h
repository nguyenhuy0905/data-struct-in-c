#ifndef __DS_IN_C_ILIST_H__
#define __DS_IN_C_ILIST_H__

#include "../oop/object.h"
#include "i-collection.h"
#include <assert.h>
#include <stdio.h>

typedef struct IList IList;

struct IList {
  ICollection i_collection;
  void (*const append)(void *self, Object *val);
  void (*const prepend)(void *self, Object *val);
  void (*const insert)(void *self, size_t index, Object *val);
  Object *(*const get_value)(void *self, size_t index);
  const Class *(*const get_data_type)(void *self);
};

#define ILIST(ptr) ptr->i_list

#endif // !__DS_IN_C_ILIST_H__
