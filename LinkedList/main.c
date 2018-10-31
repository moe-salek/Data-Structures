#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    node_t *head;

    //create nodes:
    node_t *node1 = create1(100);
    node_t *node2 = create1(200);
    node_t *node3 = create1(300);
    node_t *node4 = create1(400);
    node_t *node5 = create1(500);

    //link them together:
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    //reverse list:
//    head = reverseList(head);

    //insert to top of the list:
//    node_t *newNode1 = create1(1);
//    head = insert(head, newNode1);

    //push to bottom of the list:
//    node_t *newNode2 = create1(2);
//    push(head, newNode2);

    //pop from the top of the list:
//    node_t *newHead = head->next;
//    node_t *poppedVar = pop(head);
//    head = newHead;

    //swap two nodes in the list:
//    swapNodes(head, node4, node2);

    //print the list:
    printNodesFrom(head);

    return 0;
}