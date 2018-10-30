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

node_t *create0();
node_t *create1(int num);
void printNode(node_t *node);
void printNodesFrom(node_t *head);
node_t *insert(node_t *newNode, node_t *head);
void push(node_t *newNode, node_t *head);
node_t *pop(node_t *head);
node_t *reverseList(node_t *head);

#endif