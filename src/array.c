#include "oop/array.h"
#include "oop/class.h"
#include "oop/object.h"
#include <stdlib.h>

struct Array {
  const Class *klass;          // the Array class
  const Class *template_klass; // the class of the underlying data type
  const TArray *table;
  Object **arr; // the values contained inside
  size_t length;
  size_t count;
};

static const Class array_class = {
  .free_obj = array_dtor,
};

static const TArray array_table = {
    .i_list = {.get_data_type = array_get_datatype,
               .append = array_append,
               .prepend = array_prepend,
               .insert = array_insert,
               .i_collection = {
                   .get_count = array_get_count,
                   .iterate_next = NULL,
               }}};

Array *array_ctor(const Class *type, size_t size) {
  Array *ret = (Array *)malloc(sizeof(Array));
  ret->klass = &array_class;
  ret->template_klass = type;
  ret->arr = (Object **)malloc(sizeof(Object *) * size);
  ret->length = size;
  ret->count = 0;
  return ret;
}

void array_dtor(void *self){
  if(self == NULL)
    return;
  if(((Object*)self)->klass != &array_class){
    printf("Not an array\n");
    free(self);
    return;
  }
  for(int i = 0; i < ((Array*)self)->count; i++){
    // free(((Array*)self)->arr[i]);
    ((Array*)self)->template_klass->free_obj(((Array*)self)->arr[i]);
  }
  free(((Array*)self)->arr);
  free(self);
  return;
}

const Class *array_get_datatype(void *self) {
  return ((Array *)self)->template_klass;
}

size_t array_get_count(void *self) { return ((Array *)self)->count; }

void array_append(void *self, Object *data) {
  if (((Object *)self)->klass != &array_class)
    return;
  if (data->klass != ((Array *)self)->template_klass)
    return;
  if (((Array *)self)->count == ((Array *)self)->length)
    return;
  ((Array *)self)->arr[((Array *)self)->count] = data;
  ((Array*)self)->count++;
}

void array_prepend(void *self, Object *data) {
  if (((Object *)self)->klass != &array_class)
    return;
  if (data->klass != ((Array *)self)->template_klass)
    return;
  if (((Array *)self)->count == ((Array *)self)->length)
    return;
}

void array_insert(void *self, size_t index, Object *data) {}

Object *array_get(void *self, size_t index){
  if(((Array*)self)->count <= index)
    return NULL;
  return ((Array*)self)->arr[index];
}

Array *is_Array(Object *self) {
  if (self == NULL)
    return NULL;
  if (self->klass != &array_class)
    return NULL;
  return (Array *)self;
}

const Class *get_class_Array(){
  return &array_class;
}
