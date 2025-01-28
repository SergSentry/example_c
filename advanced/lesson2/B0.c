/*
 B0 Максимальный блок
*/

#include <stdio.h>
#include <inttypes.h>
#include <malloc.h>
#include <string.h>

typedef struct List {
    void *address;
    size_t size;
    char comment[64];
    struct List *next;
} List_t;

List_t *new_link(List_t *next, size_t size, char *comment) {
    List_t *link = (List_t *) malloc(sizeof(struct List));
    link->size = size;
    link->address = link;
    size_t len = strlen(comment);
    memcpy(link->comment, comment, len > 64 ? 63 : len);
    link->next = next;
    return link;
}

List_t *list_init() {
    List_t *list = (List_t *) malloc(sizeof(List_t));
    list->address = NULL;
    list->next = NULL;
    list->size = 0;
    return list;
}

void list_add(List_t *list, size_t size, char *comment) {
    if (list != NULL) {
        List_t *link = list;
        while (link->next != NULL)
            link = link->next;

        if (link->next == NULL) {
            link->next = new_link(link->next, size, comment);
            return;
        }
    }
}

void *findMaxBlock(List_t *list) {
    if (list != NULL) {
        List_t *max = list;
        List_t *link = list;
        while (link != NULL) {
            if (link->size > max->size)
                max = link;
            link = link->next;
        }
        return max->address;
    }

    return NULL;
}

void list_free(List_t *list) {
    if (list != NULL) {
        List_t *link = list;
        while (link != NULL) {
            List_t *tmp = link->next;
            free(link);
            link = tmp;
        }
    }
}

int32_t main(void) {
    List_t *list;
    list = list_init();

    list_add(list, 1, "pinapple");
    list_add(list, 20, "banana");
    list_add(list, 10, "apple");

    void *address = findMaxBlock(list);
    if (address != NULL)
        printf("%p", address);
    else
        printf("NULL");

    list_free(list);

    return 0;
}
