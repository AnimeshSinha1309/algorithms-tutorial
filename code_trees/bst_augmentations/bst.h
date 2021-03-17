#ifndef ALGORITHMS_TUTORIAL_BST_H
#define ALGORITHMS_TUTORIAL_BST_H

typedef int AssetType;
typedef int IncomeType;

typedef struct BinarySearchTreeNode {
    IncomeType income;
    AssetType asset;
    AssetType subtree_asset; // Augmentation

    struct BinarySearchTreeNode* parent;
    struct BinarySearchTreeNode* left_child;
    struct BinarySearchTreeNode* right_child;
} BSTNode;

BSTNode* bst_insert(BSTNode* root, IncomeType income, AssetType asset);
BSTNode* bst_find(BSTNode* root, IncomeType income, AssetType asset);
BSTNode* bst_minimum(BSTNode* root);
void bst_print(BSTNode* root);
BSTNode* bst_delete(BSTNode* root, BSTNode* pointer);
AssetType bst_get_assets_below_income(BSTNode* root, IncomeType income);

#endif //ALGORITHMS_TUTORIAL_BST_H
