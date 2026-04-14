#include <stdio.h>
#include <stdlib.h>

// TreeNode
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// BinaryTree
struct BinaryTree {
    struct TreeNode* root;
};

// Create node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert (level-order)
void insert(struct BinaryTree* tree, int data) {
    struct TreeNode* newNode = createNode(data);

    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = tree->root;

    while (front < rear) {
        struct TreeNode* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            queue[rear++] = temp->right;
        }
    }
}

// Find node by value
struct TreeNode* findNode(struct TreeNode* root, int value) {
    if (root == NULL)
        return NULL;

    if (root->data == value)
        return root;

    struct TreeNode* left = findNode(root->left, value);
    if (left != NULL)
        return left;

    return findNode(root->right, value);
}

// Print grandchildren
void find_grandchildren(struct BinaryTree* tree, int value) {
    struct TreeNode* node = findNode(tree->root, value);

    if (node == NULL) {
        printf("Node not found\n");
        return;
    }

    int found = 0;

    // Left child's children
    if (node->left != NULL) {
        if (node->left->left != NULL) {
            printf("%d ", node->left->left->data);
            found = 1;
        }
        if (node->left->right != NULL) {
            printf("%d ", node->left->right->data);
            found = 1;
        }
    }

    // Right child's children
    if (node->right != NULL) {
        if (node->right->left != NULL) {
            printf("%d ", node->right->left->data);
            found = 1;
        }
        if (node->right->right != NULL) {
            printf("%d ", node->right->right->data);
            found = 1;
        }
    }

    if (!found) {
        printf("No grandchildren");
    }

    printf("\n");
}

// Demo
int main() {
    struct BinaryTree tree;
    tree.root = NULL;

    insert(&tree, 1);
    insert(&tree, 2);
    insert(&tree, 3);
    insert(&tree, 4);
    insert(&tree, 5);
    insert(&tree, 6);
    insert(&tree, 7);

    printf("Grandchildren of node 1: ");
    find_grandchildren(&tree, 1);

    return 0;
}
