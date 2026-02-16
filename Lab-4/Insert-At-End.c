#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// insert at beginning
void insert_at_beginning(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// insert at end
void insert_at_end(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

  
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Display list
void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert_at_end(10);
    insert_at_end(11);
    insert_at_end(12);
    insert_at_end(13);
    insert_at_end(14);
    insert_at_end(15);

    printf("Linked List:\n");
    display();

    free_list();  

    return 0;
}

