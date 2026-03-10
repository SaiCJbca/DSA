#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Display list
void display() {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to start)\n");
}

// Insert at end
void insertEnd(int data) {

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    struct Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;
}

// Insert at start
void insertStart(int data) {

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    struct Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;

    head = newNode;
}

// Insert at position
void insertPosition(int data, int pos) {

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = head;

    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    printf("Circular Doubly Linked List before insertion:\n");
    display();

    insertStart(5);
    printf("\nAfter insertion at start:\n");
    display();

    insertEnd(50);
    printf("\nAfter insertion at end:\n");
    display();

    insertPosition(25, 3);
    printf("\nAfter insertion at position 3:\n");
    display();

    return 0;
}