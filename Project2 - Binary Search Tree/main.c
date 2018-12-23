//
// Created by Salek.
//

#include "bst.h"

int main() {

    /* Array of Items: */
    int array[] = { 40, 20, 10, 30 , 50 };

    /* Choose order: */
    node_t *root = createBST_preOrder(array, 5); /* First Root */
    // node_t *root = createBST_postOrder(array, 5); /* Last Root */

    /*      40
    *      /  \
    *     20  50
    *    /  \
    *   10  30
    *       /
    *     (25)
    */

    /* Add Items: */
    addToBST(root, 25);

    /* Delete Items: */
    //deleteFromBST(root, 25); /* No Child */
    //deleteFromBST(root, 30); /* One Child */
    deleteFromBST(root, 20); /* Two Child */

    /* Search Items: */
    printf("\n<< Searched Item Info >>\n");
    printNode(searchInBST(root, 40));
    //printNode(searchParentInBST(root, 10));

    /* Traversals: */
    printf("<< Traversals >>\n");
    printf("%-13s" ,"PreOrder: ");
    printTree_preOrder(root);
    printf("\n");
    printf("%-13s" ,"InOrder: ");
    printTree_inOrder(root);
    printf("\n");
    printf("%-13s" ,"PostOrder: ");
    printTree_postOrder(root);
    printf("\n\n");

    /* Layers: */
    //("<< Layers >>\n");
    //printLayers(root, 5);
    //printf("\n");

    return 0;
}