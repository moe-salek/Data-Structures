//
// Created by Mohammad Salek.
//

#include "project.h"

int main() {

    int studentNum = 4;
    char *names[] = {
            "Mohammad",
            "Farhad",
            "Alireza",
            "Hamid"
    };
    float scores[] = {
            19.5,
            15.65,
            17.20,
            9.5
    };

    // create arrays of node_ts for both names and scores:
    node_t *nameNodes[studentNum], *scoreNodes[studentNum];
    for (int i = 0; i < studentNum; ++i) {
        nameNodes[i] = createNode(names[i], -1);
    }
    for (int i = 0; i < studentNum; ++i) {
        scoreNodes[i] = createNode(NULL, scores[i]);
    }

    // link the nodes:
    for (int i = 0; i < studentNum - 1; ++i) {
        nameNodes[i]->next = nameNodes[i + 1];
    }
    nameNodes[studentNum - 1]->next = NULL;
    for (int i = 0; i < studentNum - 1; ++i) {
        scoreNodes[i]->next = scoreNodes[i + 1];
    }
    scoreNodes[studentNum - 1]->next = NULL;

    // create heads:
    node_t *headNames = nameNodes[0];
    node_t *headScores = scoreNodes[0];

    // init the structure Array:
    initializeArr(studentNum);
    for (int i = 0; i < studentNum; ++i) {
        addMoreToArr();
    }

    // do stuff to nodes:
//    sortByName(&headNames);
//    sortByScore(&headScores);
//    shuffle(&headNames);
//    shuffle(&headScores);

    // show nodes and array:
//    showNodesFrom(headNames);
//    showNodesFrom(headScores);
//    showArr();

    // search for student or score:
    scoreByStudentName(headNames, headScores, 9.5);
    studentNameByScore(headNames, headScores, "Mohammad");

    // termination:
    terminateNodes(headNames);
    terminateNodes(headScores);
    terminateArr();

    return 0;
}