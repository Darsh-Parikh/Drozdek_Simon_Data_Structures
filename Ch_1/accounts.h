#ifndef ACCOUNTS_H
#define ACCOUNTS_h

#include"list.h"

typedef struct {
    int balance;
    List transactions;
} AcctData;

typedef int dbkeytype;
typedef AcctData dbdatatype;

#define comparedbkey(k1, k2)    (k1 - k2)
#define copydbkey(k1, k2)       (k2 = k1)
#define copydbdata(d1, d2)      (d2 = d1)

#endif