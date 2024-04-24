#include "../src/header/linked-list.h"
#include "./simple-utest/simple-utest.h"

register_test(test_append_insert, VERBOSE) {
  linked_list *test_list = linked_list_new();

  int inline_data[] = {4, 8, 16};

  linked_list_append(test_list, 4);
  linked_list_append(test_list, 16);
  linked_list_insert(test_list, 1, 8);

  for (int i = 0; i < sizeof(inline_data) / sizeof(inline_data[0]); i++) {
    simple_assert_int(inline_data[i], linked_list_get_value(test_list, i));
  }

  linked_list_free(test_list);
}

register_test(test_remove, VERBOSE) {
  linked_list *test_list = linked_list_new();

  int inline_data[] = {8, 16};

  linked_list_append(test_list, 4);
  linked_list_append(test_list, 16);
  linked_list_insert(test_list, 1, 8);
  linked_list_remove(test_list, 0);

  for (int i = 0; i < sizeof(inline_data) / sizeof(inline_data[0]); i++) {
    simple_assert_int(inline_data[i], linked_list_get_value(test_list, i));
  }
}
