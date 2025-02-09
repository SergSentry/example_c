/*
C2 Польская запись
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef enum {
    NOP = 0,
    ADD,
    SUB,
    MUL,
    DIV,
} Operation_t;

#ifndef Item_t
#define Item_t int32_t
#endif

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

int32_t get_number(const char *number) {
    if (strlen(number) != 0) {
        return atoi(number);
    }

    return 0;
}

Operation_t get_operation(const char *operation) {
    if (strlen(operation) == 1) {
        switch (operation[0])
        {
            case '+': return ADD;
            case '-': return SUB;
            case '*': return MUL;
            case '/': return DIV;
            default: return NOP;
        }
    }

    return NOP;
}

uint8_t is_operation(const char *operation) {
    if (strlen(operation) == 1) {
        return operation[0] == '+'
        || operation[0] == '-'
        || operation[0] == '*'
        || operation[0] == '/' ? 1 : 0;

    }

    return 0;
}

uint8_t operation_handler(const char* token, Stack_t *stack) {
        if (is_operation(token)) {
            Operation_t operation = get_operation(token);
            int32_t operand_left = 0;
            int32_t operand_right = 0;
            int32_t result = 0;
            
            switch (operation) {
            case ADD:
                operand_right = stack_pop(stack);
                operand_left = stack_pop(stack);
                result = operand_left + operand_right;
                stack_push(stack, result);
                break;
            case SUB:
                operand_right = stack_pop(stack);
                operand_left = stack_pop(stack);
                result = operand_left - operand_right;
                stack_push(stack, result);
                break;
            case MUL:
                operand_right = stack_pop(stack);
                operand_left = stack_pop(stack);
                result = operand_left * operand_right;
                stack_push(stack, result);
                break;
            case DIV:
                operand_right = stack_pop(stack);
                operand_left = stack_pop(stack);
                if (operand_right != 0) {
                    result = operand_left / operand_right;
                    stack_push(stack, result);
                }
                else 
                    return -1;
                break;
            default:
                break;
            }

        } else {
            int32_t number = get_number(token);
            stack_push(stack, number);
        }
    return 0;
}

int32_t main(void) {
    const char *DELIMETER = " .\r\n";
    char *input_str = (char *)calloc(1002, sizeof(char));
    
    Stack_t *stack = stack_init();

    fgets(input_str, 1000, stdin);

    int finput_len = strlen(input_str);

    char *token = strtok(input_str, DELIMETER);
    int8_t calc_state = 0;

    while (token != NULL) {
        calc_state = operation_handler(token, stack);
        if (calc_state != 0) {
            break;
        }

        token = strtok(NULL, DELIMETER);
    }
    
    if (calc_state == 0) {
        int32_t result = stack_pop(stack);
        printf("%d", result);
    }
    else {
        printf("Calculation error.");
    }


    free(input_str);
    stack_free(stack);
    
    return 0;
}
