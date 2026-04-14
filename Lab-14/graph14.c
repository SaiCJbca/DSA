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

// Create node
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
    struct Node* newNode = createNode(w);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;

    newNode = createNode(v);
    newNode->next = graph->adjList[w];
    graph->adjList[w] = newNode;
}

// DFS utility for cycle detection
int detectCycleUtil(struct Graph* graph, int vertex, int visited[], int parent) {
    visited[vertex] = 1;

    struct Node* temp = graph->adjList[vertex];

    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            if (detectCycleUtil(graph, adjVertex, visited, vertex))
                return 1;
        }
        else if (adjVertex != parent) {
            return 1; // Cycle found
        }

        temp = temp->next;
    }

    return 0;
}

// Detect cycle in entire graph
int detect_cycle(struct Graph* graph) {
    int visited[MAX_VERTICES] = {0};

    // Handle disconnected graph
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (detectCycleUtil(graph, i, visited, -1))
                return 1; // True
        }
    }

    return 0; // False
}

// Demo
int main() {
    struct Graph* graph = createGraph(5);

    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 1); // Creates cycle

    if (detect_cycle(graph))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}
