#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int val;
  struct Node *left;
  struct Node *right;
};
typedef struct Node Node;
typedef Node *tree;

tree New_Node(int val) {
  tree node = (Node *)(malloc(sizeof(Node)));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

tree insert(tree R, int val) {
  if (R == NULL) {
    return New_Node(val);
  }

  if (val < R->val) {
    R->left = insert(R->left, val);
  } else if (val > R->val) {
    R->right = insert(R->right, val);
  }
  return R;
}

void In_order(tree R) {
  if (R == NULL) {
    return;
  }
  In_order(R->left);
  printf("%d ", R->val);
  In_order(R->right);
}
//   The idea is to use a recursive helper function, isBSTUtil(node, min, max)
//   to check whether a subtree (rooted at a given node) is a binary search tree
//   (BST) within a specified range of minimum (min) and maximum (max) values.
//   If it falls outside this range, it violates BST properties, so we return
//   false.

//      For the left subtree, we call isBSTUtil() with the updated range as the
//      max is set to (node->data – 1 ) because all values in the left subtree
//      must be smaller than the current node’s value.
//    For the right subtree, we call isBSTUtil() with the updated range as the
//    min is set to (node->data + 1) because all values in the right subtree
//    must be greater than the current node’s value.

// Both recursive calls must return true for the entire subtree to be a valid
// BST.
//
//
//
// Helper function to check if a tree is BST within a given range

//              __
//             / _)
//     _.----._/ /
//    /         /
// __ / (  | (  |
///__.-'|_|--|_|

bool isBSTUtil(tree R, int min, int max) {
  if (R == NULL)
    return true;

  if (R->val < min || R->val > max) {
    return false;
  }
  return isBSTUtil(R->left, min, R->val - 1) &&
         isBSTUtil(R->right, R->val + 1, max);
}
//
//  _______
// .-'       '-.
//  /             \
// |               |
// |,  .-. .-.  ,  |
// | )(__/ \__)(   |
// |/     /\     \ |
// (_     ^^     _)
// \__|IIIIII|__/
//  | \IIIIII/ |
//   \          /
//    `--------`

bool isBst(tree root) {
  //
  //
  // the INT_MIN INT_MAX are pre defined in the limits .h
  return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main(int argc, char *argv[]) {
  tree root = New_Node(4);
  tree Left = New_Node(2);
  tree Right = New_Node(5);
  root->left = Left;
  root->right = Right;
  root = insert(root, 1);
  root = insert(root, 3);
  if (isBst(root)) {
    printf("the tree is a Binary Search tree \n");
  } else {
    printf("the tree is not a Binary search tree \n");
  }
  In_order(root);
  return EXIT_SUCCESS;
}
