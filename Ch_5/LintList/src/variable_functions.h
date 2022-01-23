#ifndef VARIABLE_FUNCTIONS_H
#define VARIABLE_FUNCTIONS_H

#include "varDataType.h"
#include "listPrinting.h"

void startProgram();
void endProgram();

int makeVariable(char*);
void assignToVariable(char*, VAR_DATA_TYPE);
void initVariableWithVal(char*, VAR_DATA_TYPE);

void startFunction();
void endFunction();

#endif