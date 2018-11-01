#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    node_t *head;

    //create nodes:
    node_t *node1 = createNode(100);
    node_t *node2 = createNode(200);
    node_t *node3 = createNode(300);
    node_t *node4 = createNode(400);
    node_t *node5 = createNode(500);

    //link them together:
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    //push to list:
//    push(head, createNode(2));

//    pop from list:
//    node_t *popped = pop(head);

    //insert to bottom of the list:
//    node_t *newNode1 = createNode(1);
//    head = insert(head, newNode1);

    //swap two nodes in the list:
//    swapNodes(head, node4, node2);

    //reverse list:
//    head = reverseList(head);

    //print the list:
    showNodesFrom(head);

    return 0;
}
