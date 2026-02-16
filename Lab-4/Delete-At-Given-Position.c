#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node *next;
};

// Head pointer
struct Node *head = NULL;

// Insert at end
void insert_at_end(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete first node containing given data
void delete_node(int data) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    // Case 1: If head node contains data
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    // Search for node to delete
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If data not found
    if (temp == NULL) {
        printf("Value %d not found in list.\n", data);
        return;
    }

    // Unlink node
    prev->next = temp->next;
    free(temp);
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

// Free entire list
void free_list() {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {

    // Insert numbers
    insert_at_end(10);
    insert_at_end(11);
    insert_at_end(12);
    insert_at_end(13);
    insert_at_end(14);
    insert_at_end(15);

    printf("Original List:\n");
    display();

    // Delete a value
    delete_node(12);

    printf("After Deleting 12:\n");
    display();

    free_list();

    return 0;
}
