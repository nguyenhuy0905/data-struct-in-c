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

#define register_test(testname, OPTS)                                          \
  void testname();                                                             \
  __attribute__((constructor)) void reg_##testname() {                         \
    reglist_add(testname, #testname, __FILE__, __LINE__);                      \
    reglist_config_newest(OPTS);                                               \
  }                                                                            \
  /* define your test */                                                       \
  void testname()

/* options to be passed into register_test() */

extern void reglist_config_newest(const uint16_t);

#define DEFAULT 0b0

#define EXCLUDE 0b1

#define VERBOSE 0b10

#endif // !__SIMPLE_UTEST_REGISTER_H__
