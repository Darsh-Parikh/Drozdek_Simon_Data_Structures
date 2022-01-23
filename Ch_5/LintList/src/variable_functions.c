#include <stdio.h>
#include "lintWarnings.h"
#include "variable_functions.h"
#include "funcStack.h"

int __Started = 0;

void startProgram() {
    if (__Started) {
        printf("StartProgram: Program has already been started\n");
        return;
    }
    if (__WANTS_CHANGES) {
        printf("Starting the Program\n");
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    }
    initializeFunctionStack();
    __Started++;
}

void endProgram() {
    if (!__Started) {
        printf("EndProgram: No program has been started yet\n");
        return;
    }
    if (__WANTS_CHANGES) {
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("Closing the Program\n");
    }
    func_stack *allVariables = get_function_stack();
    while (allVariables->FUNC_DEPTH--) {
        popFunctionsList();
    }
    popFunctionsList(); // Global list at depth 0
    free(allVariables);
    __Started--;
}

int makeVariable(char* var_name) {
    if (!__Started) {
        printf("MakeFunction: No program has been started yet\n");
        return 0;
    }
    if (__WANTS_CHANGES) { printf("\tAttempting to make variable '%s': ", var_name); }
    func_stack *allVariables = get_function_stack();
    if (doesListContain(allVariables->Head, var_name)) {
        printf("FAILURE\n");
        lintWarning(1, var_name);
        return 0;
    } else if (doesListContain(allVariables->Last, var_name)) {
        printf("FAILURE\n");
        lintWarning(2, var_name);
        return 0;
    } else {
        printf("SUCCESS\n");
        addVarToList(allVariables->Last, var_name);
        return 1;
    }
}

void assignToVariable(char* var_name, VAR_DATA_TYPE var_data) {
    if (!__Started) {
        printf("AssignmentFunction: No program has been started yet\n");
        return;
    }
    if (__WANTS_CHANGES) { printf("\tAttempting to assign %d to '%s':", var_data, var_name); }
    v_node *var;
    func_stack *allVariables = get_function_stack(); 
    if ((var = doesListContain(allVariables->Head, var_name))) {
        printf("SUCCESS\n");
        var->val = var_data;
    } else if ((var = doesListContain(allVariables->Last, var_name))) {
        printf("SUCCESS\n");
        var->val = var_data;
    }
    else {
        printf("FAILURE\n");
        lintWarning(3, var_name);
    }
}

void initVariableWithVal(char* var_name, VAR_DATA_TYPE var_data) {
    if (!__Started) {
        printf("InitFunction: No program has been started yet\n");
        return;
    }
    if (makeVariable(var_name)) {
        assignToVariable(var_name, var_data);
    }
}

void startFunction() {
    if (!__Started) {
        printf("StartFunction: No program has been started yet\n");
        return;
    }
    if (__WANTS_CHANGES) {
        printf("--------------------------------------\n");
        printf("--Starting new function\n");
    }
    pushFunctionsList();
}

void endFunction() {
    if (!__Started) {
        printf("EndFunction: No program has been started yet\n");
        return;
    }
    if (__WANTS_CHANGES) {
        printf("--Exiting function\n");
        printf("--------------------------------------\n");
    }
    popFunctionsList();
}