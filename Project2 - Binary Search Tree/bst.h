//
// Created by Salek.
//

#ifndef MINIPROJECT2_BST_H
#define MINIPROJECT2_BST_H

#include "tree.h"

node_t *createBST_preOrder(int *array, int size);
node_t *createBST_postOrder(int *array, int size);
node_t *searchInBST(node_t *root, int item);
node_t *searchParentInBST(node_t *root, int item);
void addToBST(node_t *root, int item);
void deleteFromBST(node_t *root, int item);
node_t *minSubtreeNode(node_t *node);

#endif //MINIPROJECT2_BST_H