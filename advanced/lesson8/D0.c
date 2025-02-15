/*
 D0 отсортировать слова
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#ifdef Item_t
#undef Item_t
#endif

#define Item_t char*

typedef int32_t (*Compare_t)(Item_t, Item_t);

typedef struct ListNode *ListLink_t;

struct ListNode {
    Item_t Item;
    ListLink_t Next;
};

typedef struct {
    ListLink_t Head;
    ListLink_t Tail;
    uint32_t Count;
} List_t;


ListLink_t new_link(Item_t item, ListLink_t next) {
    ListLink_t link = (ListLink_t) malloc(sizeof(struct ListNode));
    link->Item = item;
    link->Next = next;
    return link;
}

List_t *list_init() {
    List_t *list = (List_t *) malloc(sizeof(List_t));
    list->Head = NULL;
    list->Tail = NULL;
    list->Count = 0;
    return list;
}

int8_t list_empty(List_t *list) {
    if (list != NULL) {
        return list->Head == NULL ? 1 : 0;
    }

    return -1;
}

void list_add(List_t *list, Item_t item) {
    if (list != NULL) {
        list->Count++;

        if (list->Head == NULL) {
            list->Head = (list->Tail = new_link(item, list->Head));
            return;
        }

        list->Tail->Next = new_link(item, list->Tail->Next);
        list->Tail = list->Tail->Next;
    }
}

Item_t list_get(List_t *list) {
    if (list != NULL) {
        if (list->Head != NULL) {
            Item_t item = list->Head->Item;
            ListLink_t link = list->Head->Next;
            free(list->Head);
            list->Head = link;
            list->Count--;
            return item;
        }
    }

    return NULL;
}

ListLink_t list_remove(List_t *list, ListLink_t link) {
    if (list != NULL) {
        ListLink_t t = link->Next;
        link->Next = t->Next;
        list->Count--;
        return t;
    }

    return NULL;
}

void list_insert(List_t *list, ListLink_t x, ListLink_t t) {
    if (list != NULL) {
        t->Next = x->Next;
        x->Next = t;
        list->Count++;
    }
}

void list_print(List_t *list) {
    if (list != NULL) {
        ListLink_t link = list->Head;
        while (link != NULL) {
            Item_t item = link->Item;
            link = link->Next;
            if (link != NULL)
                printf("%s ", item);
            else
                printf("%s", item);
        }
    }
}

void swap(ListLink_t a, ListLink_t b) {
    if (a != NULL && b != NULL) {
        Item_t temp = a->Item;
        a->Item = b->Item;
        b->Item = temp;
    }
}

void list_sort(List_t *list, Compare_t cmp) {
        if (list != NULL) {
            int swapp;
            ListLink_t currentLink;
            ListLink_t lastLink = NULL;
            ListLink_t head = list->Head;

            if (head == NULL)
                return;
            do {
                swapp = 0;
                currentLink = head;

                while (currentLink->Next != lastLink) {
                    if (cmp(currentLink->Item,  currentLink->Next->Item) > 0) {
                        swap(currentLink, currentLink->Next);
                        swapp = 1;
                    }
                    currentLink = currentLink->Next;
                }

                lastLink = currentLink;
            }
            while (swapp);
        }
}

void list_free(List_t *list) {
    if (list != NULL) {
        while (list_empty(list) == 0) {
            list_get(list);
            list->Count--;
        }
    }
}

int32_t compare(Item_t a, Item_t b) {
   return strcmp(a, b);
}

int32_t main(void) {
    const char *DELIMETER = " .\r\n";
    char *input_str = (char *)calloc(1002, sizeof(char));
    
    List_t *list = list_init();

    fgets(input_str, 1000, stdin);

    int finput_len = strlen(input_str);

    char *token = strtok(input_str, DELIMETER);
    int8_t calc_state = 0;

    while (token != NULL) {
        list_add(list, token);

        token = strtok(NULL, DELIMETER);
    }
    
    list_sort(list, compare);
    list_print(list);

    free(input_str);
    list_free(list);
    
    return 0;
}
