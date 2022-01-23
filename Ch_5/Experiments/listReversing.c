#include "listInfo.h"
#include "listHidden.h"

void iterdebug(List*, List*);
List* _Iterative_reverser(List*, List*);

/*Reverses the whole List.*/
int reverseList() {
    List *t_l = Head;
    Head = _Iterative_reverser(Head, Last);
    Last = t_l;
    return 1;
}

/*Reverses the list after the starting element.*/
int reverseListIntermediate(List *start) {
    if (!start) { ll_err("Reverse", 1); return 0; }
    List* t_l = start->next;
    start->next = _Iterative_reverser(start, Last);
    Last = t_l;
    return 1;
}

/*Reverses the list, but only the len elements after the starting element.*/
int reverseListPart(List *start, int len) {
    if (!start) { ll_err("Reverse", 1); return 0; }
    List *t_l = start->next, *end;
    int i, l = 0;
    for (i = len; i > 0 && t_l; t_l = t_l->next) {
        if (i == 1) { end = t_l; }
        i--;
    }
    if (i && end != Last) { ll_err("Reverse", 2); return 0; } /*len > size of list*/
    else if (end == Last) {
        l = 1;
        t_l = start->next;
    }
    start->next = _Iterative_reverser(start, end);
    if (l) { Last = t_l; }
    return 1;
}

List* _Iterative_reverser(List *start, List *end) {
    List *endpoint = end->next, *tmpH = endpoint, *tmpNx, *nx;
    int reached = 0, from_head = 0;
    if (start == Head) { from_head = 1; }
    while (!reached) {
        tmpNx = from_head ? start->next : start;
        nx = from_head ? tmpNx : tmpNx->next->next;
        List *tmp = _removeNextNode(start);
        tmp->next = tmpH;
        tmpH = tmp;
        if ((nx) == endpoint) { reached = 1; }
        if (__WANTS_INFO) { iterdebug(tmp, tmpH); }
        start = tmpNx;
    }
    return tmpH;
}

void iterdebug(List *t, List *tmphead) {
    printf("Worked on node "); printNodeInfo(t, "\n");
    printList("\t main");
    printf("\t othr: ");
    _printList(tmphead);
}