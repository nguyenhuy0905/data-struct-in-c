#include <stdlib.h>
#include <stdio.h>
typedef struct TreeNode TreeNode;

struct TreeNode{
  TreeNode *parent;
  TreeNode *left;
  TreeNode *right;
  char *data[1];
};

int main(int argc, char *argv[])
{
  TreeNode *test = (TreeNode*)malloc(sizeof(TreeNode));
  test->parent = NULL;
  test->left = NULL;
  test->right = NULL;
  test->data[0] = malloc(24*sizeof(char));
  test->data[0] = "Hello World";

  printf("%s\n", test->data[0]);

  return EXIT_SUCCESS;
}
