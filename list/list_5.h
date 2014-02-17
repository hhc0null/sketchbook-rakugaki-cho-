#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _node_t {
    int entity;
    struct _node_t* next;
} node_t;

typedef struct _list_t {
    node_t* head;
} list_t;
