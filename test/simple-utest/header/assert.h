#ifndef __SIMPLE_UTEST_ASSERT_H__
#define __SIMPLE_UTEST_ASSERT_H__

/*
 * A list of assertion methods available with simple_assert_[datatype], and
 * one user-defined assert (complex_assert_pointer)
 * */

/* these includes don't do anything but suppress some wrong and annoying
 * warnings*/
#include <stdbool.h>

extern void _simple_assert_int(int expected, int actual, int line);

extern void _simple_assert_double(double expected, double actual, int line);

extern void _simple_assert_string(const char *expected, const char *actual, int line);

extern void _complex_assert_pointer(const void *expected, const void *actual,
                                   bool (*comparer)(const void *expected,
                                                    const void *actual), int line);

/* Interface with register */
extern void notify_fail();

#endif // !__SIMPLE_UTEST_ASSERT_H__
