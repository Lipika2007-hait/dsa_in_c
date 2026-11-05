/*2. Insert a Node in a Doubly Linked List

Question: Write a C function to insert a node with value 12 between the 2nd and 3rd nodes of an existing doubly linked list.

Given list: 6 ↔ 2 ↔ 8 ↔ 4*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* insert(struct Node *head, int value, int pos) {
    struct Node *newNode, *temp = head;
    int i;

    newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int a[] = {6, 2, 8, 4};
    int i;

    for (i = 0; i < 4; i++) {
        newNode = malloc(sizeof(struct Node));
        newNode->data = a[i];
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp->next = newNode;
            newNode->prev = temp;
        }
        temp = newNode;
    }

    printf("Original List: ");
    display(head);

    head = insert(head, 12, 3);

    printf("\nResultant List: ");
    display(head);

    return 0;
}