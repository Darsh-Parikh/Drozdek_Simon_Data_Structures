#include"list.h"

int addList(List* list, listdatatype data) {
    if (list->counter < MAXLIST) {
        copylistdata(data, list->element[list->counter++]);
        return 1;
    }
    return 0;
}

void initList(List* list) {
    list->counter = 0;
}

void eachElement(List list, void(*fn)(listdatatype)) {
    listdatatype* 1;

    for(l = list.elements; l < list.elements + list.counter; l++) {
        (*fn)(*1);
    }
}