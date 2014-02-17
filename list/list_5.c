#include "list.h"

// external

// internal

int main(void)
{
    list_t *list;
    node_t *a, *b, *c, *d, *e, *tmp;

    // 1st
    list = NULL;
    list = (list_t*)malloc(sizeof(list_t)*1);
    list->head = NULL;

    // 2nd
    a = (node_t*)malloc(sizeof(node_t)*1);
    a->next = NULL;
    a->entity = 0;
    list->head = a;

    // 3rd
    (list->head)->entity = 1;

    // 4th
    b = (node_t*)malloc(sizeof(node_t)*1);
    b->next = NULL;
    b->entity = 2;
    (list->head)->next = b;

    // 5th
    c = (node_t*)malloc(sizeof(node_t)*1);
    c->next = NULL;
    c->entity = 3;
    ((list->head)->next)->next = c;

    // 6th
    d = (node_t*)malloc(sizeof(node_t)*1);
    d->next = NULL;
    d->entity = 5;
    (((list->head)->next)->next)->next = d;

    // 7th
    (((list->head)->next)->next)->entity = 3;

    // 8th
    e = (node_t*)malloc(sizeof(node_t)*1);
    e->next = list->head;
    e->entity = 1;
    list->head = e;

    // show
    tmp = list->head;
    for(int i = 0; tmp != NULL; i++) {
        printf("%d\n", tmp->entity);
        tmp = tmp->next;
    }

    // 9th, destroy
    tmp = list->head;
    for(int i = 0; tmp != NULL; i++) {
        free(list->head);
        list->head = tmp->next;
        tmp = tmp->next;
    }
    free(list);

    printf("%d\n", d->entity);
    return 0;
}

// external

// internal
struct _node_t* _addnode(struct _node_t* orig)
{
    struct _node_t* add;
    add = (struct _node_t*)malloc(sizeof(struct _node_t)*1);
    add->next = orig->next;
    add->entity = 0;
    return add
}
struct _node_t* _delnode(struct _node_t* del)
{
    struct _node_t* tmp;
    tmp = del->next;
    free(del);
    return tmp;
}
