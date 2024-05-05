#ifndef __DS_IN_C_OBJECT_H__
#define __DS_IN_C_OBJECT_H__

#include "class.h"

typedef struct Object Object;

/**
 * @class Object
 * @brief A wrapper around a class. That's it.
 * Can be used to traverse up the class hierachy
 *
 */
struct Object {
  const Class *const klass;
};

#endif // !__DS_IN_C_OBJECT_H__
