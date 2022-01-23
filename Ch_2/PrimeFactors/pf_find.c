#include <stdlib.h>
#include <stdio.h>

// Finds prime factors of integers from 1 to whatever user input number is

#define is_factor(a, b) (((float)b/(float)a) - (int)(b/a) == 0)

typedef struct factor_des {
    int f;
    struct factor_des *prev;
} factr;

factr* newFactor(int fac) {
    factr *nw = (factr*)malloc(sizeof(factr));
    nw->f = fac;
    nw->prev = NULL;
    return nw;
}

void printFactor(factr* fc) {
    if (fc->prev) {
        printf("%d x ", fc->f);
        if (fc->prev->prev) {
            printFactor(fc->prev);
        }
        else {
            printf("%d", fc->prev->f);
        }
    }
    else {
        printf("%d", fc->f);
    }
}

// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

int main() {
    int max, prime;
    printf("Till what number do you want the prime factors of? :");
    scanf("%d", &max);

    printf("Computing prime factors of all numbers from 1 to %d\n", max);
    factr** numbers = malloc(max * sizeof(factr*));

    numbers[0] = newFactor(1);
    printf("1: {"); printFactor(numbers[0]); printf("}\n");
    numbers[1] = newFactor(2);
    printf("2: {"); printFactor(numbers[1]); printf("}\n");

    for (int i = 3; i <= max; i++) {
        prime = 1;
        for (int j = 2; j < i; j++) {
            if (is_factor(j, i)) {
                numbers[i - 1] = newFactor(j);
                numbers[i - 1]->prev = numbers[(i / j) - 1];
                prime = 0;
                break;
            }
        }
        if (prime) {
            numbers[i - 1] = newFactor(i);
        }
        printf("%d: {", i); printFactor(numbers[i - 1]); printf("}\n");
    }

    for (int i = 0; i < max; i++) { free(numbers[i]); }
    free(numbers);
    // printf("Cleaned all memory successfully\n");
    return 0;
}