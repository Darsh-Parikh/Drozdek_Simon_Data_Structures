#ifndef STRING_STACKS_H
#define String_STACKS_H

typedef struct string_stack {
    int max, top;
    char *string;
} Sstack;

Sstack* newStack();
void deleteStack(Sstack*);
void push(Sstack*, char);
char pop(Sstack*);
void printStack(Sstack*);

#endif