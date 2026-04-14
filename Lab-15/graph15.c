#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100

// Adjacency list node
struct Node {
    int user;
    struct Node* next;
};

// Social Network (Graph)
struct SocialNetwork {
    int numUsers;
    struct Node* adjList[MAX_USERS];
};

// Create node
struct Node* createNode(int user) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->user = user;
    newNode->next = NULL;
    return newNode;
}

// Create network
struct SocialNetwork* createNetwork(int users) {
    struct SocialNetwork* net = (struct SocialNetwork*)malloc(sizeof(struct SocialNetwork));
    net->numUsers = users;

    for (int i = 0; i < users; i++) {
        net->adjList[i] = NULL;
    }

    return net;
}

// Add friendship (undirected)
void add_friendship(struct SocialNetwork* net, int u1, int u2) {
    struct Node* newNode = createNode(u2);
    newNode->next = net->adjList[u1];
    net->adjList[u1] = newNode;

    newNode = createNode(u1);
    newNode->next = net->adjList[u2];
    net->adjList[u2] = newNode;
}

// BFS for shortest path (degrees of separation)
int degrees_of_separation(struct SocialNetwork* net, int start, int target) {
    int visited[MAX_USERS] = {0};
    int distance[MAX_USERS];

    // Queue
    int queue[MAX_USERS];
    int front = 0, rear = 0;

    // Initialize
    visited[start] = 1;
    distance[start] = 0;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];

        if (current == target)
            return distance[current];

        struct Node* temp = net->adjList[current];

        while (temp != NULL) {
            int neighbor = temp->user;

            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                distance[neighbor] = distance[current] + 1;
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    return -1; // No path
}

// Demo
int main() {
    struct SocialNetwork* net = createNetwork(6);

    add_friendship(net, 0, 1);
    add_friendship(net, 0, 2);
    add_friendship(net, 1, 3);
    add_friendship(net, 2, 4);
    add_friendship(net, 4, 5);

    int deg = degrees_of_separation(net, 0, 5);

    if (deg != -1)
        printf("Degrees of separation: %d\n", deg);
    else
        printf("No connection\n");

    return 0;
}
