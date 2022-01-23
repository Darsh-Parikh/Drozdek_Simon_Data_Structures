#include"database.h"

#define maxRec 1000

Dbrec db[maxRec];
int numRecs = 0;

int findRec(dbkeytype key, dbdatatype* data, indextype* idx) {
    int low = 0, high = numRecs - 1, found = 0, mid, cmp;

    // assuming db is sorted already
    while (!found && low <= high) {
        mid = (low + high) / 2;
        cmp = comparedbkey(key, db[mid].key);
        if (cmp < 0) {
            high = mid - 1;
        } else if (cmp > 0) {
            low = mid + 1;
        }
        else { found = 1; }
    }
    if (found) {
        *idx = db + mid;
        copydbdata((*idx)->data, *data);
    }
    else {
        *idx = db + low;
    }
    return found;
}

int createRec(dbkeytype key, dbdatatype data, indextype idx) {
    Dbrec* rec;

    if (numRecs == maxRec) { return 0; }
    for (rec = db + numRecs; rec > idx; rec--) {
        *rec = *(rec + 1);
    }
    copydbkey(key, idx->key);
    copydbdata(data, idx->data);
    numRecs++;
}

void setRec(indextype idx, dbdatatype data) {
    copydbdata(data, idx->data);
}

void eachRec(void (*fn)(dbkeytype, dbdatatype)) {
    Dbrec* rec;
    for (rec = db; rec < db + numRecs; rec++) {
        (*fn)(rec->key, rec->data);
    }
}