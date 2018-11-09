#include "linkedlist.h"

int main() {

/* nodes sample1: */
    node_t *node1 = createNode(100);
    node_t *node2 = createNode(200);
    node_t *node3 = createNode(300);
    node_t *node4 = createNode(400);
    node_t *node5 = createNode(500);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

/* nodes sample2: */
//    srand((unsigned int) time(NULL));
//    node_t *array[1000];
//    for (int i = 0; i < 1000; ++i) {
//        array[i] = createNode(rand() % 1000 + 1000);
//    }
//    for (int i = 1; i < 1000; ++i) {
//        array[i-1]->next = array[i];
//    }

/* head of the list: */
    node_t *head;
    head = node1;  /* link head to sample1*/
//    head = array[0]; /* or link head to sample2*/

/* functions usage: */

//    push(head, createNode(2));

//    int popped = pop(head);

//    insert(&head, createNode(987));

//    swapNodes(&head, node2, node3);

//    addNodeAfter(node2, createNode(900));

//    addNodeBefore(&head, node3, createNode(842));

//    removeNode(&head, node3);

//    removeNodeByData(&head, 200);

//    printf("%d", sizeOfList(head));

//    reverseList(&head);

//    sortByData(&head);

//    showNode(nodeByIndex(head, 0));

//    shuffle(&head);

    showNodesFrom(head);

    return 0;
}
