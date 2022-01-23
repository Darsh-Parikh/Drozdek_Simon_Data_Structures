#ifndef _LIST_HIDDEN_H_
#define _LIST_HIDDEN_H_

#include <stdio.h>
#include "list_data.h"

List* _makeListNode();
void _addToEnd(List*);
void _addToFront(List*);
void _addInMiddle(List*, List*);

List* _removeFirstNode();
List* _removeLastNode();
List* _removeNextNode(List*);

void _printList(List*);

void ll_err(char[], int);

#endif