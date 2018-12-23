//
// Created by Salek.
//

#include "bst.h"

int main() {

    /* Arrays of Items: */
    int array[] = { 40, 20, 10, 30 , 50 }; // For BST Construction
    int array2[] = {1, 2, 3, 4, 5, 6}; // For Tree Construction

    /* Construct Tree: */
    node_t *root2 = createLevelTree(array2, 6);

    /*
    *       1
    *      /  \
    *     2    3
    *    / \  /
    *   4   5 6
    *
    */

    /* Construct BST: */
    node_t *root = createBST_preOrder(array, 5); /* First Item is Root */
    // node_t *root = createBST_postOrder(array, 5); /* Last Item is Root */

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
    printf("<< Layers >>\n");
    printf("<root>\n");
    printLayers(root, 5);
    printf("\n");
    printf("<root2>\n");
    printLayers(root2, 6);
    printf("\n");

    /* Check BST: */
    printf("<< Check BST >>\n");
    printf("\"root\"");
    if (isBST(root)) {
        printf(" IS BST!");
    } else {
        printf(" is NOT BST!");
    }
    printf("\n");
    printf("\"root2\"");
    if (isBST(root2)) {
        printf(" IS BST!");
    } else {
        printf(" is NOT BST!");
    }
    printf("\n\n");

    return 0;
}