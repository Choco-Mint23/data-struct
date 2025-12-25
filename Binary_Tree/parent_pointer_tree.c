#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10
#define ROOT_NODE -1
#define INVALID_NODE -2

typedef int Node;
typedef int Tree[MAX_NODES];

void initialize(Tree T) {
    int i;
    for(i = 0; i < MAX_NODES; i++) {
        T[i] = INVALID_NODE;
    }
}

void makeRoot(Tree T, Node r) {
    T[r] = ROOT_NODE;
}

void setParent(Tree T, Node child, Node parent) {
    T[child] = parent;
}

Node parent(Node n, Tree T) {
    if (T[n] == ROOT_NODE) {
        return ROOT_NODE;
    } else {
        return T[n];
    }
}

Node left(Tree T) {
    int i, j;

    for (i = 0; i < MAX_NODES; i++) {
        int childFlag = 0;

        for (j = 0; j < MAX_NODES; j++) {
            if (T[j] == i) {
                childFlag = 1;
                break;
            }
        }

        if (!childFlag)
            return i;
    }

    return INVALID_NODE;
}

Node right(Tree T) {
    int i, j;

    for (i = MAX_NODES - 1; i > 0; i--) {
        int childFlag = 0;

        for (j = 0; j < MAX_NODES; j++) {
            if (T[j] == i) {
                childFlag = 1;
                break;
            }
        }

        if (!childFlag)
            return i;
    }

    return INVALID_NODE;
}

void printTree(Tree T) {
    printf("--- Tree Array Representation ---\n");
    printf("Index (Child) | Parent\n");
    printf("--------------|-------\n");

    for (int i = 0; i < MAX_NODES; i++) {
        if (T[i] == ROOT_NODE) {
            printf("%13d | ROOT\n", i);
        } else if (T[i] == INVALID_NODE) {
            printf("%13d | (Uninitialized)\n", i);
        } else {
            printf("%13d | %d\n", i, T[i]);
        }
    }

    printf("---------------------------------\n");
}

int main() {
    Tree myTree;
    initialize(myTree);

    makeRoot(myTree, 0);
    setParent(myTree, 1, 0);
    setParent(myTree, 2, 0);
    setParent(myTree, 3, 1);
    setParent(myTree, 4, 1);
    setParent(myTree, 5, 2);
    setParent(myTree, 8, 5);
    setParent(myTree, 9, 5);

    printTree(myTree);

    Node node_to_check = 5;
    Node p = parent(node_to_check, myTree);

    if (p == ROOT_NODE) {
        printf("Parent of Node %d: (It is the Root)\n", node_to_check);
    } else if (p == INVALID_NODE) {
        printf("Parent of Node %d: (Node is Invalid/Uninitialized)\n", node_to_check);
    } else {
        printf("Parent of Node %d: Node %d\n", node_to_check, p);
    }

    node_to_check = 0;
    p = parent(node_to_check, myTree);

    if (p == ROOT_NODE) {
        printf("Parent of Node %d: (It is the Root)\n", node_to_check);
    } else {
        printf("Parent of Node %d: Node %d\n", node_to_check, p);
    }

    Node l = left(myTree);
    if (l != INVALID_NODE) {
        printf("Leftmost Leaf: Node %d\n", l);
    } else {
        printf("Leftmost Leaf: Tree is empty or has no leaves.\n");
    }

    Node r = right(myTree);
    if (r != INVALID_NODE) {
        printf("Rightmost Leaf: Node %d\n", r);
    } else {
        printf("Rightmost Leaf: Tree is empty or has no leaves.\n");
    }

    return 0;
}
