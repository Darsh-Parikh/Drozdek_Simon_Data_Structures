
#include"lltype.h"

typedef struct llList {
    llElement* Head;
    llElement* Tail;
    int size;
} aLinkedList;

/*Gets the data from the element by providing its index.*/
const lld_type getElementData(ll_idx);
/**/
void updateElement(ll_idx, lld_type);

