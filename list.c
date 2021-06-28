#include "list2.h"

struct list *listCreate(){

    LIST *vlist = (struct list *) malloc(sizeof(struct list));

	if (!vlist)
		return NULL;

    vlist->begin = NULL;

    return vlist;
};

void listAdd(struct list *plist, void *value){

    struct node *pnode = (struct node *)malloc(sizeof(struct node));
	struct node *current = NULL;
    pnode->item = value;
    pnode->next_item = NULL;

    if(plist->begin == NULL){
        plist->begin = pnode;
        plist->begin->next_item = NULL;
    }else{
        current = plist->begin;
        plist->begin = pnode;
        pnode->next_item = current;
    }
}

void listRemove(struct list *plist, void *value) {
	struct node *prev = NULL, *current= NULL;
	current = plist->begin;
	prev = current;

	while (current != NULL) {
		if (current->item == value) {
			prev->next_item = current->next_item;
			if (current == plist->begin)
				plist->begin = current->next_item;
			free(current);
			return;
		}
		prev = current;
		current = current->next_item;
	}
}

void listRemoveStr(struct list *plist, void *value, int strLength) {
	struct node *prev = NULL, *current = NULL;
	current = plist->begin;
	prev = current;

	while (current != NULL) {
		if (memcmp(current->item, value, strLength) == 0) {
			prev->next_item = current->next_item;
			if (current == plist->begin)
				plist->begin = current->next_item;
			free(current);
			return;
		}
		prev = current;
		current = current->next_item;
	}
}

BOOL listExistString(LIST *plist, void *value, int length) {

	ITERATOR it = plist->begin;

	while (it != NULL) {
		if (memcmp(it->item, value, length) == 0) {
			return TRUE;
		}
		it = it->next_item;
	}

	return FALSE;
}

BOOL listIsEmpty(LIST *plist){

    if(plist->begin == NULL)
        return TRUE;
    return FALSE;
}

int listGetSize(LIST *plist) {

	int count = 0;

	ITERATOR it = plist->begin;
	while (it != NULL) {
		it = it->next_item;
		count++;
	}
	return count;
}

void *listReturnSortedValue(LIST *plist) {
	
	int listSize = listGetSize(plist);
	if (listSize == 0)
		return NULL;
	struct node *pvalue;
	srand(time(NULL));
	int random = rand() % listSize;
	random++;

	if (random <= listSize) {
		ITERATOR it = plist->begin;
		for (int x = 1; x < random; x++)
			it = it->next_item;
		pvalue = it->item;
		listRemove(plist, it->item);
		return pvalue;
	}
	return NULL;
}

void listDelete(LIST *plist){

	ITERATOR it = plist->begin, fn;

    while(it != NULL){
        fn = it->next_item;
		free(it->item);
		free(it);
        it = fn;
    }
    free(plist);
}

