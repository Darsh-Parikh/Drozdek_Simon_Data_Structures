#ifndef VARIABLE_LIST_H
#define VARIABLE_LIST_H

#include "varDataType.h"

typedef struct variable_list {
    v_node *head;
    struct variable_list *next_list, *prev_list;
} v_list;

v_list* createVarList();
void deleteVarList(v_list*);
void addVarToList(v_list*, char*);
v_node* doesListContain(v_list*, char*);

void printVarList(char*, v_list*);

#endif