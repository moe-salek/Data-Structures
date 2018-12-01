//
// Created by Mohammad Salek.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    float data;
    char *dataStr;
    struct node *next;
} node_t;

/* create a node with given data: */
node_t *createNode(char *dataStr, float data);

/* print a node by the given address: */
void showNode(node_t *node);

/* print nodes from specific starting node: (head for entire list) */
void showNodesFrom(node_t *head);

/* insert to bottom of the list (before head): */
void insertNode(node_t **head, node_t *newNode);

/* push to list: */
void pushNode(node_t *head, node_t *newNode);

/* pop from list: */
float popNode(node_t *head);

char *popStrNode(node_t *head);

/* reverse list: */
void reverseList(node_t **head);

/* swap two nodes in the list: */
void swapNodes(node_t **head, node_t *node1, node_t *node2);

/* sort list: */
void sortByData(node_t **head);

void sortByDataStr(node_t **head);

/* size of list: */
int sizeOfList(node_t *head);

/* add after a node: */
void addNodeAfter(node_t *prevNode, node_t *newNode);

/* add before a node: */
void addNodeBefore(node_t **head, node_t *afterNode, node_t *newNode);

/* remove a node by address: */
void removeNode(node_t **head, node_t *selected);

/* remove a node by its data: */
void removeNodeByData(node_t **head, int data);

/* remove a node by its dataStr: */
void removeNodeByDataStr(node_t **head, char *dataStr);

/* get pointer to a node by its index starting from head (index = 0): */
node_t *nodeByIndex(node_t *head, int index);

/* get index (starting from head) of a node by its pointer: */
int indexByNode(node_t *head, node_t *node1);

/* get index of a node by its dataStr: */
int indexByDataStr(node_t *head, char *dataStr);

/* shuffle the list: */
void shuffleNodes (node_t **head);

/* free the memory: */
void terminateNodes(node_t *head);

int indexByData(node_t *head, float data);

#endif