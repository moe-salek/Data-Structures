//
// Created by Mohammad Salek.
//

#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct node node_t;

node_t *createNode(int data) {
    node_t *newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void showNode(node_t *node) {
    printf("<node(-)> ");
    printf("data:%d , ", node->data);
    printf("adrs:%p , ", node);
    printf("next:%p", node->next);
    printf("\n");
}

void showNodesFrom(node_t *node) {
    node_t *current = node;
    int counter = 0;
    while (current != NULL) {
        printf("<node(%d)> ", ++counter);
        printf("data:%d , ", current->data);
        printf("adrs:%p , ", current);
        printf("next:%p", current->next);
        printf("\n");
        current = current->next;
    }
}

void insert(node_t **head, node_t *newNode) {
    if (newNode == NULL)
        return;
    newNode->next = *head;
    *head = newNode;
}

void push(node_t *head, node_t *newNode) {
    if (newNode == NULL || head == NULL)
        return;
    node_t *currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    newNode->next = NULL;
}

int pop(node_t *head) {
    if (head == NULL)
        return -1;
    node_t *prevNode, *current;
    prevNode = current = head;
    while (current->next != NULL) {
        prevNode = current;
        current = current->next;
    }
    int value = current->data;
    free(current);
    prevNode->next = NULL;
    return value;
}

void reverseList(node_t **head) {
    if (head == NULL)
        return;
    node_t *tmpNode1 = NULL;
    node_t *tmpNode2 = *head;
    node_t *tmpNode3 = tmpNode2->next;
    tmpNode2->next = tmpNode1;
    while (tmpNode3 != NULL) {
        tmpNode1 = tmpNode2;
        tmpNode2 = tmpNode3;
        tmpNode3 = tmpNode2->next;
        tmpNode2->next = tmpNode1;
    }
    *head = tmpNode2;
}

void swapNodes(node_t **head, node_t *node1, node_t *node2) {
    if (*head == NULL || node1 == NULL || node2 == NULL || node1 == node2)
        return;
    node_t *newHead, *current = *head, *prevNode, *prevNode1, *prevNode2;
    prevNode = prevNode1 = prevNode2  = NULL;
    if (node1 == *head) {
        newHead = node2;
    } else if (node2 == *head) {
        newHead = node1;
    } else {
        newHead = *head;
    }
    while (current != NULL) {
        if (current == node1) {
            prevNode1 = prevNode;
        } else if (current == node2) {
            prevNode2 = prevNode;
        }
        prevNode = current;
        current = current->next;
    }
    node_t *tmp;
    if (prevNode1 == node2) {  //checks if node1 is before node2 or vice versa
        if (prevNode2 != NULL)
            prevNode2->next = node1;
        tmp = node1->next;
        node1->next = node2;
        node2->next = tmp;
    } else if (prevNode2 == node1) {
        if (prevNode1 != NULL)
            prevNode1->next = node2;
        tmp = node2->next;
        node2->next = node1;
        node1->next = tmp;
    } else {
        if (prevNode1 != NULL)
            prevNode1->next = node2;
        if (prevNode2 != NULL)
            prevNode2->next = node1;
        tmp = node2->next;
        node2->next = node1->next;
        node1->next = tmp;
    }
    *head = newHead;
}

void sortByData(node_t **head) {
    if (*head == NULL)
        return;
    int size = sizeOfList(*head);
    node_t *current, *prevNode, *newHead = *head;
    while (size) {
        current = prevNode = newHead;
        while (current != NULL) {
            if (prevNode->data > current->data) {
                swapNodes(&newHead, prevNode, current);
            }
            prevNode = current;
            current = current->next;
        }
        --size;
    }
    *head = newHead;
}

int sizeOfList(node_t *head) {
    int counter = 0;
    node_t *current = head;
    if (current != NULL) {
        ++counter;
        while (current->next != NULL) {
            ++counter;
            current = current->next;
        }
    }
    return counter;
}

void addNodeAfter(node_t *prevNode, node_t *newNode) {
    if (prevNode == NULL && newNode == NULL)
        return;
    node_t *afterNode = prevNode->next;
    prevNode->next = newNode;
    newNode->next = afterNode;
}

void addNodeBefore(node_t **head, node_t *afterNode, node_t *newNode) {
    if (afterNode == *head)
        insert(head, newNode);
    node_t *current = *head;
    while (current != NULL) {
        if (current->next == afterNode)
            break;
        current = current->next;
    }
    if (current != NULL) {
        current->next = newNode;
        newNode->next = afterNode;
    }
}

void removeNode(node_t **head, node_t *selected) {
    if (*head == NULL || selected == NULL)
        return;
    if (*head == selected) {
        node_t *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    } else {
        node_t *prev, *current = *head;
        while (current != NULL && current != selected) {
            prev = current;
            current = current->next;
        }
        if (current != NULL)
            prev->next = current->next;
        else
            prev->next = NULL;
        free(current);
    }
}

void removeNodeByData(node_t **head, int data) {
    if (*head == NULL || data == NULL)
        return;
    if ((*head)->data == data) {
        node_t *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    } else {
        node_t *prev, *current = *head;
        while (current != NULL && current->data != data) {
            prev = current;
            current = current->next;
        }
        if (current != NULL)
            prev->next = current->next;
        else
            prev->next = NULL;
        free(current);
    }
}

node_t *nodeByIndex(node_t *head, int index) {
    if (head == NULL)
        return NULL;
    node_t *current = head;
    while (current != NULL && index) {
        current = current->next;
        --index;
    }
    return current;
}

void shuffle (node_t **head) {
    if (*head == NULL)
        return;
    srand((unsigned int) time(NULL));
    int size = sizeOfList(*head), counter, r1, r2;
    counter = size;
    while (counter) {
        r1 = rand() % size;
        r2 = rand() % size;
        swapNodes(head, nodeByIndex(*head, r1), nodeByIndex(*head, r2));
        --counter;
    }
}
