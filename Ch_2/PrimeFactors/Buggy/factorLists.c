#include <stdlib.h>
#include <stdio.h>
#include "factorLists.h"

fnode* newFactors(int a, fnode *front, fnode *end) {
    fnode *newf = (fnode*)malloc(sizeof(fnode));
    newf->f = a;
    newf->prev_f = front;
    newf->next_f = end;
    return newf;
}

flist* newList() {
    flist *new = (flist*)malloc(sizeof(flist));
    new->Head = new->Last = NULL;
    new->num = 0;
    return new;
}

void deleteList(flist* fl) {
    if (!fl) { return; }
    fnode *curr = fl->Head;
    if (curr->prev_f) { curr->prev_f->next_f = NULL; }
    while (curr) {
        fnode *nx = curr->next_f;
        free(curr);
        curr = nx;
    }
    free(fl);
}

void addFactor(flist* fl, int fac) {
    if (fl->Head) {
        fl->Last->next_f = newFactors(fac, fl->Last, fl->Last->next_f);
        fl->Last = fl->Last->next_f;
    }
    else {
        fl->Head = fl->Last = newFactors(fac, fl->Head, fl->Last);
    }
    fl->num++;
}

/*appends f2 behind f1. Lins it so following f2 will result in reaching nodes of f1*/
void appendEntireList(flist* f1, flist* f2) {
    if (f1->Head) {
        if (f2->Head) {
            f2->Head->prev_f = f1->Last;
            f1->Last->next_f = f2->Head;
            f1->Last = f2->Last;
        }
        else  { return; }
    }
    else {
        f1->Head = f2->Head;
        f1->Last = f2->Last;
    }
    f1->num += f2->num;
}

void printFactors(flist* fl) {
    fnode *curr = fl->Head;
    while (curr->next_f) {
        printf("%d, ", curr->f);
        curr = curr->next_f;
    }
    printf("%d", curr->f);
}