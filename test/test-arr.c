#include "simple-utest-0.4/simple-utest.h"
#include "header/oop/array.h"
#include "header/oop/string.h"

register_test(test_array_class, VERBOSE){
  Array *test = array_ctor(CLASS(String), 16);
  array_append(test, (Object*)string_ctor_and_set("AHA"));
  array_append(test, (Object*)string_ctor_and_set("Never gonna give you up"));
  simple_assert_int(1, (test != NULL));
  simple_assert_string("AHA", string_get_text((String*)array_get(test, 0)));
  simple_assert_string("Never gonna give you up", string_get_text((String*)array_get(test, 1)));
  array_dtor(test);
}

register_test(test_nested_array_class, VERBOSE){
  Array *test = array_ctor(CLASS(Array), 16);
}
