#include <stdio.h>
#include "bst.h"

int main() {
    BSTNode* tree = NULL;

    tree = bst_insert(tree, 17);
    bst_insert(tree, 13);
    bst_insert(tree, 22);
    bst_insert(tree, 3);
    bst_insert(tree, 15);
    bst_insert(tree, 19);
    bst_insert(tree, 31);
    bst_insert(tree, 30);
    bst_insert(tree, 2);
    bst_insert(tree, 8);
    bst_insert(tree, 4);
    bst_insert(tree, 12);

    bst_level_order_traversal(tree);
}