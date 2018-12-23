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

#ifndef MINIPROJECT2_TREE_H
#define MINIPROJECT2_TREE_H

#include "queue.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

node_t *createNode(int item);
int addNode(node_t *root, node_t *newNode, char side);
int findHeight(node_t *root);
int printNode(node_t *node);
int printItem(node_t *root);
void printTree_preOrder(node_t *root);
void printTree_inOrder(node_t *root);
void printTree_postOrder(node_t *root);
void printLayers(node_t *root, int size);

#endif //MINIPROJECT2_TREE_H