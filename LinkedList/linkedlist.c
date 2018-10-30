//
// Created by Mohammad Salek
//

#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node node_t;
typedef struct data data_t;

node_t *create0() {
    node_t *currentNode = NULL;
    currentNode = malloc(sizeof(node_t));
    return currentNode;
}

node_t *create1(int num) {
    node_t *currentNode = NULL;
    currentNode = malloc(sizeof(node_t));
    currentNode->data.num = num;
    return currentNode;
}

void printNode(node_t *node) {
    printf("+ ");
    printf("data: %d", node->data);
    printf(", ");
    printf("next: %p", node->next);
    printf("\n");
}

void printNodesFrom(node_t *node) {
    node_t *current = node;
    int counter = 0;
    while (current != NULL) {
        printf("(%d) ", ++counter);
        printf("data: %d", current->data);
        printf(", ");
        printf("next: %p", current->next);
        printf("\n");
        current = current->next;
    }
}

node_t *insert(node_t *newNode, node_t *head) {
    if (newNode == NULL) {
        return NULL;
    }
    newNode->next = head;
    return newNode;
}

void push(node_t *newNode, node_t *head) {
    if (newNode == NULL && head == NULL) {
        return ;
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
    head->next = NULL;
    return head;
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