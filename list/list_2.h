#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _list_t {
    int element;
    struct _list_t* next;
} list_t;
    
extern list_t* create_empty_list(void);
extern bool set_element(list_t *list, const int value);
extern bool set_nextptr(list_t *list, list_t *next_list);
extern bool is_empty(list_t *list);
extern void prepend_list(list_t *back, const int value);
extern list_t* determine_first(list_t *list);
extern bool destroy_list(list_t *list);
