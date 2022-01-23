#include "listInfo.h"

int reversing_tests(int, int), sorting_test(int, int);

int main() {
    // NEED_INFO();
    GIVE_POINTERS();
    
    makeList(10);
    printList("O");

    printf("\n\t\t\t\t+++ Reversing Tests +++\n");
    if (!reversing_tests(3, 4)) { return -1; }
    
    printf("\n\t\t\t\t+++ Sorting Tests +++\n");
    if (!sorting_test(3, 4)) { return -1; }

    printf("\nEnd of testing\n");
    deleteList();
    return 0;
}

int reversing_tests(int idx, int amnt) { // Reverse randomly at the end..
    List* n = nodeAtIndex(idx);
    
    printf("-- Reversing the whole list\n");
    if (reverseList()) {
        printList("R");
        printf("Re-ordering the list again.\n");
        reverseList();
        printList("R");
    }
    else {
        printf("ERROR while reversing the whole list\n");
        return 0;
    }

    // printf("-- Reversing the list after Node: "); printNodeInfo(n, "\n");
    // if (reverseListIntermediate(n)) {
    //     printList("R");
    //     printf("Re-ordering the list again.\n");
    //     reverseListIntermediate(n);
    //     printList("R");
    // }
    // else {
    //     printf("ERROR while reversing the list after index %d\n", idx);
    //     return 0;
    // }

    // printf("-- Reversing %d nodes after Node: ", MY_LIST_LEN+1); printNodeInfo(n, "\n");
    // printf("NOTE: This will FAIL, since the number of nodes to reverse is more than the size of the list\n");
    // reverseListPart(n, MY_LIST_LEN+1);
    // printList("R");

    // printf("-- Reversing %d nodes after Node: ", amnt); printNodeInfo(n, "\n");
    // printf("NOTE: This does work\n");
    // if (reverseListPart(n, amnt)) {
    //     printList("R");
    // }
    // else {
    //     printf("ERROR while reversing the middle of the list\n");
    //     return 0;
    // }

    printf("\nThe list will be kept partially reversed so as to test sorting\n");
    return 1;
}

int sorting_test(int idx, int amnt) {
    printf("eh...\n");
    // printf("Making it normal again by sorting\n");
    // sortList();
    // printList("S");
    return 1;
}
