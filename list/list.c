// a bad implementation

#include "list.h"

// internal
static node_t *_addnode(node_t *, node_t *, const int);
static node_t *_delnode(node_t *, node_t *);

int main(void)
{
    /*** test code ***/
    list_t *list = NULL;

    create(&list, 0);

    printf("size(&list) = %d\n", size(&list));
    for(int i = 1; i < 5; i++) {
        append(&list, i*2);
        printf("size(&list) = %d\n", size(&list));
    }
    for(int i = 0; i < 8; i++) {
        printf("list[%d] = %d\n", i, get(&list, i));
    }

    prepend(&list, 100);
    printf("size(&list) = %d\n", size(&list));
    for(int i = 0; i < 8; i++) {
        printf("list[%d] = %d\n", i, get(&list, i));
    }
    insert(&list, 1, 39);
    for(int i = 0; i < 8; i++) {
        printf("list[%d] = %d\n", i, get(&list, i));
    }
    expunge(&list, 3);
    for(int i = 0; i < 8; i++) {
        printf("list[%d] = %d\n", i, get(&list, i));
    }

    destroy(&list);
}

// external
/* create a list */
void create(list_t **list, int entity)
{
    list_t *new = NULL;

    if( (new = (list_t *)malloc(sizeof(list_t)*1)) == NULL) {
        perror("Error: cannot allocate a space");
        exit(-1);
    }
    new->node = _addnode(new->node, NULL, entity);
    *list = new;
}

/* destroy a list */
void destroy(list_t **list)
{
    while((*list)->node->next != NULL) {
        (*list)->node = _delnode((*list)->node->next, (*list)->node);
    }
    free((*list)->node);
    free(*list);
}

/* put an entity at the end of a list. */
void append(list_t **list, int entity)
{
    node_t *ptr;

    ptr = (*list)->node;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = _addnode(ptr->next, NULL, entity);
}

/* put an entity at the front of a list. */
void prepend(list_t **list, int entity)
{
    // dirty trick
    (*list)->node = _addnode((*list)->node,(*list)->node, entity);
}

/* insert an entity to a list. */
void insert(list_t **list, int index, int entity)
{
    node_t *ptr;

    // dirty trick
    if(index >= size(list)) {
        printf("!!! Error: out of range. ");
    } else if(index == 0) {
        prepend(list, entity);
    } else {
        ptr = (*list)->node;
        for(int i = 1; i < index; i++)
            ptr = ptr->next;
        ptr->next = _addnode(ptr->next, ptr->next, entity);
    }
}

/* delete an entity from a list. */
void expunge(list_t **list , int index)
{
    node_t *ptr = NULL;

    // dirty trick
    if(index >= size(list)) {
        printf("!!! Error: out of range.");
    } else if(index == 0) {
        (*list)->node = _delnode(ptr, (*list)->node);
    } else {
        ptr = (*list)->node;
        for(int i = 1; i < index; i++) {
            ptr = ptr->next;
        }
        ptr = _delnode(ptr->next, ptr);
    }
}

int size(list_t **list)
{
    int len;
    node_t *ptr = NULL;

    ptr = (*list)->node;
    for(len = 0; ptr != NULL; len++)
        ptr = ptr->next;

    return len;
}

int get(list_t ** list, int index)
{
    int entity;
    node_t *ptr = NULL;

    if(index >= size(list)) {
        printf("!!! Error: out of range. ");
        entity = -1;
    } else {
        ptr = (*list)->node;
        for(int i = 0; i < index; i++)
            ptr = ptr->next;
        entity = ptr->entity;
    }
    
    return entity;
}

// internal
/* connect a node and a node. */
static node_t *_addnode(node_t *cur, node_t *next, const int entity)
{
    node_t *new = NULL;

    if( (new = (node_t *)malloc(sizeof(node_t))) == NULL) {
        perror("Error: cannot allocate a space.");
        exit(-1);
    }
    new->next = next;
    new->entity = entity;
    cur = new;

    return cur;
}

/* delete a node */
static node_t *_delnode(node_t *del, node_t *prev) 
{
    prev->next = del->next;
    free(del);
    return prev;
}
