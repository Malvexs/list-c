#ifndef LIST2_H_INCLUDED
#define LIST2_H_INCLUDED

#include <windows.h>

struct node{
    void *item;
    struct node *next_item;
};

struct list{
    struct node *begin;
};

typedef struct list LIST;
typedef struct node* ITERATOR;

struct list *listCreate();
void listAdd(struct list *plist, void *value);
void listRemove(struct list *plist, void *value);
BOOL listExistString(LIST *plist, void *value, int length);
void listRemoveStr(struct list *plist, void *value, int strLength);
BOOL listIsEmpty(LIST *plist);
void listDelete(LIST *plist);
int listGetSize(LIST *plist);
void *listReturnSortedValue(LIST *plist);

#endif // LIST_H_INCLUDED
