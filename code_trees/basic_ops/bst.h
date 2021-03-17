#ifndef ALGORITHMS_TUTORIAL_BST_H
#define ALGORITHMS_TUTORIAL_BST_H

typedef int ElementType;

typedef struct BinarySearchTreeNode {
    ElementType value;
    struct BinarySearchTreeNode* left_child;
    struct BinarySearchTreeNode* right_child;
} BSTNode;

BSTNode* bst_insert(BSTNode* root, ElementType data);
void bst_level_order_traversal(BSTNode* root);
void bst_in_order_traversal(BSTNode* root);
void bst_pre_order_traversal(BSTNode* root);
void bst_post_order_traversal(BSTNode* root);
void bst_delete(BSTNode* root, ElementType el);

#endif //ALGORITHMS_TUTORIAL_BST_H
