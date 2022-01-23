#include<stdio.h>
#include"database.h"

void printCount(char* word, int n) {
    printf("%20s %5d\n", word, n);
}

int main() {
    char word[21];
    int count;
    indextype idx;

    while (scanf("%20s", word) == 1) {
        if (findRec(word, &count, &idx)) {
            setRec(idx, count + 1);
        }
        else if (!createRec(word, 1, idx)) {
            printf("Error: cannot add word %s. Database is full.\n", word);
        }
    }
    eachRec(&printCount);

    return 0;
}