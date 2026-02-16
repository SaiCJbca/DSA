#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Head pointer (initially NULL)
struct Node *head = NULL;

// Function to insert at beginning
void insert_at_beginning(int data) {
    // Create new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    // Assign data
    newNode->data = data;

    // Make new node point to current head
    newNode->next = head;

    // Move head to new node
    head = newNode;
}

// Function to display list
void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert_at_beginning(11);
    insert_at_beginning(22);
    insert_at_beginning(33);
    insert_at_beginning(44);
    insert_at_beginning(55);

    printf("Linked List:\n");
    display();

    return 0;
}
