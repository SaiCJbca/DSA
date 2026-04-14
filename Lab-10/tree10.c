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

// LCA helper (returns pointer to LCA node)
struct TreeNode* findLCAUtil(struct TreeNode* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct TreeNode* leftLCA = findLCAUtil(root->left, n1, n2);
    struct TreeNode* rightLCA = findLCAUtil(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Public function
int find_lca(struct BinaryTree* tree, int n1, int n2) {
    struct TreeNode* lca = findLCAUtil(tree->root, n1, n2);

    if (lca == NULL) {
        printf("LCA not found\n");
        return -1;
    }

    return lca->data;
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

    int lca = find_lca(&tree, 4, 5);
    printf("LCA of 4 and 5: %d\n", lca);

    return 0;
}
