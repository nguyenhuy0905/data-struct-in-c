#include "../src/header/linked-list.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  linked_list *ll = linked_list_new();
  linked_list_append(ll, 8);
  linked_list_append(ll, 16);
  linked_list_append(ll, 32);
  linked_list_insert(ll, 2, 24);
  linked_list_print(ll);

  linked_list_free(ll);

  return EXIT_SUCCESS;
}
