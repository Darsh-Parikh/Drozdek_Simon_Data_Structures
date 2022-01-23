#include <stdio.h>
#include <stdlib.h>
#include "string_stacks.h"

Sstack* newStack(int size) {
    Sstack *new_stack = (Sstack*)malloc(sizeof(Sstack));
    new_stack->string = (char*)malloc(sizeof(char) * size);
    new_stack->top = -1;
    new_stack->max = size;
    for (int i = 0; i < size; i++) { new_stack->string[i] = '\0'; }
    return new_stack;
}

void deleteStack(Sstack *st) {
    free(st->string);
    free(st);
}

void push(Sstack* st, char c) {
    if (st->top > st->max - 1) {
        printf("Stack is full\n");
        return;
    }
    st->string[++st->top] = c;
}

char pop(Sstack *st) {
    if (st->top < 0) {
        printf("Stack is empty\n");
        return '\0';
    }
    return st->string[st->top--];
}

void printStack(Sstack *st) {
    printf("Stack: %s, top: %d\n", st->string, st->top);
}