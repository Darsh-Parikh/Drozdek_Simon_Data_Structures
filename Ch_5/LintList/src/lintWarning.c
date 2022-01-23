#include <stdio.h>
#include "lintWarnings.h"

/*
IDs:
    1: Variable Already Exists in Global
    2: Variable Already Exists in Local
    3: No Variable with that Name (aka Not Initialized)
*/
void lintWarning(int ID, char* n) {
    switch (ID) {
        case 1: printf("\t\t\tLINT WARNING: Variable %s cannot be created: Already Exists Globally\n", n); break;
        case 2: printf("\t\t\tLINT WARNING: Variable %s cannot be creates: Already Exists in the same Function\n", n); break;
        case 3: printf("\t\t\tLINT WARNING: Tried assigning to Variable %s when it does not exist\n", n); break;
        default : printf("warning function called with invalid ID %d", ID); break;
    }
}