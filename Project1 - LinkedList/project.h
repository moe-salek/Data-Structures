//
// Created by Mohammad Salek.
//

#include "linkedlist.h"

#ifndef MINIPROJECT1
#define MINIPROJECT1

void initializeArr(int num);

void terminateArr();

void addMoreToArr();

void swap(node_t **head, node_t *node1, node_t *node2);

void shuffle (node_t **head);

void showArr();

void studentNameByScore(node_t *headNames, node_t *headScores, char *name);

void scoreByStudentName(node_t *headNames, node_t *headName, float score);

void sortByName(node_t **head);

void sortByScore(node_t **head);

#endif //MINIPROJECT1