void insert(BST *tree, const char *key_data) {

    // Use pointer-to-pointer to easily modify the parent's child pointer
    // *trav points to the current node as we traverse
    BST *trav = tree;

    // 1?? Traverse the tree to find the correct insertion point
    while (*trav != NULL) {

        // Check if the key already exists in the tree
        if (strcmp((*trav)->key, key_data) == 0) {
            // Key exists, do not insert duplicates
            printf("Key \"%s\" already exists. Ignoring.\n", key_data);
            return;
        }

        // Decide which subtree to traverse
        if (strcmp(key_data, (*trav)->key) > 0) {
            // key_data is greater than current node's key ? go right
            trav = &((*trav)->RC);
        } else {
            // key_data is less than current node's key ? go left
            trav = &((*trav)->LC);
        }
    }

    // 2?? Insert the new node when we reach a NULL position
    if (*trav == NULL) {
        *trav = (BST) calloc(1, sizeof(Node));  // allocate memory for new node
        if (!*trav) {
            fprintf(stderr, "Memory allocation failed.\n");
            return;
        }

        // Allocate memory for the key string (+1 for null terminator)
        (*trav)->key = malloc(strlen(key_data) + 1);
        if (!(*trav)->key) {
            fprintf(stderr, "Memory allocation for key failed.\n");
            free(*trav);
            return;
        }

        strcpy((*trav)->key, key_data); // Copy key_data into the node
    }

    // 3?? Print confirmation (optional)
    printf("Inserted key: \"%s\" \n", key_data);
}






BST deleteNode(BST root, const char *key_data) {

    // Use a pointer-to-pointer so we can easily rewire parent links
    // *trav will point to the current node as we traverse
    BST *trav = &root; 

    // 1?? Traverse the tree to find the node to delete
    while (*trav != NULL && strcmp(key_data, (*trav)->key) != 0) {
        int status = strcmp(key_data, (*trav)->key);

        // Move right if key_data > current node's key
        if (status > 0) {
            trav = &(*trav)->RC;
        } else { // Move left if key_data < current node's key
            trav = &(*trav)->LC;
        }

        // If we reach a NULL child, the key doesn't exist in the tree
        if (*trav == NULL) {
            printf("Key \"%s\" not found for deletion.\n", key_data);
            return root; // Return original tree
        }
    }

    // 2?? Node deletion cases

    // Case A: Node is a leaf (no children)
    if ((*trav)->LC == NULL && (*trav)->RC == NULL) {
        Node *temp = *trav;  // Store pointer to node to free
        *trav = NULL;        // Remove node from parent
        free(temp->key);     // Free dynamically allocated key string
        free(temp);          // Free the node itself
    }
    // Case B: Node has two children
    else if ((*trav)->LC != NULL && (*trav)->RC != NULL) {

        // Find inorder successor: leftmost node in right subtree
        BST *successor = &(*trav)->RC;
        while ((*successor)->LC != NULL) {
            successor = &(*successor)->LC;
        }

        // Copy successor's key into the node to delete
        // Free old key to prevent memory leak
        free((*trav)->key);
        (*trav)->key = malloc(strlen((*successor)->key) + 1);
        strcpy((*trav)->key, (*successor)->key);

        // Delete the successor node, which has at most one child
        Node *sNode = *successor;
        Node *child = sNode->RC; // Successor cannot have a left child
        *successor = child;       // Rewire parent to bypass successor
        free(sNode->key);         // Free successor's key
        free(sNode);              // Free successor node
    }
    // Case C: Node has only one child
    else {
        Node *child;
        if ((*trav)->LC != NULL) {
            child = (*trav)->LC; // Node has only left child
        } else {
            child = (*trav)->RC; // Node has only right child
        }

        Node *temp = *trav; // Store node to delete
        *trav = child;      // Rewire parent to bypass node
        free(temp->key);    // Free key
        free(temp);         // Free node
    }

    // 3?? Return the (possibly updated) root of the tree
    return root;
}

