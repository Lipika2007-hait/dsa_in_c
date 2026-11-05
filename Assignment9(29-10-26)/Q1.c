/*1. Addition of Two Polynomials Using Linked List

Question: Write a C program to perform addition of two polynomials using a linked list and display the resultant list.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node *next;
};

struct Node* insert(struct Node *head, int c, int e) {
    struct Node *p = head, *prev = NULL;

    while (p != NULL && p->exp > e) {
        prev = p;
        p = p->next;
    }

    if (p != NULL && p->exp == e) {
        p->coeff += c;
        return head;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = p;

    if (prev == NULL)
        head = newNode;
    else
        prev->next = newNode;

    return head;
}

struct Node* add(struct Node *p, struct Node *q) {
    struct Node *result = NULL;

    while (p != NULL) {
        result = insert(result, p->coeff, p->exp);
        p = p->next;
    }

    while (q != NULL) {
        result = insert(result, q->coeff, q->exp);
        q = q->next;
    }

    return result;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        head = head->next;
        if (head != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node *p = NULL, *q = NULL, *result = NULL;
    int n, c, e, i;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        p = insert(p, c, e);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        q = insert(q, c, e);
    }

    result = add(p, q);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}