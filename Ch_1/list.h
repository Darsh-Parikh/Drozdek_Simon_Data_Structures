#ifndef LIST_H
#define LIST_H

#include"trans.h"

#define MAXLIST 10

typedef struct {
    listdatatype elements[MAXLIST];
    int counter;
} List;

int addList(List*, listdatatype);
void initList(List*);
void eachElement(List, void(*)(listdatatype));

#endif