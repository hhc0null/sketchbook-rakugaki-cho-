/*
 * Int List structure
 *
 * ---
 * Implementation of the list data structure may provide some of the following operations:
 *
 *     a constructor for creating an empty list;
 *     an operation for testing whether or not a list is empty;
 *     an operation for prepending an entity to a list
 *     an operation for appending an entity to a list
 *     an operation for determining the first component (or the "head") of a list
 *     an operation for referring to the list consisting of all the components of a list except for its first (this is called the "tail" of the list.)
 * ---
 * (quoted from wikipedia.)
 *
 */

#include "list.h"

// internal functions
static struct _list_t* int_list_addnode(struct _list_t* _add, const int _data, struct _list_t* _next);
static struct _list_t* int_list_delnode(struct _list_t* _del);
static int int_list_getlen(struct _list_t** _list);

int main(void)
{
    list_t* list1 = NULL;
    int list1_length = 0;

    list1 = int_list_create(10);

    for(int i = 0; i < 5; i++) {
        list1_length = int_list_append(&list1, i+1);
    }

    for(int i = 0; i < list1_length; i++) {
        printf("list1(%02d): %d\n", i, int_list_get(&list1, i));
    }

    list1_length = int_list_destroy(&list1);

    return 0;
}

extern list_t* int_list_create(const int data)
{
    list_t* new = NULL;

    new = int_list_addnode(new, data, NULL);

    return new;
}

extern int int_list_destroy(list_t **list)
{
    int length;

    for(;(*list)->next;){
        *list = int_list_delnode(*list);
    }

    length = int_list_size(list);

    return length;
}

extern int int_list_insert(list_t **list, int pos, const int data)
{
    int length;
    list_t *head = *list;
    
    length = int_list_getlen(&head);
    if(pos > length) {
        puts("OUT OF RANGE");
        exit(-1);
    }

    for(int i = 0; i < pos-1; i++) {
        printf("(*list)->data: %x\n", (*list)->data);
        *list = (*list)->next;
    }

    (*list)->next = int_list_addnode((*list)->next, data, (*list)->next);
    length = int_list_getlen(&head);

    return length;
}

extern int int_list_get(list_t **list, const int pos)
{
    list_t *tmp = NULL;

    if(pos >= int_list_getlen(list)) {
        puts("OUT OF RANGE");
        exit(-1);
    }

    tmp = *list;
    for(int i = 0; i < pos; i++) {
        tmp = tmp->next;
    }

    return tmp->data;
}

extern int int_list_append(list_t **list, const int data) {
    int index, length;

    index = int_list_getlen(list);
    printf("index: %d\n", index);
    length = int_list_insert(list, index, data);

    return length;
}

extern int int_list_size(list_t **list)
{
    int length = 0;

    length = int_list_getlen(list);

    return length;
}

static struct _list_t* int_list_addnode(struct _list_t* _add, const int _data, struct _list_t* _next)
{
    struct _list_t* _tmp = NULL;

    _tmp = (struct _list_t*)malloc(sizeof(struct _list_t) * 1);

    _tmp->data = _data;
    _tmp->next = _next;

    _add = _tmp;
    
    return _add;
}

static struct _list_t* int_list_delnode(struct _list_t* _del)
{
    struct _list_t* _tmp;

    _tmp = _del->next;
    free(_del);

    return _tmp;
}

static int int_list_getlen(struct _list_t** _list)
{
    int _length;

    for(_length = 0; *_list != NULL; _length++) {
        *_list = (*_list)->next;
    }

    return _length;
}
