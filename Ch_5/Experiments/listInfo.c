#include <stdio.h>
#include <stdlib.h>
#include "list_data.h"
#include "listInfo.h"
#include "listHidden.h"

void makeList(int n) {
    MY_LIST_LEN = n;
    int k = n,  i = k - 1;
    Head = Last = _makeListNode(n - i);
    k -= 1;
    while (k-- > 0) {
        i--;
        List *l = _makeListNode(n - i);
        Last->next = l;
        Last = l;
    }
}

int _listLen(List* l) {
    if (l->next) { return 1 + _listLen(l->next); }
    else { return 1; }
}

int getListLength() {
    return _listLen(Head);
}

void deleteList() {
    List *l = Head;
    while (l) {
        List *tmp = l->next;
        free(l);
        l = tmp;
    }
}

/*Indexing from 0*/
List* nodeAtIndex(int idx) {
    if (idx > MY_LIST_LEN - 1) { return NULL; }
    List* nati = Head;
    for (int i = 0; i < idx; i++) {
        nati = nati->next;
    }
    return nati;
}

void printList(char str[]) {
    printf("%s: ", str);
    _printList(Head);
}