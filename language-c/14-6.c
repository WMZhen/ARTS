#include <stdio.h>
#include <stdlib.h>

// 二叉树结点结构
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建结点
TreeNode* createNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

#define MAX_SIZE 100

typedef struct {
    TreeNode* data[MAX_SIZE];
    int front, rear;
} Queue;

// 初始化队列
void initQueue(Queue* q) { q->front = q->rear = 0; }

// 判断队列是否为空
int isEmpty(Queue* q) { return q->front == q->rear; }

// 入队
void enqueue(Queue* q, TreeNode* node) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        printf("队列满了\n");
        return;
    }
    q->data[q->rear] = node;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

// 出队
TreeNode* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    TreeNode* node = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return node;
}

// 广度优先
void levelOrder(TreeNode* root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        TreeNode* node = dequeue(&q);
        printf("%c ", node->data);

        if (node->left) enqueue(&q, node->left);
        if (node->right) enqueue(&q, node->right);
    }
}

int main() {
    TreeNode* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->right = createNode('F');

    printf("层次遍历：");
    levelOrder(root);
    printf("\n");

    return 0;
}
