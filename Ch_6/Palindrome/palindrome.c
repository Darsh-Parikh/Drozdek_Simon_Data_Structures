#include <stdio.h>
#include <ctype.h>
#include "string_stacks.h"

int usage(), getSize(char*), copy(char*, Sstack*, int), getCase(int*);

int is_palindrome(Sstack* input, Sstack *reverse) {
    char chr;
    int i = 0;
    while (reverse->top <= input->top) {
        if ((chr = pop(input))) { push(reverse, chr); }
        else { printf("Popped too much from the input stack\n"); i = -1; break; } /*Should not happen here but still*/
        int idx = reverse->top;
        if (reverse->string[idx] != input->string[idx]) { i = 0; break; } /*nth last letter not the same as nth first letter*/
        if (idx == input->top - 1) { i = 1; break; } /*For odd number sized words*/
    }
    return i;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Incorrect usage\n");
        printf("Provide a string (a word) as an arguement when running the program\n");
        printf("Example: palindrome.exe word\n");
        return -1;
    }

    int Case, s;
    if (!(s = getSize(argv[1]))) { return -1; }
    getCase(&Case);

    Sstack *inp = newStack(s);
    copy(argv[1], inp, Case);
    Sstack *rev = newStack(s);

    if (is_palindrome(inp, rev) > 0) { printf("%s is a palindrome\n", argv[1]); }
    else { printf("%s is not a palindrome\n", argv[1]); }

    deleteStack(inp);
    deleteStack(rev);
    return 0;
}


int getSize(char *str) {
    int s;
    char chr;
    for (s = 0; (chr = str[s]) != '\0'; s++) { /*Find length of string*/
        if (!isalpha(chr)) {
            printf("'word' %s contains non letter character %c. Give a valid word\n", str, chr);
            return 0;
        }
    }
    if (s < 2) { //? Can it be 0?
        printf("%d letter words do not count as palindromes. Give a larger word\n", s);
        return 0;
    }
    return s;
}

int getCase(int *cs) {
    char chr;
    while (1) {
        printf("Do you want to be case sensitive? (y or n): ");
        scanf("%c", &chr);
        if (chr == 'y') { (*cs) = 1; break; }
        else if (chr == 'n') { (*cs) = 0; break; }
    }
    return 1;
}

int copy(char *str, Sstack *input, int cs) {
    if (cs) {
        for (int s = 0; s < input->max; s++) { push(input, str[s]); }
    }
    else {
        for (int s = 0; s < input->max; s++) { push(input, tolower(str[s])); }
    }
    return 1;
}