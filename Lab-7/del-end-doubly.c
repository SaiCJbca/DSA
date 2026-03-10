#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* head = NULL;


// Insert node at end (to create list)
void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;


    if (head == NULL) {
        head = newNode;
        return;
    }


    struct Node* temp = head;


    while (temp->next != NULL) {
        temp = temp->next;
    }


    temp->next = newNode;
    newNode->prev = temp;
}


// Display list
void display() {
    struct Node* temp = head;


    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }


    printf("NULL\n");
}


// Delete node at end
void deleteEnd() {


    if (head == NULL) {
        printf("List is empty\n");
        return;
    }


    struct Node* temp = head;


    // Only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }


    while (temp->next != NULL) {
        temp = temp->next;
    }


    temp->prev->next = NULL;
    free(temp);
}


int main() {


    insert(10);
    insert(20);
    insert(30);
    insert(40);


    printf("Doubly Linked List before deletion:\n");
    display();


    deleteEnd();


    printf("\nDoubly Linked List after deletion at end:\n");
    display();


    return 0;
}
