//
// Created by Salek.
//

#include "stack.h"

stack_t *createNewStack(int capacity) {
    stack_t *stack;
    stack = malloc(sizeof(stack_t));
    stack->capacity = capacity;
    stack->size = 0;
    stack->nodeArray = (node_t *)malloc(capacity * sizeof(node_t));
    return stack;
}

void push(stack_t *stack, node_t *node) {
    if(stack->size < stack->capacity) {
        stack->nodeArray[stack->size++] = *node;
    } else {
        printf("Full Stack! (push)\n");
    }
}

node_t *pop(stack_t *stack) {
    if(stack->size == 0) {
        printf("Empty Stack! (pop)\n");
        return NULL;
    }
    return &stack->nodeArray[--stack->size];
}

void printStack(stack_t *stack) {
    if(stack == NULL) {
        printf("NULL stack! (printStack)\n");
        return;
    }
    printf("<< Stack Status >>\n");
    printf("Capacity: %d\n", stack->capacity);
    printf("Size: %d\n", stack->size);
    printf("Node Array: ");
    if(stack->size == 0)
        printf("[ ]");
    else {
        printf("[ ");
        for(int i = 0; i < stack->size; ++i) {
            if(i != stack->size - 1)
                printf("%d, ", stack->nodeArray[i].item);
            else
                printf("%d", stack->nodeArray[i].item);
        }
        printf(" ]\n");
    }
}