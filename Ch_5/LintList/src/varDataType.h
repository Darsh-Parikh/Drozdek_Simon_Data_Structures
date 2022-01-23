#ifndef VARIABLE_DATA_TYPE_H
#define VARIABLE_DATA_TYPE_H

#define __WANTS_CHANGES 1

typedef int VAR_DATA_TYPE;

typedef struct variable_node {
    char *name;
    VAR_DATA_TYPE val;
    struct variable_node *next_var;
} v_node;

#endif