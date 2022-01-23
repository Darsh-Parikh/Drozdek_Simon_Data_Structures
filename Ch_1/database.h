#ifndef DATABASE
#define DATABASE

#include<stdio.h>
#include"words.h"

typedef struct dbrec {
    dbkeytype key;
    dbdatatype data;
} Dbrec;

typedef Dbrec* indextype;

int findRec(dbkeytype, dbdatatype*, indextype*);
int createRec(dbkeytype, dbdatatype, indextype);
void setRec(indextype, dbdatatype);
void eachRec(void (*)(dbkeytype, dbdatatype));

#endif