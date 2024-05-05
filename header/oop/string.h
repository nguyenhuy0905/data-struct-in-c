#ifndef __DS_IN_C_STRING_H__
#define __DS_IN_C_STRING_H__

#include "class.h"
#include "object.h"

typedef struct String String;

String *string_ctor();

void string_set_text(String *self, const char *text);

String *string_ctor_and_set(const char *text);

void string_dtor(void *self);

int string_compare(void *self, void *another);

String *is_String(Object *self);

char *string_get_text(String *self);

#endif // !__DS_IN_C_STRING_H__
