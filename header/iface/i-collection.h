#ifndef __DS_IN_C_ICOLLECTION_H__
#define __DS_IN_C_ICOLLECTION_H__
#include "../oop/class.h"
#include "../oop/object.h"
#include <stdio.h>

typedef struct ICollection ICollection;

struct ICollection {
  size_t (*const get_count)(void *self);
  Object *(*const iterate_next)(void *self);
};

#define ICOLLECTION(ptr) ptr->i_collection

#endif // !__DS_IN_C_ICOLLECTION_H__
