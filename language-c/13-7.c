#include <stdatomic.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>

#include "stdio.h"

#define Maxsize 50

typedef int ElemType;
typedef struct link_q {
    ElemType data;
    struct link_q *next;
} link_q;
link_q *front, *rear;

void init_queue(link_q *q) {
    front = rear = (link_q *)malloc(sizeof(link_q));
    front->next = NULL;
}

// bool isEmpty(link_q *q) { return q->rear == q->front; }

bool EnQueue(link_q *q, ElemType x) {
    link_q *p = (link_q *)malloc(sizeof(link_q));
    p->data = x;
    p->next = NULL;
    rear->next = p;
    rear = p;

    return true;
}

int main() {
    printf("hello\n");
    link_q Q;
   init_queue(&Q);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);
    link_q *p = front;
    while (p) {
        printf("num:%d\n", p->data);
        p = p->next;
    }
    return 0;

