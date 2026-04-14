#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node* adjList[MAX_VERTICES];
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Add edge (undirected)
void add_edge(struct Graph* graph, int v, int w) {
    // Add w to v
    struct Node* newNode = createNode(w);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;

    // Add v to w
    newNode = createNode(v);
    newNode->next = graph->adjList[w];
    graph->adjList[w] = newNode;
}

// DFS utility
void dfsUtil(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjList[vertex];

    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            dfsUtil(graph, adjVertex, visited);
        }

        temp = temp->next;
    }
}

// DFS function
void dfs(struct Graph* graph, int start_vertex) {
    int visited[MAX_VERTICES] = {0};

    dfsUtil(graph, start_vertex, visited);
    printf("\n");
}

// Main
int main() {
    struct Graph* graph = createGraph(5);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);

    printf("DFS starting from vertex 0: ");
    dfs(graph, 0);

    return 0;
}
