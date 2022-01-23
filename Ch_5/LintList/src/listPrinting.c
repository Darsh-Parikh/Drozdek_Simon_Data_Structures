#include <stdio.h>
#include "funcStack.h"
#include "listPrinting.h"

void printAllVariables() {
    printf("\n++++++++++ Printing all the variables +++++++++++\n");
    func_stack *allVariables = get_function_stack();
    printVarList("Global:", allVariables->Head);
    v_list *curr;
    if ((curr = allVariables->Head->next_list)) {
        int i = allVariables->FUNC_DEPTH, j = i - 1;
        while(curr) {
            printf("Function %d", i-j); printVarList(":", curr);
            curr = curr->next_list;
            j--;
        }
    }
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
}