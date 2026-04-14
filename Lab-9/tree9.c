#include <stdio.h>
#include <stdlib.h>

// Define TreeNode
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Define BinaryTree
struct BinaryTree {
    struct TreeNode* root;
};

// Create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert (simple level-order insertion)
void insert(struct BinaryTree* tree, int data) {
    struct TreeNode* newNode = createNode(data);

    // If tree is empty
    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    // Use a simple queue (array-based)
    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = tree->root;

    while (front < rear) {
        struct TreeNode* temp = queue[front++];

        // Insert as left child
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            queue[rear++] = temp->left;
        }

        // Insert as right child
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            queue[rear++] = temp->right;
        }
    }
}

// Pre-order traversal
void preOrderTraversal(struct TreeNode* node) {
    if (node == NULL) return;

    printf("%d ", node->data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

// Main function
int main() {
    struct BinaryTree tree;
    tree.root = NULL;

    insert(&tree, 1);
    insert(&tree, 2);
    insert(&tree, 3);
    insert(&tree, 4);
    insert(&tree, 5);

    printf("Pre-order traversal: ");
    preOrderTraversal(tree.root);

    return 0;
}
