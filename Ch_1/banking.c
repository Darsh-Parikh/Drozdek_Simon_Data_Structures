#include<stdio.h>
#include"trans.h"
#include"database.h"
#include"list.h"
#include"accounts.h"

void printStatement(int acctNo, AcctData acctRec) {
    Transaction trans;

    printf("Account number: %8d, Balance = %d.\n", acctNo, acctRec.balance);
    eachElement(acctRec.transactions, &printTransaction);
}

void printError(int acctNo, Transaction trans) {
    printf("Error: Transaction not processed: %d %d %d.\n", acctNo, trans.date, trans.amount);
}

int main() {
    int acctNo;
    Transaction trans;
    AcctData acctRec;
    indextype idx;

    while (scanf("%d%d%d", &acctNo, &trans.date, &trans.amount) == 3) {
        if (findRec(acctNo, &acctRec, &idx)) {
            acctRec.balance += trans.amount;
            if (addList(&acctRec.transactions, trans)) {
                setRec(idx, acctRec);
            }
            else {
                printError(acctNo, trans);
            }
        }
        else {
            acctRec.balance = trans.amount;
            initList(&acctRec.transactions);
            if (!addList(&acctRec.transactions, trans) || !createRec(acctNo, acctRec, idx)) {
                printError(acctNo, trans);
            }
        }
    }
    eachRec(&printStatement);

    return 0;
}