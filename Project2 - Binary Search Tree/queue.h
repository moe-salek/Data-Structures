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

#ifndef MINIPROJECT2_QUEUE_H
#define MINIPROJECT2_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Queue {
    int capacity;
    int size;
    int front, rear;
    node_t *nodeArray;
} queue_t;

queue_t *createNewQueue(int capacity);
int enqueue(queue_t *queue, node_t *item);
node_t *dequeue(queue_t *queue);
void printQueue(queue_t *queue);

#endif //MINIPROJECT2_QUEUE_H