#include <stdlib.h>
#include <stdio.h>
#include "list_data.h"
#include "listHidden.h"

List* _makeListNode(int i) {
    List *n = (List*)malloc(sizeof(List));
    n->ID = i;
    n->next = NULL;
    return n;
}

void _addToEnd(List* p) {
    Last->next = p;
    p->next = NULL;
}

void _addToFront(List* p) {
    p->next = Head->next;
    Head = p;
}

void _addInMiddle(List* prev, List* p) {
    p->next = prev->next;
    prev->next = p;
}

List* _removeFirstNode() {
    List* t = Head;
    Head = t->next;
    t->next = NULL;
    return t;
}

List* _removeLastNode() {
    return NULL;
}

List* _removeNextNode(List* n) {
    if (n == Head) {
        return _removeFirstNode();
    }
    List* t = n->next;
    n->next = t->next;
    t->next = NULL;
    return t;
}

void printNodeInfo(List* p, char end[]) {
    if (__POINTER_INFO) { printf("%d (%6x)%s", p->ID, p, end); }
    else { printf("%d%s", p->ID, end); }
}

void _printList(List* s) {
    if (!s) {
        printf("Empty...\n");
        return;
    }
    List* l;
    for (l = s; l->next; l = l->next) {
        printNodeInfo(l, " -> ");
    }
    printNodeInfo(l, "\n");
}

void ll_err(char type[], int id) {
    switch (id) {
        case 1: printf("\t%s Error: Starting node doesn't exist\n", type); break;
        case 2: printf("\t%s Error: len longer than length\n", type); break;
        default: printf("\t\t%s function error called with invalid id %d\n", type, id); break;
    }
}