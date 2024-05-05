#include "header/oop/string.h"
#include "simple-utest-0.4/simple-utest.h"

register_test(test_string_class, VERBOSE) {
  String *test = string_ctor();
  simple_assert_int((test != NULL), 1); // pass if test isnt null
  string_dtor(test);
}
