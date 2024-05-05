#include "header/oop/string.h"
#include "simple-utest-0.4/simple-utest.h"

register_test(test_string_class, VERBOSE) {
  // test initialization
  String *test = string_ctor();
  simple_assert_int((test != NULL), 1); // pass if test isnt null
  // test setting string
  string_set_text(test, "AHA");
  simple_assert_string("AHA", string_get_text(test));

  string_dtor(test);
}
