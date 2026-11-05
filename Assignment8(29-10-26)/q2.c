/*
Q.8.2.
Train coaches using Doubly Linked List:   
A railway system stores the coaches of a train in a doubly linked list. 
Each coach has a coach number and link to both previous and next coaches. 
This allows the railway staff to inspect the coaches from the engine towards 
the last coach and from the last coach back towards the engine.   

Task: — Write a C Program (WACP) to:   
i) Create a doubly linked list of coach numbers.   
ii) Traverse and display the coaches in forward order.   
iii) Traverse and display the coaches in backward order.  
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode;
    int n, i;

    printf("Enter number of coaches: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = temp;

        if (head == NULL) {
            head = newnode;
            newnode->prev = NULL;
        } else {
            temp->next = newnode;
        }
        temp = newnode;
    }

    printf("Forward: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next == NULL)
            break;
        temp = temp->next;
    }

    printf("\nBackward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    return 0;
}