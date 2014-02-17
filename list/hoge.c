#include <stdio.h>
#include <stdlib.h>

/*
#define _DESTROY_LIST	0;
#define	_CREATE_LIST	1;
#define _INSERT_ENTITY	2;
#define	_

typedef void exception;

exception proc(struct _ilist*) {
    int i;
    exit(-1);
}
*/

typedef struc _inode {
    int entity;
    struct _inode *next;
}

typedef struct _ilist {
    struct _inode *firstnode;
} ilist;

/* there are external functions. */
// create a list
ilist* CreateList();
// insert an entity to a list
void InsertEntity(ilist*, int, int);
// delete an entity from a list
void DeleteEntity(ilist*, int);
// get an entity from a list
int GetEntity(ilist* , int);
// get a number of entities
int GetNumberOfEntity(ilist*);
// delete a list
void DeleteList(ilist*);
/* there are internal functions. */
// add a node
static struct _ilist* _AddNode(ilist*, int, ilist*);
// delete a node
static void _DeleteNode(ilist*, ilist*);

int main() {

    int i;
    ilist* list = NULL; 

    list = CreateList();					// list = {'\0'}

    for(i = 0; i < 3; i++) {
	InsertEntity(list, i, i+1);
	/*
	 * list = {1}
	 * list = {1, 2}
	 * list = {1, 2, 3}
	 */

    }

    for(i = 0; i < 3; i++) {
	printf("%d\n", GetEntity(list, 2));
    }
    //printf("%d\n", GetEntity(list, 2));			// 2
/*
    InsertToList(list, 4, 1);				// list = {1, 2, 3, '\0', 1}

    for(i = 0; i < GetNumberOfEntity(list); i++) {
	printf("%d, ", GetEntity(list, i));
	* 1
	 * 2
	 * 3
	 * '\0'
	 * 1
	 

    }

    DeleteEntity(list, 2);				// list = {1, 2, '\0', 1}
    */
    DeleteList(list);					// (list)

    return 0;

}

ilist* CreateList() {
    ilist* list = NULL;

    list = _AddNode(list, '\0', NULL);

    if(list == NULL) {
	puts("!!!cannot create a list!!!");
	exit(-1);

    }

    return list;

}

void InsertEntity(ilist* list, int index, int entity) {
    ilist* ins = NULL;

    ins = (ilist *)_AddNode(ins, entity, (list+index*sizeof(ilist))); 
    if(ins == NULL) {
	puts("!!! ERROR: cannot add an entity !!!");
	exit(-1);
    }

    printf("%p\n", (list+(index)*sizeof(ilist)));

}

void DeleteEntity(ilist* list, int index) {
    _DeleteNode((ilist* )(list+index), (ilist* )(list+index)->next);

}

int GetEntity(ilist* list, int index) {
    return (list+index*sizeof(ilist))->entity;

}

int GetNumberOfEntity(ilist* target) {
    int num = 0;
    ilist *list = NULL;

    list = target;

    for(;list != NULL;num++) {
	list = list->next;
    }

    free(list);

    return num;

}

void DeleteList(ilist* del) {
    int num, i, j;
    ilist* list = NULL;

    list = del;
    num = GetNumberOfEntity(del);

    for(i = 0; num - 1 > 0; i++) {
	for(j = 0; j < num; j++) {
	    list = list->next;
	}
	_DeleteNode(list, (ilist *)(list+(-1)*sizeof(ilist)));

    }

}

static struct _ilist* _AddNode(ilist* _add, int _entity, ilist* _next) {
    ilist* _list = NULL;

    _list = (ilist* )malloc(1*sizeof(struct _ilist));
    if(_list == NULL) {
	puts("!!! ERROR: cannot malloc !!!");
	exit(-1);

    }
    _list->next = _next;
    _list->entity = _entity;

    return _add = _list;
}

static void _DeleteNode(ilist* _del, ilist* _prev) {
    _prev->next = _del->next;

    free(_del);

}
