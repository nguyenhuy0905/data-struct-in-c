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

/*
 * THIS METHOD SHOULD NOT BE CALLED BY THE CLIENT
 *
 * (Recursively) searches for a node with specified data in the tree
 *
 * Parameters:
 * - data: the string to look for
 * - subtree_node: for recursive search calls
 *
 * Return:
 * - The node with specified data if such node exists
 * - NULL otherwise
 * */
TreeNode *search_subtree_for(char data[], TreeNode *subtree_node) {
  if (subtree_node == NULL) {
    printf("Node \"%s\" not found!\n", data);
    return NULL;
  }
  int cmp_result = strcmp(data, subtree_node->data);
  if (cmp_result == 0) {
    printf("Node \"%s\" found!\n", data);
    return subtree_node;
  }
  if (cmp_result < 0) {
    return search_subtree_for(data, subtree_node->left);
  }
  return search_subtree_for(data, subtree_node->right);
}

/*
 * Search for a tree node which contains the specified string
 *
 * Parameters:
 * - char data[]: the string to look for
 *
 * Returns:
 * - the tree node with the data specified if such a node exists
 * - NULL otherwise
 * */
TreeNode *search_for(char data[]) { return search_subtree_for(data, root); }

/*
 * Get the depth of the tree node
 *
 * Parameters:
 * - node: the node to calculate depth
 *
 * Return:
 * - The depth of that node
 * */
int depth(TreeNode *node){
  if(node->left == NULL && node->right == NULL)
    return 0;
  if(node->left == NULL) return 1 + depth(node->right);
  if(node->right == NULL) return 1 + depth(node->left);
  int left_depth = 1 + depth(node->left);
  int right_depth = 1 + depth(node->right);
  return (left_depth >= right_depth) ? left_depth : right_depth;
}  

void balance_left(TreeNode *node){
  if(node->left->left != NULL){
    // left-left imbalance with extra steps
    if(node->left->right != NULL){
      
      return;
    }
    // left-left imbalance
    return;
  } 
}

void balance_right(TreeNode *node){
  if(node->right->right != NULL){
    // right-right imbalance with extra steps
    if(node->right->right != NULL){
      return;
    }
    // right-right imbalance
    return;
  }
}

/*
 * THIS METHOD SHOULD NOT BE CALLED BY THE CLIENT
 *
 * Balances the tree if needed
 * */
void balance_tree(TreeNode *node){
  int diff = depth(node->left) - depth(node->right); 
  // nothing cool here
  if(-1 <= diff && diff <= 1) return;
  // too many right nodes
  if(diff < -1){
    balance_right(node);
  }
  // too many left nodes
  else{
    balance_left(node);
  }
}

/*
 * THIS METHOD SHOULD NOT BE CALLED BY THE CLIENT
 *
 * Inserts the specified node into the tree
 *
 * Parameters:
 * - node: The node to be inserted
 * - curr: For recursive calls
 * */
TreeNode *insert(TreeNode *node, TreeNode *curr) {
  // at the point when this func is called, both the pointers passed in aren't
  // null (if only the client would always be obedient)
  if (strcmp(node->data, curr->data) == 0) {
    printf("Error, this entry already exists inside the tree\n");
    return NULL;
  }
  if (strcmp(node->data, curr->data) < 0) {
    if (curr->left == NULL) {
      curr->left = node;
      node->parent = curr;
      printf("Node inserted to left\n");
      return node;
    }
    return insert(node, curr->left);
  }
  if (curr->right == NULL) {
    curr->right = node;
    node->parent = curr;
    printf("Node inserted to right\n");
    return node;
  }
  return insert(node, curr->right);
}

/*
 * Adds a node with the specified data into the tree
 *
 * Parameters:
 * - data: the data to be added into the tree
 *
 * Return:
 * - The tree node just created
 * */
