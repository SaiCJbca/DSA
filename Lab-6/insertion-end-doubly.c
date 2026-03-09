#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

void display(struct Node* node) {
    printf("NULL <- ");
    while (node != NULL) {
        printf("[%d]", node->data);
        if (node->next != NULL) {
            printf(" <-> ");
        }
        node = node->next;
    }
    printf(" -> NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);

    printf("Before: ");
    display(head);

    insertAtEnd(&head, 30);

    printf("After:  ");
    display(head);

    return 0;
}
