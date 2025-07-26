#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int weight;
    struct Node *left, *right;
} Node;

// 创建新节点
Node* createNode(int weight) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->weight = weight;
    node->left = node->right = NULL;
    return node;
}

// 创建简单的哈夫曼树：只做演示用途（实际可用优先队列构建）
Node* buildSimpleHuffmanTree() {
    Node* A = createNode(5);
    Node* B = createNode(7);
    Node* C = createNode(2);
    Node* D = createNode(4);

    Node* node1 = createNode(0);
    node1->left = C;
    node1->right = A;
    Node* node2 = createNode(0);
    node2->left = B;
    node2->right = node1;
    Node* root = createNode(0);
    root->left = node2;
    root->right = D;

    return root;
}

// 递归计算 WPL
int calculateWPL(Node* root, int depth) {
    if (!root) return 0;

    // 叶子结点
    if (!root->left && !root->right) {
        return root->weight * depth;
    }

    return calculateWPL(root->left, depth + 1) +
           calculateWPL(root->right, depth + 1);
}

// 释放树内存
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = buildSimpleHuffmanTree();
    int wpl = calculateWPL(root, 0);
    printf("带权路径长度 (WPL) = %d\n", wpl);
    freeTree(root);
    return 0;
}
