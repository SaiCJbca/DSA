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

// Create a new adjacency node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Initialize graph
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
    // Add w to v's list
    struct Node* newNode = createNode(w);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;

    // Add v to w's list
    newNode = createNode(v);
    newNode->next = graph->adjList[w];
    graph->adjList[w] = newNode;
}

// Print graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);

        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Demo
int main() {
    struct Graph* graph = createGraph(5);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
