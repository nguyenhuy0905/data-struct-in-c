#ifndef __SIMPLE_UTEST_ASSERT_H__
#define __SIMPLE_UTEST_ASSERT_H__

/*
 * A list of assertion methods available with simple_assert_[datatype] that
 * the end-user can use to write test
 * */

/* these includes don't do anything but suppress some wrong and annoying
 * warnings*/
#include <stdbool.h>

extern void _simple_assert_int(int expected, int actual, int line);

extern void _simple_assert_double(double expected, double actual, int line);

extern void _simple_assert_string(const char *expected, const char *actual,
                                  int line);

extern void _simple_assert_float(float expected, float actual, int line);

extern void _simple_assert_long(long expected, long actual, int line);

extern void _simple_assert_long_long(long long expected, long long actual,
                                     int line);

extern void _simple_assert_char(char expected, char actual, int line);

/* Interface with register */

#endif // !__SIMPLE_UTEST_ASSERT_H__
