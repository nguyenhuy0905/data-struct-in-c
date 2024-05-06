#ifndef __DS_IN_C_CLASS_H__
#define __DS_IN_C_CLASS_H__

typedef struct Class Class;

/**
 * @class class
 * @brief: mainly used to check the type of an object
 *
 */
struct Class {
  void (*free_obj)(void *self); // useful for collection types
};

#define IS_CLASS(Class, ptr) is_##Class(ptr)

#define CLASS(Class) get_class_##Class()

#endif // !__DS_IN_C_CLASS_H__
