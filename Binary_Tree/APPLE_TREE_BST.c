#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct apple {
    char name[20];
    char color[10];
    int hardness;
    int size_cm;
    bool ripe;
} Apple;

typedef struct node {
    Apple *app;
    struct node *LC;
    struct node *RC;
} Node, *BST;

typedef struct box {
    Apple apples[50];
    int count;
    int capacity;
} Box;

BST createNode(Apple *a);
BST insertBST(BST root, Apple *a);
BST deleteNode(BST root);
BST makeAppleTree(Apple apples[], int n);
void preorderTraversal(BST root);
BST harvestRecursive(BST root, Box *box);
BST harvestRotten(BST root, Box *box);
void initBox(Box *box, int capacity);

int main() {
    Box box;
    initBox(&box, 10);

    Apple apples[10] = {        
        {"Fuji", "red", 7, 8, true},
        {"Gala", "green", 6, 7, true},
        {"Honeycrisp", "red", 5, 6, false},
        {"Golden", "yellow", 8, 9, true},
        {"RedDel", "red", 6, 7, true},
        {"Granny", "green", 7, 8, true},
        {"Jonathan", "red", 8, 9, true},
        {"McIntosh", "red", 4, 7, true},
        {"PinkLady", "pink", 6, 7, true},
        {"Empire", "red", 7, 8, false}
    };

    BST tree = makeAppleTree(apples, 10);

    printf("Pre-order traversal of BST:\n");
    preorderTraversal(tree);

    printf("\n\nHarvested Ripe Apples:\n");
    tree = harvestRecursive(tree, &box);

    printf("\n\nRotten Apples:\n");
    tree = harvestRotten(tree, &box);

    return 0;
}

BST createNode(Apple *a) {
    BST newNode = malloc(sizeof(Node));
    newNode->app = malloc(sizeof(Apple));
    strcpy(newNode->app->name, a->name);
    strcpy(newNode->app->color, a->color);
    newNode->app->hardness = a->hardness;
    newNode->app->size_cm = a->size_cm;
    newNode->app->ripe = a->ripe;
    newNode->LC = NULL;
    newNode->RC = NULL;
    return newNode;
}

BST insertBST(BST root, Apple *a) {
    if(root == NULL) return createNode(a);

    if(a->size_cm < root->app->size_cm) {
        root->LC = insertBST(root->LC, a);
    } else if(a->size_cm > root->app->size_cm) {
        root->RC = insertBST(root->RC, a);
    } else {
        if(strcmp(a->name, root->app->name) < 0)
            root->LC = insertBST(root->LC, a);
        else if(strcmp(a->name, root->app->name) > 0)
            root->RC = insertBST(root->RC, a);
    }
    return root;
}

BST deleteNode(BST root) {
    if(root == NULL) return NULL;

    if(root->LC == NULL && root->RC == NULL) {
        free(root->app);
        free(root);
        return NULL;
    } else if(root->LC == NULL) {
        BST temp = root->RC;
        free(root->app);
        free(root);
        return temp;
    } else if(root->RC == NULL) {
        BST temp = root->LC;
        free(root->app);
        free(root);
        return temp;
    } else {
        BST succ = root->RC;
        while(succ->LC != NULL) succ = succ->LC;
        free(root->app);
        root->app = malloc(sizeof(Apple));
        strcpy(root->app->name, succ->app->name);
        strcpy(root->app->color, succ->app->color);
        root->app->hardness = succ->app->hardness;
        root->app->size_cm = succ->app->size_cm;
        root->app->ripe = succ->app->ripe;
        root->RC = deleteNode(root->RC);
        return root;
    }
}

BST makeAppleTree(Apple apples[], int n) {
    BST tree = NULL;
    for(int i = 0; i < n; i++) {
        tree = insertBST(tree, &apples[i]);
    }
    return tree;
}

void preorderTraversal(BST root) {
    if(root == NULL) return;
    Node *stack[100];
    int top = -1;
    stack[++top] = root;

    while(top != -1) {
        Node *curr = stack[top--];
        printf("%s, %s, %d, %d, %d\n", curr->app->name, curr->app->color,
               curr->app->hardness, curr->app->size_cm, curr->app->ripe);
        if(curr->RC != NULL) stack[++top] = curr->RC;
        if(curr->LC != NULL) stack[++top] = curr->LC;
    }
}

BST harvestRecursive(BST root, Box *box) {
    if(root == NULL) return NULL;
    root->LC = harvestRecursive(root->LC, box);
    Apple *a = root->app;
    if(strcmp(a->color, "red") == 0 && a->hardness > 6 && a->size_cm > 7 && a->ripe) {
        if(box->count < box->capacity) {
            box->apples[box->count++] = *a;
            printf("%s, ", a->name);
        }
        root = deleteNode(root);
        return harvestRecursive(root, box);
    }
    root->RC = harvestRecursive(root->RC, box);
    return root;
}

BST harvestRotten(BST root, Box *box) {
    if(root == NULL) return NULL;
    root->LC = harvestRotten(root->LC, box);
    Apple *a = root->app;
    if(!a->ripe) {
        if(box->count < box->capacity) {
            box->apples[box->count++] = *a;
            printf("%s, ", a->name);
        }
        root = deleteNode(root);
        return harvestRotten(root, box);
    }
    root->RC = harvestRotten(root->RC, box);
    return root;
}

void initBox(Box *box, int capacity) {
    box->count = 0;
    box->capacity = capacity;
}
