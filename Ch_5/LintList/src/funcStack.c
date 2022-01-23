#include <stdlib.h>
#include <stdio.h>
#include "funcStack.h"

static func_stack *funcVarsList = NULL;

#define GLOBAL_LIST funcVarsList->Head
#define CURR_FUNC_LIST funcVarsList->Last

func_stack* get_function_stack() {
    static int function_stack_amount = 0;
    if (!function_stack_amount) {
        function_stack_amount++;
        funcVarsList = (func_stack*)malloc(sizeof(func_stack));
    }
    return funcVarsList;
}

void initializeFunctionStack() {
    func_stack *allVariables = get_function_stack();
    allVariables->Head = allVariables->Last = createVarList();
    allVariables->Head->next_list = allVariables->Last->next_list = NULL;
    allVariables->Head->prev_list = allVariables->Last->prev_list = NULL;
    allVariables->FUNC_DEPTH = 0;
}

void pushFunctionsList() {
    func_stack *allVariables = get_function_stack();
    v_list *nx = allVariables->Last->next_list;
    allVariables->Last->next_list = createVarList();
    allVariables->Last->next_list->prev_list = allVariables->Last;
    allVariables->Last->next_list->next_list = nx;
    allVariables->Last = allVariables->Last->next_list;
    allVariables->FUNC_DEPTH++;
}

void deleteHead() {
    func_stack *allVariables = get_function_stack();
    deleteVarList(allVariables->Head);
}

void popFunctionsList() {
    func_stack *allVariables = get_function_stack();
    if (allVariables->Last == allVariables->Head) {
        deleteHead();
    }
    else {
        v_list *new_last = allVariables->Last->prev_list;
        new_last->next_list = allVariables->Last->next_list;
        deleteVarList(allVariables->Last);
        allVariables->Last = new_last;
        allVariables->FUNC_DEPTH--;
    }
}