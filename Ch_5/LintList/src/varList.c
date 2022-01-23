#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lintWarnings.h"
#include "varList.h"

v_node* _createVariable(char *var_name) {
    v_node *new_var = (v_node*)malloc(sizeof(v_node));
    new_var->name = strdup(var_name);
    new_var->val = 0;
    new_var->next_var = NULL;
    return new_var;
}

v_list* createVarList() {
    v_list *new_list = (v_list*)malloc(sizeof(v_list));
    new_list->head = NULL;
    new_list->next_list = new_list->prev_list = NULL;
    return new_list;
}

void deleteVarList(v_list *vlist) {
    v_node *hd = vlist->head;
    while (hd) {
        v_node *nxvr = hd->next_var;
        free(hd->name);
        free(hd);
        hd = nxvr;
    }
    free(vlist);
}

v_node* doesListContain(v_list *vlist, char *var_name) {
    v_node *curr = vlist->head;
    while(curr) {
        if (!strcmp(var_name, curr->name)) {
            return curr;
        }
        curr = curr->next_var;
    }
    return NULL;
}

void addVarToList(v_list* vlist, char* var_name) {
    if (!vlist) { return; }
    v_node *new_var = _createVariable(var_name);
    if (vlist->head) {
        new_var->next_var = vlist->head;    
    }
    vlist->head = new_var;
}

void printVarList(char* front, v_list* vlist) {
    printf("%s", front);
    v_node *hd = vlist->head;
    while (hd) {
        printf(" {%s : %d}", hd->name, hd->val);
        hd = hd->next_var;
    }
    printf("\n");
}