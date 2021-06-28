#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main(){

    LIST *plist = listCreate();

    char *str = malloc(15);
    strcpy(str, "Test");
    listAdd(plist, str); /* add str pointer to list */

    char *str2 = malloc(15);
    strcpy(str2, "Test2");
    listAdd(plist, str2); /* add str pointer to list */

    char *str3 = malloc(15);
    strcpy(str3, "Test3");
    listAdd(plist, str3); /*add str pointer to list */

    char *str4 = malloc(15);
    strcpy(str4, "Test4");
    listAdd(plist, str4); /* add str pointer to list */

    char *str5 = malloc(15);
    strcpy(str5, "Test5");
    listAdd(plist, str5); /* add str pointer to list */

    printf("List size is: %d\n", listGetSize(plist)); /* print list size */
    printf("List is empty ? %d\n", listIsEmpty(plist)); /* use this to verify if list is empty*/

    ITERATOR it = plist->begin; /* print all itens */
    while(it != NULL){
        printf("%s\n", it->item);
        it = it->next_item;
    }

    if(listExistString(plist, "Test4", strlen("Test4"))){ /*verify if exist "Test4" */
        printf("Exist\n");
    }

    char *sortedStr = listReturnDrawnValue(plist); /*return a drawn value */
    printf("Drown value is: %s\n", sortedStr);
    free(sortedStr); /* required free after use. */

    listRemoveStr(plist, "Test3", strlen("Test3")); /* remove if value exist in list */

    printf("--------\n");

    printf("List size is: %d\n", listGetSize(plist)); /*list size */

    ITERATOR it2 = plist->begin; /* print all itens */
    while(it2 != NULL){
        printf("%s\n", it2->item);
        it2 = it2->next_item;
    }

    listDelete(plist); /* delete and free all itens in the list, and delete plist */

    system("pause");
}
