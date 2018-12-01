//
// Created by Mohammad Salek.
//

#include "project.h"

int **array;
static int arraySize, lastFilledIndex;

void initializeArr(int num) {
    arraySize = num;
    array = malloc(arraySize * sizeof(int *));
    for (int i = 0; i < arraySize; ++i) {
        array[i] = malloc(arraySize * sizeof(int) );
        memset(array[i], 0, arraySize * sizeof(int));
    }
}

//TODO: TEST
void increaseArr(int **array, int lastFilledIndex) {
    arraySize *= 2;
    array = realloc(array, (arraySize * sizeof(int)));
    for (int i = 0; i < arraySize; ++i) {
        array[i] = realloc(array[i], (arraySize * sizeof(int)));
        if (i >= lastFilledIndex) {
            memset(array[i], 0, arraySize * sizeof(int));
        }
    }
}

void terminateArr() {
    free(array);
}

void addMoreToArr() {
    if (lastFilledIndex > arraySize - 1) {
        increaseArr(array, lastFilledIndex);
    }
    array[lastFilledIndex][lastFilledIndex] = 1;
    ++lastFilledIndex;
}

void showArr() {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; ++j) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void swap(node_t **head, node_t *node1, node_t *node2) {
    //TODO: fix possible errors
    int isN1Score = (node1->data != -1);
    int indx1 = indexByNode(*head, node1);
    int indx2 = indexByNode(*head, node2);
    if (!isN1Score) {
        for (int i = 0; i < arraySize; ++i) {
            int tmp = array[indx1][i];
            array[indx1][i] = array[indx2][i];
            array[indx2][i] = tmp;
        }
    } else {
        for (int i = 0; i < arraySize; ++i) {
            int tmp = array[i][indx1];
            array[i][indx1] = array[i][indx2];
            array[i][indx2] = tmp;
        }
    }
    swapNodes(head, node1, node2);
}

void shuffle (node_t **head) {
    if (*head == NULL)
        return;
    srand((unsigned int) time(NULL));
    int size = sizeOfList(*head), counter, r1, r2;
    counter = size;
    while (counter) {
        r1 = rand() % size;
        r2 = rand() % size;
        swap(head, nodeByIndex(*head, r1), nodeByIndex(*head, r2));
        --counter;
    }
}

void studentNameByScore(node_t *headNames, node_t *headScores, char *name) {
    node_t *target = NULL;
    int indx = indexByDataStr(headNames, name);
    if (indx == -1) {
        printf("Not Found.\n");
        return;
    }
    for (int i = 0; i < arraySize; ++i) {
        if (array[indx][i] == 1)
            target = nodeByIndex(headScores ,i);
    }
    if (target != NULL)
        printf("Student: %-10s, Score: %-5.2f\n", name, target->data);
    else
        printf("Not Found.\n");
}

void scoreByStudentName (node_t *headNames, node_t *headScores, float score) {
    node_t *target = NULL;
    int indx = indexByData(headScores, score);
    if (indx == -1) {
        printf("Not Found.\n");
        return;
    }
    for (int i = 0; i < arraySize; ++i) {
        if (array[i][indx] == 1)
            target = nodeByIndex(headNames ,i);
    }
    if (target != NULL)
        printf("Student: %-10s, Score: %-5.2f\n", target->dataStr, score);
    else
        printf("Not Found.\n");
}

void sortByName(node_t **head) {
    if (*head == NULL)
        return;
    int size = sizeOfList(*head);
    node_t *current, *prevNode, *newHead = *head;
    while (size) {
        current = prevNode = newHead;
        while (current != NULL) {
            if (strcmp(prevNode->dataStr, current->dataStr) > 0) {
                swap(&newHead, prevNode, current);
            }
            prevNode = current;
            current = current->next;
        }
        --size;
    }
    *head = newHead;
}

void sortByScore(node_t **head) {
    if (*head == NULL)
        return;
    int size = sizeOfList(*head);
    node_t *current, *prevNode, *newHead = *head;
    while (size) {
        current = prevNode = newHead;
        while (current != NULL) {
            if (prevNode->data > current->data) {
                swap(&newHead, prevNode, current);
            }
            prevNode = current;
            current = current->next;
        }
        --size;
    }
    *head = newHead;
}