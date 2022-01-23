#ifndef TRANS_H
#define TRANS_H

typedef struct {
    int date;
    int amount;
} Transaction;

typedef Transaction listdatatype

#define copylistdata(d1, d2) (d2 = d1)

void printTransaction(Transaction trans) {
    printf("Date: %d, Amount: %d\n", trans.date, trans.amount);
}

#endif