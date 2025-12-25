#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    struct node* LC;
    struct node* RC;
} Node, *BST;

void insert(BST *tree, const char *key_data) {
    BST *trav = tree;

    while (*trav != NULL) {
        if (strcmp((*trav)->key, key_data) == 0) {
            printf("Key \"%s\" already exists. Ignoring.\n", key_data);
            return;
        }

        if (strcmp(key_data, (*trav)->key) > 0) {
            trav = &((*trav)->RC);
        } else {
            trav = &((*trav)->LC);
        }
    }

    *trav = (BST) calloc(1, sizeof(Node));
    (*trav)->key = malloc(strlen(key_data) + 1);
    strcpy((*trav)->key, key_data);

    printf("Inserted key: \"%s\" \n", key_data);
}

void inorderTraversal(BST tree) {
    if (tree != NULL) {
        inorderTraversal(tree->LC);
        printf("\"%s\" ", tree->key);
        inorderTraversal(tree->RC);
    }
}

void preorderTraversal(BST tree) {
    if (tree != NULL) {
        printf("\"%s\" ", tree->key);
        preorderTraversal(tree->LC);
        preorderTraversal(tree->RC);
    }
}

void postorderTraversal(BST tree) {
    if (tree != NULL) {
        postorderTraversal(tree->LC);
        postorderTraversal(tree->RC);
        printf("\"%s\" ", tree->key);
    }
}

void destroyTree(BST tree) {
    if (tree != NULL) {
        destroyTree(tree->LC);
        destroyTree(tree->RC);
        free(tree->key);
        free(tree);
    }
}

int main() {
    BST myTree = NULL;

    insert(&myTree, "Mango");
    insert(&myTree, "Apple");
    insert(&myTree, "Pineapple");
    insert(&myTree, "Banana");
    insert(&myTree, "Grape");
    insert(&myTree, "Orange");
    insert(&myTree, "Kiwi");
    insert(&myTree, "Mango");

    printf("\nInorder:\n");
    inorderTraversal(myTree);

    printf("\n\nPreorder:\n");
    preorderTraversal(myTree);

    printf("\n\nPostorder:\n");
    postorderTraversal(myTree);

    printf("\n\n");

    destroyTree(myTree);

    return 0;
}
