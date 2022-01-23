#include <stdio.h>
#include <stdlib.h>
#include "factorLists.h"

#define is_factor(a, b) (((float)b/(float)a) - (int)(b/a) == 0)

int main() {
    int max, prime;
    printf("Till what number do you want the prime factors of? :");
    scanf("%d", &max);

    printf("Computing prime factors of all numbers from 1 to %d\n", max);
    flist** numbers = malloc(max * sizeof(flist*));
    for (int i = 0; i < max; i++) { numbers[i] = newList(); }
    
    addFactor(numbers[0], 1);
    addFactor(numbers[1], 2);
    
    for (int i = 3; i <= max; i++) {
        prime = 1; /*Assuming it is a prime*/
        for (int j = 2; j < i; j++) {/*to check if anything before i is a factor of i (except 1)*/
            if (is_factor(j, i)) {
                addFactor(numbers[i - 1], j);
                appendEntireList(numbers[i - 1], numbers[(i/j) - 1]);
                prime = 0; /*not a prime*/
                break;
            }
        }
        if (prime) {
            addFactor(numbers[i - 1], i);
        }
    }

    for (int i = 0; i < max; i++) {
        printf("%d : { ", (i + 1));
        printFactors(numbers[i]);
        printf(" }\n");
    }

    printf("Finishing the program now\n");
    for (int i = 0; i < max; i++) {
        deleteList(numbers[i]);
        printf("Removed %d\n", i+1);
    }
    printf("Cleaned memory used for storing factors\n");

    // for (int i = 1; i < max; i++) {
    //     appendEntireList(numbers[i], numbers[i-1]);
    // }
    // printFactors(numbers[max-1]);
    // deleteList(numbers[max-1]);

    free(numbers);
    printf("Cleaned all memory used. Exiting normally\n");
    return 0;
}