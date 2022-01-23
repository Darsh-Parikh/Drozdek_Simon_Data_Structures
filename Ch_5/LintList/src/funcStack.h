#ifndef FUNCTIONS_VARIABLE_STACK_H
#define FUNCTIONS_VARIABLE_STACK_H

#include <stdlib.h>
#include "varList.h"

typedef struct variables_ls {
    int FUNC_DEPTH;
    v_list *Head, *Last;
} func_stack;

func_stack* get_function_stack();

void initializeFunctionStack();
void pushFunctionsList();
void popFunctionsList();

#endif