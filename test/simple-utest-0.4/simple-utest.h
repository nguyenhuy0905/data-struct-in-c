#ifndef __SIMPLE_UTEST_H__
#define __SIMPLE_UTEST_H__

/* all the macros that shall be used by the end user */

/* maybe this is specific to me. I need to #define and #undef like this
 * for the LSP to not scream at me for the wrong thing */

#define simple_assert_int(expected, actual) \
  _simple_assert_int(expected, actual, __LINE__)

#define simple_assert_double(expected, actual) \
  _simple_assert_double(expected, actual, __LINE__)

#define simple_assert_float(expected, actual) \
  _simple_assert_float(expected, actual, __LINE__)

#define simple_assert_long(expected, actual) \
  _simple_assert_long(expected, actual, __LINE__)

#define simple_assert_long_long(expected, actual) \
  _simple_assert_long_long(expected, actual, __LINE__)

#define simple_assert_string(expected, actual) \
  _simple_assert_string(expected, actual, __LINE__)

#define simple_assert_char(expected, actual) \
  _simple_assert_char(expected, actual, __LINE__)

#define simple_assert(type, expected, actual) \
  _simple_assert_##type(expected, actual, __LINE__)

/* declares all the functions that (mostly) can be included by the end user */
#include "header/.deps.h"
#include "header/assert.h"
#include "header/register.h"

#endif
