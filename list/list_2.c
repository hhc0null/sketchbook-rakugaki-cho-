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

static list_t* _malloc_list(const int _number);
static void _set_value_to_element(list_t* _list, const int _value);
static void _set_ptr_to_next(list_t* _list, list_t* _next_element);
static list_t *_get_nextptr(list_t *_list);
static list_t *_get_ptr(list_t *_list);
static void _free_list(list_t* _list);

int main(void)
{
    list_t *tmp = NULL;
    list_t *aaa = NULL;
    list_t *bbb = NULL;
    list_t *ccc = NULL;

    tmp = create_empty_list();
    aaa = create_empty_list();
    bbb = create_empty_list();
    ccc = create_empty_list();

    set_element(tmp, 0xff);
    set_element(aaa, 0x10);
    set_element(bbb, 0x80);
    set_element(ccc, 0x80);

    set_nextptr(tmp, aaa);
    set_nextptr(aaa, bbb);
    set_nextptr(bbb, ccc);
    set_nextptr(ccc, NULL);

    destroy_list(tmp);
    destroy_list(aaa);
    destroy_list(bbb);
    destroy_list(ccc);

    return 0;
}

extern list_t *create_empty_list(void)
{
    list_t *list = NULL;

    list = _malloc_list(1);
    if(list == NULL) {
        puts("Failed...");
        exit(-1);
    }

    return list;
}

extern bool set_element(list_t *list, const int value)
{
    _set_value_to_element(list, value);
    return (list->element != value)?false : true;
}

extern bool set_nextptr(list_t *list, list_t *next_list)
{
    _set_ptr_to_next(list, next_list);
    return (list->next != &(next_list->element))?false : true;
}

extern bool is_empty(list_t *list)
{
    return (list == NULL)? true : false;
}

extern void prepend_list(list_t *prev, const int value)
{
    list_t *next = NULL;
    list_t *list = NULL;

    next = _get_nextptr(prev);
    _set_value_to_element(list, value);

    _set_ptr_to_next(prev, list);
    _set_ptr_to_next(list, next);
}

extern list_t* determine_first(list_t *list)
{
    // TODO: implemention.
    return NULL;
}

extern bool destroy_list(list_t *list)
{
    _free_list(list);
    return (list == NULL)? true : false;
}
 
static list_t *_malloc_list(const int _number)
{
    return (list_t *)malloc(sizeof(list_t)*_number);
}

static void _set_value_to_element(list_t* _list, const int _value)
{
    _list->element = _value;
}

static void _set_ptr_to_next(list_t* _list, list_t* _next_list)
{
    _list->next = &(_next_list->element);
}

static list_t *_get_nextptr(list_t *_list)
{
    return (list_t *)(_list->next);
}


static void _free_list(list_t* _list)
{
    free(_list);
}
