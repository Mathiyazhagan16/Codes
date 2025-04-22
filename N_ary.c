#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode** child;
    int childCount;
} TreeNode;

TreeNode* createTreeNode(int data, int childCount) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    node->childCount = childCount;
    if (childCount > 0) {
        node->child = (TreeNode**)malloc(childCount * sizeof(TreeNode*));
    } else {
        node->child = NULL;
    }
    return node;
}

TreeNode* genericToBinary(TreeNode* root) {
    if (!root || root->childCount == 0) {
        return root;
    }

    root->left = genericToBinary(root->child[0]);
    if (root->childCount == 1) {
        return root;
    }

    TreeNode* curr = root->left;
    for (int i = 1; i < root->childCount; i++) {
        curr->right = genericToBinary(root->child[i]);
        curr = curr->right;
    }

    return root;
}

void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    TreeNode* root = createTreeNode(5, 3);
    root->child[0] = createTreeNode(8, 2);
    root->child[1] = createTreeNode(2, 0);
    root->child[2] = createTreeNode(1, 0);

    root->child[0]->child[0] = createTreeNode(3, 0);
    root->child[0]->child[1] = createTreeNode(4, 0);

    TreeNode* binaryTree = genericToBinary(root);

    printTree(binaryTree);

    return 0;
}
