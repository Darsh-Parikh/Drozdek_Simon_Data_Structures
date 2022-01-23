#include <stdio.h>
#include "variable_functions.h"

void test();

int main() {
    printf("----Running the Lint program\n\n");
    test();

    return 0;
}

void test() {
    startProgram();
        makeVariable("x"); //S
        assignToVariable("x", 4); //S
        makeVariable("yellow"); //S
        assignToVariable("boo", 100); //F
        initVariableWithVal("boo", 200); //S

        startFunction();
            initVariableWithVal("lk", 2); //S
            initVariableWithVal("yellow", 5); //F
            assignToVariable("yellow", 6); //S

            startFunction();
                makeVariable("x"); //S
                initVariableWithVal("lk", 17); //S
                printAllVariables();
            endFunction();
        
        endFunction();

        startFunction();
            initVariableWithVal("new_variable", 5); //S
            makeVariable("boo"); //F
                printAllVariables();
            makeVariable("Another"); //S
        endFunction();

            printAllVariables();
    endProgram();
}