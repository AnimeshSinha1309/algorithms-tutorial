#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <queue>

// This is the implementation for a set (unique entries)
BSTNode* bst_insert(BSTNode* root, ElementType data) {
    if (root == NULL) {
        root = (BSTNode*) malloc(sizeof(BSTNode));
        root->value = data;
        root->left_child = NULL;
        root->right_child = NULL;
    } else {
        if (data > root->value) {
            root->right_child = bst_insert(root->right_child, data);
        } else if (data < root->value) {
            root->left_child = bst_insert(root->left_child, data);
        }
    }
    return root;
}

void bst_level_order_traversal(BSTNode* root) {
    std::queue<BSTNode*> q;
    if (root != NULL)
        q.push(root);
    while (!q.empty()) {
        BSTNode* current = q.front();
        if (current != NULL) {
            printf("%d ", current->value);
            if (root->left_child != NULL)
                q.push(current->left_child);
            if (root->right_child != NULL)
                q.push(current->right_child);
        }
        q.pop();
    }
}
