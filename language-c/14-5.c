#include <stdio.h>
#include <stdlib.h>

// 定义二叉树结点结构
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新结点
TreeNode* createNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// 前序遍历（根左右）深度优先遍历
void preorder(TreeNode* root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// 中序遍历（左根右）
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

// 后序遍历（左右根）
void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

int main() {
    // 构造树结构
    TreeNode* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->right = createNode('F');
    root->right->right->left = createNode('G');

    printf("前序遍历：");
    preorder(root);
    printf("\n");

    printf("中序遍历：");
    inorder(root);
    printf("\n");

    printf("后序遍历：");
    postorder(root);
    printf("\n");

    return 0;
}
