#include <stdio.h>
#include "bst.h"

int main() {
    BSTNode* tree = NULL;
    tree = bst_insert(tree, 20, 2);
    tree = bst_insert(tree, 30, 3);
    tree = bst_insert(tree, 10, 5);
    tree = bst_insert(tree, 16, 4);
    tree = bst_insert(tree, 5, 1);
    tree = bst_insert(tree, 15, 3);
    bst_print(tree);
    printf("%d\n", bst_get_assets_below_income(tree, 15));
    printf("%d\n", bst_get_assets_below_income(tree, 22));
}