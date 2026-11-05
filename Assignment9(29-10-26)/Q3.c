/*3. Delete a Node from a Given Position in a Doubly Linked List

Question: Write a C program to delete an item from position 3 of an existing doubly linked list and print the resultant list.

Given list: 2 ↔ 6 ↔ 9 ↔ 13*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* deleteNode(struct Node *head, int pos) {
    struct Node *temp = head;
    int i;

    if (head == NULL)
        return head;

    if (pos == 1) {
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        free(temp);
        return head;
    }

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return head;

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

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
    int a[] = {2, 6, 9, 13};
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

    head = deleteNode(head, 3);

    printf("\nResultant List: ");
    display(head);

    return 0;
}