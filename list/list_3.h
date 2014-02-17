#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _list_t {
    int data;
    struct _list_t* next;
} list_t;

// --- external functions
// constructor
extern list_t* int_list_create(const int data);
// destructor
extern int int_list_destroy(list_t **list);
// insert an entity
extern int int_list_insert(list_t **list, int pos, const int data);
// get an entity
extern int int_list_get(list_t **list, const int pos);
// append an entity
extern int int_list_append(list_t **list, const int data);
// get size of list
extern int int_list_size(list_t **list);
