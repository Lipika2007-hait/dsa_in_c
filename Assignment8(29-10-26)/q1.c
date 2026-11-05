/*
Q.8.1.
Reversing a Delivery Route  using a Singly linked list.

A delivery Company Store it's delivery stops in a singly linked list.
Each Node Contains a Stop number and a pointer to the next stop .
After completing the deliveries , the driver needs to stops dilsplayed in
reverse order for the return journey.

Task: WACP to create the route , display it , reverse the singly linked , and display reversed route.

Example:
    Original Route : 101 -> 102 -> 103 -> 104 -> NULL
    Reversed Route : 104 -> 103 -> 102 -> 101 -> NULL
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode, *prev = NULL, *next;
    int n, i;

    printf("Enter number of stops: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("Original Route: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    temp = head;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;

    printf("Reversed Route: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}