#include "oop/string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct String {
  const Class *klass;
  size_t length;
  char *text;
};

static const Class string_class = {};

String *string_ctor() {
  String *ret = (String *)malloc(sizeof(String));
  ret->klass = &string_class;
  ret->text = NULL;
  ret->length = 0;
  return ret;
}

String *string_ctor_and_set(const char *text) {
  String *ret = (String *)malloc(sizeof(String));
  ret->klass = &string_class;
  ret->text = strdup(text);
  ret->length = strlen(text);
  return ret;
}

String *is_String(Object *self) {
  if (self == NULL)
    return NULL;
  while (self->klass != NULL) {
    if (self->klass == &string_class)
      return (String *)self;
  }
  return NULL;
}

char *string_get_text(String *self) { return self->text; }

void string_set_text(String *self, const char *text) {
  self->text = (char *)realloc(self->text, strlen(text) + 1);
  memcpy(self->text, text, strlen(text) + 1);
  self->length = strlen(text);
}

void string_dtor(void *self) {
  // without this check, a segfault will be thrown
  if (self == NULL)
    return;
  // free(NULL) will simply not do anything so this passes
  free(((String *)self)->text);
  free(self);
  self = NULL;
}

int string_compare(void *self, void *another) {
  if (self == NULL || another == NULL)
    return -1;
  if (((String *)self)->text == NULL || ((String *)another)->text == NULL)
    return -1;
  return strcmp(((String *)self)->text, ((String *)another)->text);
}
