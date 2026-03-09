#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtStart(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*head);
    newNode->prev = NULL;

    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }
    (*head) = newNode;
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

    insertAtStart(&head, 30);
    insertAtStart(&head, 20);
    insertAtStart(&head, 10);

    printf("Before: ");
    display(head);

    insertAtStart(&head, 5);

    printf("After:  ");
    display(head);

    return 0;
}
