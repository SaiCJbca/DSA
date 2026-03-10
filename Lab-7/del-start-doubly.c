#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* head = NULL;


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




void display() {
    struct Node* temp = head;


    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}




void deleteStart() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }


    struct Node* temp = head;
    head = head->next;


    if (head != NULL) {
        head->prev = NULL;
    }


    free(temp);
}


int main() {


    insert(10);
    insert(20);
    insert(30);
    insert(40);
    printf("Doubly Linked List before deletion:\n");
    display();
    deleteStart();
    printf("\nDoubly Linked List after deletion at start:\n");
    display();


    return 0;
}
