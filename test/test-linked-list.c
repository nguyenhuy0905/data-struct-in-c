#include "../src/header/linked-list.h"
#include <stdio.h>
#include <stdlib.h>

void test_append_insert(linked_list *ll);

void test_remove(linked_list *ll);

void test_length(linked_list *ll);

void test_iterator(linked_list *ll);

int main(int argc, char *argv[]) {
  linked_list *ll = linked_list_new();

  test_append_insert(ll);
  ll = linked_list_new();

  test_remove(ll);
  ll = linked_list_new();

  test_length(ll);
  ll = linked_list_new();

  test_iterator(ll);

  return EXIT_SUCCESS;
}

void test_append_insert(linked_list *ll) {
  printf("=====TEST APPEND AND INSERT=====\n\n");
  printf("Appending 8, 16, 32, then insert 24 at position 2, then 4 at "
         "position 0\n");
  linked_list_append(ll, 8);
  linked_list_append(ll, 16);
  linked_list_append(ll, 32);
  linked_list_insert(ll, 2, 24);
  linked_list_insert(ll, 0, 4);
  linked_list_print(ll);
  printf("Expected:\n4->8->16->24->32->NULL\n");
  printf("\n=====TEST APPEND AND INSERT=====\n\n");

  linked_list_free(ll);
}

void test_remove(linked_list *ll) {
  printf("=====TEST REMOVE=====\n\n");
  printf("Appending 8, 16, 32, then insert 24 at position 2, then 4 at "
         "position 0\n");
  linked_list_append(ll, 8);
  linked_list_append(ll, 16);
  linked_list_append(ll, 32);
  linked_list_insert(ll, 2, 24);
  linked_list_insert(ll, 0, 4);
  printf("Current linked list:\n");
  linked_list_print(ll);
  // start remove
  printf("Removing element 0, then element 1\n");
  linked_list_remove(ll, 0);
  linked_list_remove(ll, 1);
  linked_list_print(ll);
  printf("Expected:\n4->24->32->NULL\n");
  printf("\n=====TEST REMOVE=====\n\n");

  linked_list_free(ll);
}

void test_length(linked_list *ll) {
  printf("=====TEST LENGTH=====\n\n");
  printf("Appending 8, 16, 32, then insert 24 at position 2, then 4 at "
         "position 0\n");
  linked_list_append(ll, 8);
  linked_list_append(ll, 16);
  linked_list_append(ll, 32);
  linked_list_insert(ll, 2, 24);
  linked_list_insert(ll, 0, 4);
  printf("Expected length: 5\n");
  printf("Actual length: %d\n", linked_list_get_length(ll));
  // remove some elements
  printf("Removing element 0, then element 1\n");
  linked_list_remove(ll, 0);
  linked_list_remove(ll, 1);
  printf("Expected length: 3\n");
  printf("Actual length: %d\n", linked_list_get_length(ll));

  printf("\n=====TEST LENGTH=====\n\n");

  linked_list_free(ll);
}

void test_iterator(linked_list *ll) {
  printf("=====TEST ITERATOR=====\n\n");
  printf("Appending 8, 16, 32, then insert 24 at position 2, then 4 at "
         "position 0\n");
  linked_list_append(ll, 8);
  linked_list_append(ll, 16);
  linked_list_append(ll, 32);
  linked_list_insert(ll, 2, 24);
  linked_list_insert(ll, 0, 4);
  int expected[] = {4, 8, 16, 24, 32};
  printf("\n=====TEST ITERATOR=====\n\n");
  int out;
  int i = 0;
  linked_list_start_iteration(ll);
  while (linked_list_iteraton_next(ll, &out) != NULL) {
    printf("Expected: %d\nActual: %d\n", expected[i], out);
    i++;
  }
  printf("\n=====TEST ITERATOR=====\n\n");

  linked_list_free(ll);
}
