#include "list.h"

/* internal functions */
static list_t* int_list_addnode();
static void int_list_delnode();

int main(void)
{
    list_t* list = NULL;

    list = int_list_create(10);
    int_list_destroy(&list);

    return 0;
}

extern list_t* int_list_create(const int init)
{
    list_t* new_list = NULL;
    new_list = int_list_addnode();
    return new_list;
}

extern void int_list_destroy(list_t** del)
{
    list_t* list_ptr = NULL;

    for();
}

static list_t* int_list_addnode(list_t* , list_t* next)
{
    list_t* _list = NULL;

    _list = (list_t*)malloc(sizeof(list_t)*1);
    _list->data = data;
    _list->next = next;

    return _list;
}

static void int_list_delnode()
{
}
