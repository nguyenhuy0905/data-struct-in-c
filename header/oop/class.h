#ifndef __DS_IN_C_CLASS_H__
#define __DS_IN_C_CLASS_H__

#include <stdio.h>
typedef struct Class Class;

/**
 * @class class
 * @brief: Literally contains nothing. However, it can STILL be used
 * to check type of objects
 *
 */
struct Class {};

#define IS_CLASS(Class, ptr) is_##Class(ptr)

#endif // !__DS_IN_C_CLASS_H__
