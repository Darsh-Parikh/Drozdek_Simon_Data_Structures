#ifndef _LIST_INFO_H_
#define _LIST_INFO_H_

#include<stdio.h>
#include<stdlib.h>
#include "list_data.h"
#include "listHidden.h"

void makeList(int);
int getListLength();
void deleteList();

List* nodeAtIndex(int i);

void printList(char[]);

int reverseList();
int reverseListIntermediate(List*);
int reverseListPart(List*, int);

int sortList();
int sortListPart(List*, int);

#endif