//
// Created by Mohammad Salek
//

#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node node_t;
typedef struct data data_t;

node_t *createNode(int value) {
    node_t *currentNode = malloc(sizeof(node_t));
    currentNode->data.num = value;
    currentNode->next = NULL;
    return currentNode;
}

void showNode(node_t *node) {
    printf("<node(-)> ");
    printf("data:%5d , ", node->data);
    printf("adrs:%p , ", node);
    printf("next: %p", node->next);
    printf("\n");
}

void showNodesFrom(node_t *node) {
    node_t *current = node;
    int counter = 0;
    while (current != NULL) {
        printf("<node(%d)> ", ++counter);
        printf("data:%5d , ", current->data);
        printf("adrs:%p , ", current);
        printf("next:%p", current->next);
        printf("\n");
        current = current->next;


        if(counter > 100) break;
    }
}

node_t *insert(node_t *head, node_t *newNode) {
    if (newNode == NULL) {
        return NULL;
    }
    newNode->next = head;
    return newNode;
}

void push(node_t *head, node_t *newNode) {
    if (newNode == NULL || head == NULL) {
        return;
    }
    node_t *currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    newNode->next = NULL;
}

node_t *pop(node_t *head) {
    if (head == NULL) {
        return NULL;
    }
    node_t *popped = createNode(NULL);
    node_t *prevNode, *current;
    prevNode = current = head;
    while (current->next != NULL) {
        prevNode = current;
        current = current->next;
    }
    popped->data = current->data;
    prevNode->next = NULL;
    free(current);
    return popped;
}

node_t *reverseList(node_t *head) {
    if (head == NULL) {
        return NULL;
    }
    node_t *tmpNode1 = NULL;
    node_t *tmpNode2 = head;
    node_t *tmpNode3 = tmpNode2->next;
    tmpNode2->next = tmpNode1;
    while (tmpNode3 != NULL) {
        tmpNode1 = tmpNode2;
        tmpNode2 = tmpNode3;
        tmpNode3 = tmpNode2->next;
        tmpNode2->next = tmpNode1;
    }
    return tmpNode2;
}

//Warning: update head if swapping head with other nodes
void swapNodes(node_t *head, node_t *node1, node_t *node2) {
    if (head == NULL || node1 == NULL || node2 == NULL) {
        return;
    }
    node_t *current = head, *prevNode;
    node_t *prevNode1, *prevNode2;
    prevNode = prevNode1 = prevNode2  = NULL;
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
}

void sortByData(node_t *head) {
    //TODO
}
