#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* head = NULL;


// Insert node at end
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


// Delete at given position
void deletePosition(int pos) {


    struct Node* temp = head;


    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }


    temp->prev->next = temp->next;


    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }


    free(temp);
}


int main() {


    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);


    printf("Doubly Linked List before deletion:\n");
    display();


    deletePosition(3);


    printf("\nDoubly Linked List after deleting position 3:\n");
    display();


    return 0;
}
