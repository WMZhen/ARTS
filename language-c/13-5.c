#include <stdatomic.h>
#include <stdbool.h>

#include "stdio.h"

#define Maxsize 50

typedef int ElemType;
typedef struct {
    ElemType data[Maxsize];
    int front, rear;
} sqqueue;

void init_queue(sqqueue *q) { q->front = q->rear = 0; }

bool isEmpty(sqqueue *q) { return q->rear == q->front; }

bool EnQueue(sqqueue *q, ElemType x) {
    if ((q->rear + 1) % Maxsize == q->front) {
        return false;
    } else {
        q->data[q->rear] = x;
        q->rear++;
        return true;
    }
}

bool Dequeue(sqqueue *q, ElemType x) {
    if (q->rear == q->front) return false;
    x = q->data[q->front];
    q->front = (q->front + 1) % Maxsize;
}

int main() {
    printf("hello\n");
    sqqueue Q;
    init_queue(&Q);
    bool ret;
    ret = isEmpty(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);
    for (int i = Q.front; i < Q.rear; i++) {
        printf("num :%d", Q.data[i]);
    }

    return 0;
}
