#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10
#define ROOT_NODE -1
#define INVALID_NODE -2

typedef int Node;

typedef struct ChildNode {
    Node childIndex;
    struct ChildNode *next;
} ChildNode;

typedef struct {
    Node rootIndex;
    ChildNode* children[MAX_NODES];
} Tree;

void initializeTree(Tree *T) {
    int i;
    T->rootIndex = INVALID_NODE;
    for(i = 0; i < MAX_NODES; i++) {
        T->children[i] = NULL;
    }
}

void makeRoot(Tree *T, Node r) {
    T->rootIndex = r;
}

void addChild(Tree *T, Node parent_index, Node child_index) {
    ChildNode *newNode = malloc(sizeof(ChildNode));

    if(newNode != NULL) {
        newNode->childIndex = child_index;
        newNode->next = NULL;
    }

    ChildNode *temp = T->children[parent_index];
    T->children[parent_index] = newNode;
    newNode->next = temp;
}

Node parent(Node n, const Tree *T) {
    int i;

    for(i = 0; i < MAX_NODES; i++) {
        ChildNode *trav = T->children[i];

        while(trav != NULL) {
            if(n == T->rootIndex) {
                return ROOT_NODE;
            }

            if(trav->childIndex == n) {
                return i;
            }

            trav = trav->next;
        }
    }

    return INVALID_NODE;
}

Node left(const Tree *T) {
    int i;

    for(i = 0; i < MAX_NODES; i++) {
        ChildNode *trav = T->children[i];

        if(trav == NULL) {
            return i;
        }
    }

    return INVALID_NODE;
}

Node right(const Tree *T) {
    int i;

    for(i = MAX_NODES - 1; i > 0; i--) {
        ChildNode *trav = T->children[i];

        if(trav == NULL) {
            return i;
        }
    }

    return INVALID_NODE;
}

void freeTree(Tree *T) {
    for (int i = 0; i < MAX_NODES; i++) {
        ChildNode *current = T->children[i];
        ChildNode *next;

        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }

        T->children[i] = NULL;
    }

    printf("\nTree memory cleaned up.\n");
}

void printTree(const Tree *T) {
    printf("--- Tree Children List Representation ---\n");
    printf("Root Index: %d\n", T->rootIndex);
    printf("Parent Index | Children List\n");
    printf("-------------|---------------\n");

    for (int i = 0; i < MAX_NODES; i++) {
        printf("%12d | ", i);
        ChildNode *current = T->children[i];

        if (current == NULL) {
            printf("(None)\n");
        } else {
            while (current != NULL) {
                printf("%d -> ", current->childIndex);
                current = current->next;
            }
            printf("NULL\n");
        }
    }

    printf("-----------------------------------------\n");
}

int main() {
    Tree myTree;
    initializeTree(&myTree);

    makeRoot(&myTree, 0);

    addChild(&myTree, 0, 1);
    addChild(&myTree, 0, 2);

    addChild(&myTree, 1, 3);
    addChild(&myTree, 1, 4);

    addChild(&myTree, 2, 5);

    addChild(&myTree, 5, 8);
    addChild(&myTree, 5, 9);

    printTree(&myTree);

    printf("\n--- Testing ADT Operations ---\n");

    Node node_to_check = 5;
    Node p = parent(node_to_check, &myTree);

    if (p == ROOT_NODE) {
        printf("Parent of Node %d: (It is the Root)\n", node_to_check);
    } else if (p == INVALID_NODE) {
        printf("Parent of Node %d: (Node is Invalid/Not Found)\n", node_to_check);
    } else {
        printf("Parent of Node %d: Node %d\n", node_to_check, p);
    }

    node_to_check = 0;
    p = parent(node_to_check, &myTree);

    if (p == ROOT_NODE) {
        printf("Parent of Node %d: (It is the Root)\n", node_to_check);
    } else {
        printf("Parent of Node %d: Node %d\n", node_to_check, p);
    }

    node_to_check = 7;
    p = parent(node_to_check, &myTree);

    if (p == INVALID_NODE) {
        printf("Parent of Node %d: (Node is Invalid/Not Found)\n", node_to_check);
    } else {
        printf("Parent of Node %d: Node %d\n", node_to_check, p);
    }

    Node l = left(&myTree);
    if (l != INVALID_NODE) {
        printf("Leftmost Leaf: Node %d\n", l);
    } else {
        printf("Leftmost Leaf: Tree is empty or has no leaves.\n");
    }

    Node r = right(&myTree);
    if (r != INVALID_NODE) {
        printf("Rightmost Leaf: Node %d\n", r);
    } else {
        printf("Rightmost Leaf: Tree is empty or has no leaves.\n");
    }

    freeTree(&myTree);

    return 0;
}
