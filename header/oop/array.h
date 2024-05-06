#ifndef __DS_IN_C_ARRAY_H__
#define __DS_IN_C_ARRAY_H__

#include "../iface/i-list.h"
#include "object.h"

typedef struct Array Array;

typedef struct TArray TArray;

struct TArray {
  const IList i_list;
};

Array *array_ctor(const Class *type, size_t size);

void array_dtor(void *self);

const Class *array_get_datatype(void *self);

size_t array_get_count(void *self);

void array_append(void *self, Object *data);

void array_prepend(void *self, Object *data);

void array_insert(void *self, size_t index, Object *data);

Object *array_get(void *self, size_t index);

Array *is_Array(Object *self);

const Class *get_class_Array();

#endif // !__DS_IN_C_ARRAY_H__
