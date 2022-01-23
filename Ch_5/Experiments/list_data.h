#ifndef _LIST_DATATYPE_H_
#define _LIST_DATATYPE_H_

#include <stdio.h>

int __WANTS_INFO;
#define NEED_INFO() __WANTS_INFO = 1 
#define STOP_INFO() __WANTS_INFO = 0

int __POINTER_INFO;
#define GIVE_POINTERS() __POINTER_INFO = 1
#define STOP_POINTERS() __POINTER_INFO = 0

typedef struct lst {
    int ID;
    struct lst *next;
} List;

List *Head, *Last;
int MY_LIST_LEN;

void printNodeInfo(List* p, char end[]);

#endif