//
// Created by Mohammad Salek.
//

#include <stdlib.h>
#include <stdio.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct data {
    int num;
} data_t;

typedef struct node {
    data_t data;
    struct node *next;
} node_t;

data_t *createData(size_t value);

node_t *createNode(size_t value);

void showNode(node_t *node);

void showNodesFrom(node_t *head);

void insert(node_t **head, node_t *newNode);

void push(node_t *head, node_t *newNode);

int pop(node_t *head);

void reverseList(node_t **head);

void swapNodes(node_t **head, node_t *node1, node_t *node2);

void sortByDataNum(node_t **head);

int sizeOfList(node_t *head);

void addNodeAfter(node_t *prevNode, node_t *newNode);

void addNodeBefore(node_t **head, node_t *afterNode, node_t *newNode);

void removeNode(node_t **head, node_t *selected);

void removeNodeByData(node_t **head, data_t *theData);

#endif
