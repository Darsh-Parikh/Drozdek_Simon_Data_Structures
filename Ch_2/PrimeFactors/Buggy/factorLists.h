#ifndef FACTOR_LISTS_H
#define FACTOR_LISTS_H

typedef struct factor_node {
    int f;
    struct factor_node *next_f, *prev_f;
} fnode;

typedef struct factor_list {
    int num;
    fnode *Head, *Last;
} flist;

flist* newList();
void deleteList(flist*);
void appendEntireList(flist*, flist*);
void addFactor(flist*, int);
void printFactors(flist*);

#endif