#include "../src/header/linked-list.h"
#include <stdio.h>
#include <stdlib.h>

void test_append_insert(linked_list *ll);

void test_remove(linked_list *ll);

int main(int argc, char *argv[]) {
  linked_list *ll = linked_list_new();

  test_append_insert(ll);
  ll = linked_list_new();
  test_remove(ll);

  return EXIT_SUCCESS;
}

void test_append_insert(linked_list *ll) {
  printf("=====TEST APPEND AND INSERT=====\n\n");
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
  linked_list_append(ll, 8);
  linked_list_append(ll, 16);
  linked_list_append(ll, 32);
  linked_list_insert(ll, 2, 24);
  // remove
  linked_list_remove(ll, 0);
  linked_list_remove(ll, 1);
  linked_list_print(ll);
  printf("Expected:\n16->32->NULL\n");
  printf("\n=====TEST REMOVE=====\n\n");

  linked_list_free(ll);
}