TreeNode *add_node(char data[]) {
  TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
  if (new == NULL) {
    printf("Memo allocation error\n");
    return NULL;
  }
  
  new->data = (char*)malloc(strlen(data)+1);
  strcpy(new->data, data);
  // new->data = data;
  new->parent = NULL;
  new->left = NULL;
  new->right = NULL;

  if (root == NULL) {
    root = new;
    length++;
    return new;
  }
  length++;
  return insert(new, root);
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
   * 'n' (none) means the node is root (so it has no parent)
   */
  char parent_side;
  if(remove != root) parent_side = (strcmp(remove->data, remove->parent->data) < 0) ? 'l' : 'r';
  else parent_side = 'n';
  bool left_exist = (remove->left != NULL);
  bool right_exist = (remove->right != NULL);

  // node to remove is a leaf
  if (!left_exist && !right_exist) {
    if (parent_side == 'l')
      remove->parent->left = NULL;
    else if(parent_side == 'r')
      remove->parent->right = NULL;
    else{
      root = NULL;
    }
    free(remove);
  }
  // has a left child but no right child
  else if (left_exist && !right_exist) {
    if (parent_side == 'l') {
      remove->parent->left = remove->left;
      remove->left->parent = remove->parent;
    } else if(parent_side == 'r'){
      remove->parent->right = remove->left;
      remove->left->parent = remove->parent;
    }
    else{
      root->left->parent = NULL;
      root = root->left;
    }
    free(remove);
  }
  // has a right child but no left child
  else if (!left_exist && right_exist) {
    if (parent_side == 'l') {
      remove->parent->left = remove->right;
      remove->left->parent = remove->parent;
    } else if(parent_side == 'r'){
      remove->parent->right = remove->right;
      remove->right->parent = remove->parent;
    }
    else{
      root->right->parent = NULL;
      root = root->right;
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
    char next_data[strlen(data)];
    strcpy(next_data, next->data);
    remove_node(next_data);
    // overwrite the data of the should-be removed node
    remove->data = realloc(remove->data, strlen(next_data)+1);
    strcpy(remove->data, next_data);
  }
  printf("Removed node \"%s\"\n", data);
  length--;
}

/*
 * THIS METHOD SHOULD NOT BE CALLED BY THE CLIENT
 *
 * Print the tree pre-ordered.
 *
 * Parameters:
 * - current: For recursive calls
 * - tabs: the number of indents to add before each print content
 * */
void preorder(TreeNode *current, int tabs) {
  char tab[tabs + 1];
  for (int i = 0; i < tabs; i++) {
    tab[i] = '\t';
  }
  tab[tabs] = '\0';
  if (current == NULL) {
    printf("%sNULL\n", tab);
    return;
  }
  printf("%s%s\n", tab, current->data);
  printf("%sLeft:\n", tab);
  preorder(current->left, tabs + 1);
  printf("%sRight:\n", tab);
  preorder(current->right, tabs + 1);
}

/*
 * Print the tree pre-ordered
 * */
void preorder_print() {
  if (root == NULL) {
    printf("Tree is empty!\n");
    return;
  }
  printf("Pre-order tree:\n");
  preorder(root, 0);
}

int main(int argc, char *argv[]) {
  // let's make a sample
  char *str = "I just wanna tell you how I\'m feeling";
  add_node(str);
  str = "Don\'t tell me you\'re too blind to see";
  add_node(str);
  add_node("Never gonna give you up");
  add_node("Never gonna let you down");
  add_node("Never gonna run around and desert you");
  add_node("Never gonna make you cry");
  add_node("Never gonna say goodbye");
  add_node("Never gonna tell a lie and desert you");
  printf("\n");

  remove_node("Rick Astley");
  printf("\n");

  remove_node("Never gonna let you down");
  preorder_print();
  printf("\n");

  // rm -rf
  remove_node("I just wanna tell you how I\'m feeling");
  printf("\n");

  preorder_print();
  printf("\n");

  // search_for("Never gonna give you up");
  // search_for("Rick Astley");
  // printf("\n");

  // rm -rf again
  remove_node("Never gonna give you up");
  // remove_node("Never gonna make you cry");
  preorder_print();

  remove_node("Never gonna make you cry");
  preorder_print();

  return EXIT_SUCCESS;
}
