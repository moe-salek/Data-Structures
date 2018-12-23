//
// Created by Salek.
//

#include "bst.h"

node_t *createBST_preOrder(int *array, int size) {
    if (array == NULL) {
        printf("Empty Number Array!\n");
        return NULL;
    }
    node_t *root = createNode(array[0]);
    for (int i = 1; i < size; ++i) {
        addToBST(root, array[i]);
    }
    return root;
}

node_t *createBST_postOrder(int *array, int size) {
    if (array == NULL) {
        printf("Empty Number Array!\n");
        return NULL;
    }
    node_t *root = createNode(array[size - 1]);
    for (int i = size - 2; i >= 0; --i) {
        addToBST(root, array[i]);
    }
    return root;
}

node_t *searchInBST(node_t *root, int item) {
    if (root == NULL)
        return NULL;
    if (root->item == item) {
        return root;
    }
    node_t *node = root;
    while (node->item != item) {
        if (node->left == NULL && node->right == NULL) {
            printf("Item Not in BST!\n");
            return NULL;
        }
        if (item < node->item) {
            if (node->left == NULL){
                printf("Item Not in BST!\n");
                return NULL;
            } else
                node = node->left;
        } else if (item > node->item) {
            if (node->right == NULL){
                printf("Item Not in BST!\n");
                return NULL;
            } else
                node = node->right;
        }
    }
    return node;
}

node_t *searchParentInBST(node_t *root, int item) {
    if (root == NULL)
        return NULL;
    if (root->item == item)
        return NULL;
    if (root->left == NULL && root->right == NULL)
        return NULL;

    node_t *node = root;
    while ((node->left != NULL && node->left->item != item) &&
           (node->right != NULL && node->right->item != item)) {
        if (item < node->item) {
            if (node->left == NULL){
                printf("Parent Not in BST!\n");
                return NULL;
            } else
                node = node->left;
        } else if (item > node->item) {
            if (node->right == NULL){
                printf("Parent Not in BST!\n");
                return NULL;
            } else
                node = node->right;
        }
    }
    if (node->left == NULL && node->right == NULL) {
        printf("Parent Not in BST!\n");
        return NULL;
    }
    return node;
}

void addToBST(node_t *root, int item) {
    if (item < root->item) {
        if (root->left == NULL)
            root->left = createNode(item);
        else
            addToBST(root->left, item);
    } else if (item > root->item) {
        if (root->right == NULL)
            root->right = createNode(item);
        else
            addToBST(root->right, item);
    } else {
        printf("Item already exists in BST!");
    }
}

void deleteFromBST(node_t *root, int item) {
    node_t *parent = searchParentInBST(root, item);
    node_t *node = searchInBST(root, item);
    if (node->left == NULL && node->right == NULL) {
        if (parent->right == node) {
            parent->right = NULL;
        } else if (parent->left == node) {
            parent->left = NULL;
        }
        free(node);
    } else if (node->left == NULL) {
        if (parent->right == node) {
            parent->right = node->right;
        } else if (parent->left == node) {
            parent->left = node->right;
        }
    } else if (node->right == NULL) {
        if (parent->right == node) {
            parent->right = node->left;
        } else if (parent->left == node) {
            parent->left = node->left;
        }
        free(node);
    } else {
        int tmp = minSubtreeNode(node->right)->item;
        deleteFromBST(root, tmp);
        node->item = tmp;
    }
}

node_t *minSubtreeNode(node_t *node) {
    if (node == NULL)
        return NULL;
    node_t *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}