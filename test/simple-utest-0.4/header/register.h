#ifndef __SIMPLE_UTEST_REGISTER_H__
#define __SIMPLE_UTEST_REGISTER_H__

/* this inclusion is mainly to have my LSP not scream at me */
#include <stdint.h>
/*
 * The heart of this utility. Controls everything about a test; from test
 * execution, option handling to log info provision
 * */

/* DO NOT call this function unless you know exactly what you want to do */
extern void reglist_add(void (*testname)(), const char *test_name,
                        const char *filename, uint16_t line);

#define register_test(testname, OPTS)                     \
  void testname();                                        \
  __attribute__((constructor)) void reg_##testname() {    \
    reglist_add(testname, #testname, __FILE__, __LINE__); \
    reglist_config_newest(OPTS);                          \
  }                                                       \
  /* define your test */                                  \
  void testname()

/* options to be passed into register_test() */

/* configure the newly registered test with option */
extern void reglist_config_newest(const uint16_t);

enum reg_opts {
  /* run test with no success or fail log */
  DEFAULT = 0b0,
  /* does not run this test */
  EXCLUDE = 0b1,
  /* prints out success and fail log */
  VERBOSE = 0b110,
  /* prints out success log */
  VERBOSE_FAIL_LOG = 0b010,
  /* prints out fail log */
  VERBOSE_SUCCESS_LOG = 0b100,
};

/* Dealing with parameterized tests */

/* argument list and parameterized list must be wrapped inside these functions
 */
#define ARGS_LIST(...) __VA_ARGS__

#define PARAM_LIST(...) (__VA_ARGS__)

#define register_param_test(testname, arglist, OPTS, paramlist...) \
  void simple_wrapper_for_##testname();                            \
  void testname(arglist);                                          \
  __attribute__((constructor)) void reg_simple_wrapper_for_##testname(){\
    reglist_add(simple_wrapper_for_##testname, #testname, __FILE__, __LINE__);\
    reglist_config_newest(OPTS);\
  }\
  void simple_wrapper_for_##testname (){\
    _PASS_PARAM_LIST(testname, paramlist);\
  }\
  void testname(arglist)

/* All of the below can be called by the user, but I heavily recommend
 * against doing so. All of the below are utilized inside register_param_test
 * already
 * */

#define _PASS_PARAM_LIST(testname, ...) \
  __VA_OPT__(EXPAND(_PASS_HELPER(testname, __VA_ARGS__)))

#define _PAREN ()

#define _PASS_HELPER(testname, paramlist, ...) \
  testname paramlist;                          \
  __VA_OPT__(_PASS_HELPER_ALIAS _PAREN(testname, __VA_ARGS__))

#define _PASS_HELPER_ALIAS() _PASS_HELPER

/* Parameter list expansion, maximum 64 (4^3) list for each parameterized test
 */
/* DO NOT CALL. */
#define EXPAND(arg) EXPAND1(EXPAND1(EXPAND1(EXPAND1(arg))))
#define EXPAND1(arg) EXPAND2(EXPAND2(EXPAND2(EXPAND2(arg))))
#define EXPAND2(arg) EXPAND3(EXPAND3(EXPAND3(EXPAND3(arg))))
#define EXPAND3(arg) arg

#endif  // !__SIMPLE_UTEST_REGISTER_H__
