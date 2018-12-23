//
// Created by Salek.
//

#include "queue.h"

queue_t *createNewQueue(int capacity) {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = -1;
    queue->rear = -1;
    queue->nodeArray = (node_t **)malloc(capacity * sizeof(node_t *));
}

int enqueue(queue_t *queue, node_t *item) {
    if (queue == NULL) {
        printf("NULL Queue! (enqueue)\n");
        return -1;
    }
    if (queue->size == queue->capacity) {
        printf("Full Queue! (enqueue)\n");
        return -1;
    }
    queue->nodeArray[++queue->rear] = item;
    if (queue->front < 0)
        queue->front = 0;
    queue->size++;
    return 0;
}

node_t *dequeue(queue_t *queue) {
    if (queue == NULL) {
        printf("NULL Queue! (dequeue)\n");
        return NULL;
    }
    if (queue->size == 0) {
        printf("Empty Queue! (dequeue)\n");
        return NULL;
    }
    queue->size--;
    return queue->nodeArray[queue->front++];
}

void printQueue(queue_t *queue) {
    if (queue == NULL) {
        printf("NULL Queue! (printQueue)\n");
        return;
    }
    printf("<< Queue Status >>\n");
    printf("Capacity: %d\n", queue->capacity);
    printf("Size: %d\n", queue->size);
    printf("Node Array: ");
    if (queue->size == 0)
        printf("[ ]");
    else {
        printf("[ ");
        for (int i = queue->front; i <= queue->rear; ++i) {
            if (i != queue->rear)
                printf("%d, ", queue->nodeArray[i]->item);
            else
                printf("%d", queue->nodeArray[i]->item);
        }
        printf(" ]\n");
    }
}
