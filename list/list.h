#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _node_t {
    int entity;
    struct _node_t *next;
} node_t;

typedef struct _list_t {
    node_t *node;
} list_t;

// external functions 
void create(list_t **, int);
void destroy(list_t **);
void append(list_t **, int);
void prepend(list_t **, int);
void insert(list_t **, int, int);
void expunge(list_t **, int); // cannot use "delete" identifier
int size(list_t **);
int get(list_t **, int);

