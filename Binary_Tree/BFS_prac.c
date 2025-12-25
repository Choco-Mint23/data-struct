#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data);
int height(struct Node* node);
void printCurrentLevel(struct Node* root, int level);
void printBFS(struct Node* root);


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

    printf("BFS: ");
    printBFS(root);
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

int height(struct Node* node) {
    if (node == NULL) {

        return 0;
    }else {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight) {
            
            return (lheight + 1);
        } else {
         return (rheight + 1);
        }
    }
}

void printCurrentLevel(struct Node* root, int level) {
    if (root == NULL) {
       return;
    }

    if (level == 1){
        printf("%d ", root->data);
    }
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printBFS(struct Node* root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++) {
        printCurrentLevel(root, i);
    }
}