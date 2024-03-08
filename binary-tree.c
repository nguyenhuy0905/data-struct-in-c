#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
  // i got so much hassle trying to trace back the parent
  // without this pointer that I decided to just add it in.
  TreeNode *parent;
  TreeNode *left;
  TreeNode *right;
  char *data;
};

TreeNode *root = NULL;

int length = 0;

TreeNode *search_subtree_for(char data[], TreeNode *subtree_node) {
  if (subtree_node == NULL){
    printf("Node \"%s\" not found!\n", data);
    return NULL;
  }
  int cmp_result = strcmp(data, subtree_node->data);
  if (cmp_result == 0){
    printf("Node \"%s\" found!\n", data);
    return subtree_node;
  }
  if (cmp_result < 0) {
    if (subtree_node->left == NULL)
      return NULL;
    return search_subtree_for(data, subtree_node->left);
  }
  if (subtree_node->right == NULL)
    return NULL;
  return search_subtree_for(data, subtree_node->right);
}

TreeNode *search_for(char data[]){
  return search_subtree_for(data, root);
}

void insert(TreeNode *node, TreeNode *curr) {
  // at the point when this func is called, both the pointers passed in aren't
  // null (if only the client would always be obedient)
  if (strcmp(node->data, curr->data) == 0) {
    printf("Error, this entry already exists inside the tree\n");
    return;
  }
  if (strcmp(node->data, curr->data) <= 0) {
    if (curr->left == NULL) {
      curr->left = node;
      node->parent = curr;
      printf("Node inserted to left\n");
      return;
    }
    insert(node, curr->left);
    return;
  }
  if (curr->right == NULL) {
    curr->right = node;
    node->parent = curr;
    printf("Node inserted to right\n");
    return;
  }
  insert(node, curr->right);
  return;
}

TreeNode *add_node(char data[]) {
  TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
  if (new == NULL) {
    printf("Memo allocation error\n");
    return NULL;
  }
  new->data = data;
  new->parent = NULL;
  new->left = NULL;
  new->right = NULL;

  if (root == NULL) {
    root = new;
  } else
    insert(new, root);

  length++;
  return new;
}

/*
 * Remove a node with specified data, if such a node exists
 * */
void remove_node(char data[]) {
  // tree has yet to exist
  if (root == NULL)
    return;
  // wtf are u asking for
  if (data == NULL)
    return;
  TreeNode *remove = search_subtree_for(data, root);
  // the node with specified data doesn't exist
  if (remove == NULL) {
    printf("No such node to remove!\n");
    return;
  }
  /*
   * 'l' means the node to be removed is the left child of its parent
   * 'r' means it's right
   */
  char parent_side =
      (strcmp(remove->data, remove->parent->data) < 0) ? 'l' : 'r';
  bool left_exist = (remove->left != NULL);
  bool right_exist = (remove->right != NULL);

  // node to remove is a leaf
  if (!(left_exist || right_exist)) {
    if (parent_side == 'l')
      remove->parent->left = NULL;
    else
      remove->parent->right = NULL;
    free(remove);
  }
  // has a left child but no right child
  else if (left_exist && !right_exist) {
    if (parent_side == 'l') {
      remove->parent->left = remove->left;
      remove->left->parent = remove->parent;
    } else {
      remove->parent->right = remove->left;
      remove->left->parent = remove->parent;
    }
    free(remove);
  }
  // has a right child but no left child
  else if (!left_exist && right_exist) {
    if (parent_side == 'l') {
      remove->parent->left = remove->right;
      remove->left->parent = remove->parent;
    } else {
      remove->parent->right = remove->right;
      remove->right->parent = remove->parent;
    }
    free(remove);
  }
  // has 2 children
  else {
    // find the next bigger-valued node
    TreeNode *next = remove->right;
    while (next->left != NULL) {
      next = next->left;
    }
    char next_data[strlen(next->data)];
    strcpy(next_data, next->data);
    // do a left-removal of the next node
    next->parent->left = NULL;
    free(next);
    // overwrite the data of the should-be removed node
    remove->data = next_data;
  }
  printf("Removed node %s\n", data);
  length--;
}

void preorder(TreeNode *current, int tabs) {
  char tab[tabs + 1];
  for(int i = 0; i < tabs; i++){
    tab[i] = '\t';
  }
  tab[tabs] = '\0';
  if (current == NULL) {
    printf("%sNULL\n", tab);
    return;
  }
  printf("%s%s\n", tab, current->data);
  printf("%sLeft:\n", tab);
  preorder(current->left,tabs + 1);
  printf("%sRight:\n", tab);
  preorder(current->right,tabs + 1);
}

void preorder_print() {
  if (root == NULL) {
    printf("Tree is empty!\n");
    return;
  }
  printf("Pre-order tree:\n");
  preorder(root,0);
}

int main(int argc, char *argv[]) {
  add_node("I just wanna tell you how I\'m feeling");
  add_node("Don\'t tell me you\'re too blind to see");
  add_node("Never gonna give you up");
  add_node("Never gonna let you down");
  add_node("Never gonna run around and desert you");
  add_node("Never gonna make you cry");
  add_node("Never gonna say goodbye");
  add_node("Never gonna tell a lie and desert you");
  printf("\n");
  
  remove_node("Rick Astley");
  printf("\n");
  
  preorder_print();
  remove_node("Never gonna let you down");
  printf("\n");

  preorder_print();
  printf("\n");

  search_for("Never gonna give you up");
  search_for("Rick Astley");
  return EXIT_SUCCESS;
}
