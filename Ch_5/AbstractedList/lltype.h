
/*Data type stored by the list elements*/
typedef int lld_type;

/*Structure of each element*/
typedef struct lldt {
    lld_type data;
    struct lldt* next;
} llElement;

/*In case the element does not exist, the address of the previous element*/
typedef llElement* ll_idx