#include <stdio.h>
#include <stdlib.h>

typedef struct _list_t {
    int data;
    struct _list_t* next;
} list_t;

extern list_t* int_create_list(const int init);
