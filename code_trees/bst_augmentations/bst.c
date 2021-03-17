#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

BSTNode* bst_insert(BSTNode* root, IncomeType income, AssetType asset) {
    if (root == NULL) {
        root = (BSTNode*) malloc(sizeof(BSTNode));
        root->income = income;
        root->asset = asset;
        root->subtree_asset = asset;
        root->parent = NULL;
        root->left_child = NULL;
        root->right_child = NULL;
    } else {
        if (income > root->income || (income == root->income && asset > root->asset)) {
            root->right_child = bst_insert(root->right_child, income, asset);
            root->right_child->parent = root;
        } else {
            root->left_child = bst_insert(root->left_child, income, asset);
            root->left_child->parent = root;
        }
        root->subtree_asset = root->asset + (root->left_child == NULL ? 0 : root->left_child->subtree_asset) +
                (root->right_child == NULL ? 0 : root->right_child->subtree_asset);
    }
    return root;
}

BSTNode* bst_find(BSTNode* root, IncomeType income, AssetType asset) {
    if (root == NULL) {
        return NULL;
    } else if (root->income == income && root->asset == asset) {
        return root;
    } else if (income > root->income || (income == root->income && asset > root->asset)) {
        bst_find(root->right_child, income, asset);
    } else {
        bst_find(root->left_child, income, asset);
    }
    return root;
}

void bst_print(BSTNode* root) {
    if (root == NULL) return;
    printf("Node: %d, %d; sum = %d\n", root->income, root->asset, root->subtree_asset);
    bst_print(root->left_child);
    bst_print(root->right_child);
}

BSTNode* bst_minimum(BSTNode* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left_child == NULL && root->right_child == NULL) {
        return root;
    } else if (root->left_child == NULL) {
        return bst_minimum(root->right_child);
    } else {
        return bst_minimum(root->left_child);
    }
}


BSTNode* bst_delete(BSTNode* root, BSTNode* pointer) {
    if (pointer->right_child == NULL && pointer ->left_child == NULL) {
        // No child case
        if (pointer->parent != NULL) {
            if (pointer->income > pointer->parent->income || (
                    pointer->income == pointer->parent->income && pointer->asset > pointer->parent->asset)) {
                assert(pointer->parent->right_child == pointer);
                pointer->parent->right_child = NULL;
            } else {
                assert(pointer->parent->left_child == pointer);
                pointer->parent->left_child = NULL;
            }
        }
    } else if (pointer->right_child == NULL) {
        // Only Left child exists
        if (pointer->parent != NULL) {
            if (pointer->income > pointer->parent->income || (
                    pointer->income == pointer->parent->income && pointer->asset > pointer->parent->asset)) {
                assert(pointer->parent->right_child == pointer);
                pointer->parent->right_child = pointer->left_child;
                pointer->left_child->parent = pointer->parent;
            } else {
                assert(pointer->parent->left_child == pointer);
                pointer->parent->left_child = pointer->left_child;
                pointer->left_child->parent = pointer->parent;
            }
        }
    } else if (pointer->left_child == NULL) {
        // Only Right child exists
        if (pointer->parent != NULL) {
            if (pointer->income > pointer->parent->income || (
                    pointer->income == pointer->parent->income && pointer->asset > pointer->parent->asset)) {
                assert(pointer->parent->right_child == pointer);
                pointer->parent->right_child = pointer->right_child;
                pointer->right_child->parent = pointer->parent;
            } else {
                assert(pointer->parent->left_child == pointer);
                pointer->parent->left_child = pointer->right_child;
                pointer->right_child->parent = pointer->parent;
            }
        }
    } else {
        // Both children exist
        BSTNode* swap_with = bst_minimum(pointer->right_child);
        pointer->asset = swap_with->asset;
        pointer->income = swap_with->income;
        bst_delete(root, swap_with);
    }

    free(pointer);
    return NULL;
}

AssetType bst_get_assets_below_income(BSTNode* root, IncomeType income) {
    if (root == NULL) {
        return 0;
    } else if (income >= root->income) {
        return root->asset + (root->left_child == NULL ? 0 : root->left_child->subtree_asset) +
                bst_get_assets_below_income(root->right_child, income);
    } else {
        return bst_get_assets_below_income(root->left_child, income);
    }
}
