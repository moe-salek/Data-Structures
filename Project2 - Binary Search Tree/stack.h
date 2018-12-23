//
// Created by Salek.
//

#ifndef NODE_VAR
#define NODE_VAR

typedef struct Node {
    int item;
    struct Node *left;
    struct Node *right;
} node_t;

#endif //NODE_VAR

#ifndef MINIPROJECT2_STACK_H
#define MINIPROJECT2_STACK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
    int capacity;
    int size;
    node_t *nodeArray;
} stack_t;

stack_t *createNewStack(int capacity);
node_t *pop(stack_t *stack);
void push(stack_t *stack, node_t *node);
void printStack(stack_t *stack);

#endif //MINIPROJECT2_STACK_H