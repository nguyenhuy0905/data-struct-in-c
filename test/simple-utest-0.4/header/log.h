#ifndef __SIMPLE_UTEST_LOG_H__
#define __SIMPLE_UTEST_LOG_H__

#include <stdint.h>
/*
 * Console output for the utility.
 * Any non-test-specific output is defined in log.c,
 * otherwise it's in, again, register.c
 * */

#define RESET_ALL "\033[0m"

/* List of colors */

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGNETA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT_COLOR "\033[39m"

/* List of formats */

#define BOLD "\033[1m"
#define DIM "\033[2m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define STRIKETHROUGH "\033[9m"

/* general logs */

extern void log_final();

/* Test-specific logs */

/* Interface with test register */

extern void get_summary_info(uint16_t *n_test, uint16_t *n_run,
                             uint16_t *n_success);

extern void get_current_test_info(const char **test_name, uint16_t *line,
                                  const char **file);

extern uint16_t get_verbosity();

/* Interface with assertions */

extern void log_fail_general();

#define log_fail_result(format)                                                \
  printf(RED DIM "\t"                                                          \
                 "%s, line %d: "                                               \
                 "Expected " format ", got " format "\n" RESET_ALL,            \
         __func__, line, expected, actual);

#define log_fail(format)                                                       \
  log_fail_general();                                                          \
  log_fail_result(format);

extern void log_success_general();

#define log_success(format)                                                    \
  log_success_general();\
  printf(GREEN DIM "\t" "%s(" format ", " format "), line %d\n" RESET_ALL, __func__, expected, actual, __LINE__);\

#endif
