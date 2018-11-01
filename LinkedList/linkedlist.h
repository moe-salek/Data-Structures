//
// Created by Mohammad Salek
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct data {
    int num;
} data_t;

typedef struct node {
    data_t data;
    struct node *next;
} node_t;

node_t *createNode(int value);

void showNode(node_t *node);

void showNodesFrom(node_t *head);

node_t *insert(node_t *head, node_t *newNode);

void push(node_t *head, node_t *newNode);

node_t *pop(node_t *head);

node_t *reverseList(node_t *head);

void swapNodes(node_t *head, node_t *node1, node_t *node2);

void sortByData(node_t *head);

#endif
