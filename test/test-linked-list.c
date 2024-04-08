#include "../src/header/linked-list.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  linked_list *ll = linked_list_new();
  linked_list_append(ll, 8);

  return EXIT_SUCCESS;
}
