#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data);
void printDFS(struct Node* node);


int main() {


//Tree representation:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("DFS: ");
    printDFS(root);
    printf("\n");

    return 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printDFS(struct Node* node) {
    if (node == NULL)
        return;

    printf("%d ", node->data);
    printDFS(node->left);
    printDFS(node->right);
}