/*
 D1 Вид сверху
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#ifdef Item_t
#undef Item_t
#endif

#define Item_t uint32_t

typedef struct StackNode *StackLink_t;

struct StackNode {
    Item_t Item;
    StackLink_t Next;
};

typedef struct {
    StackLink_t Head;
    uint32_t Count;
} Stack_t;

StackLink_t new_link(Item_t item, StackLink_t next) {
    StackLink_t link = (StackLink_t) malloc(sizeof(struct StackNode));
    link->Item = item;
    link->Next = next;
    return link;
}

Stack_t *stack_init() {
    Stack_t *stack = (Stack_t *) malloc(sizeof(Stack_t));
    stack->Head = NULL;
    stack->Count = 0;
    return stack;
}

int8_t stack_empty(Stack_t *stack) {
    if (stack != NULL) {
        return stack->Head == NULL ? 1 : 0;
    }

    return -1;
}

void stack_push(Stack_t *stack, Item_t item) {
    if (stack != NULL) {
        stack->Count++;

        stack->Head = new_link(item, stack->Head);
    }
}

Item_t stack_pop(Stack_t *stack) {
    if (stack != NULL) {
        if (stack->Head != NULL) {
            Item_t item = stack->Head->Item;
            StackLink_t link = stack->Head->Next;
            free(stack->Head);
            stack->Head = link;
            stack->Count--;
            return item;
        }
    }

    return 0;
}

void stack_free(Stack_t *stack) {
    if (stack != NULL) {
        while (stack_empty(stack) == 0) {
            stack_pop(stack);
            stack->Count--;
        }
    }
}

void btUpView(struct tree *root) {

    if (root == NULL)
        return;

    if (root->left != NULL) {
        Stack_t *stack = stack_init();
        struct tree * left = root->left;

        while (left != NULL) {
            stack_push(stack, left->key);
            left = left->left;
        }

        while (stack_empty(stack) != 1) {
            Item_t key = stack_pop(stack);
            printf("%d ", key);
        }
        stack_free(stack);
    }

    struct tree *right = root;
    while (right != NULL) {
        if (right->right != NULL)
            printf("%d ", right->key);
        else
            printf("%d", right->key);

        right = right->right;
    }
}
