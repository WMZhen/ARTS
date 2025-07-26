#include <bits/bionic_multibyte_result.h>
#include <stdbool.h>

#include "stdio.h"

#define MAXSIZE 50

typedef int ElemType;

typedef struct Btree {
    char c;
    struct btree *lchild;
    struct btree *rchild;
} btree;
typedef struct tag {
    btree p;
    struct tag *pnext;
} tag_t, *ptag_t;

int main() {
    printf("14.2tree\n");

    btree pnew;
    btree tree = NULL;
    char c;
    ptag_t listp = NULl, phea = NULL, ptail = NULL, pcur = NULL;
    while (scanf("%c", &c)) {
        if (c == '\n') {
            break;
        }
        pnew = (btree)calloc(1, sizezof(btree));
        pnew->c = c;
        listp = (btree)calloc(1, sizezof(tag_t));
        listp->p = pnew;
        if (NULL == tree) {
            tree = pnew;
            phea = listp;
            ptail = listp;  //
        } else {
            // 让元素先入队
            ptail->pnext = listp;
            ptail = listp;
            if (NULL == pcur->p->lchild) {
                pcur->p->lchild = pnew;
            } else if (NULL == pcur->rchild) {
                pcur->p->rchild = pnew;
                pcur = pcur->pnext;
            } else {
            }
        }
    }
    return 0;
}
