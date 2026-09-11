/* 1. Case Study: Student Registration Management
A university department wants to develop a simple system to maintain a list of students who have registered for a technical workshop.
The number of students registering for the workshop is not fixed. Therefore, using a static array may result in either:
•	Wastage of memory when fewer students register, or
•	Insufficient space when more students register.
To solve this problem, the software developer decides to use a Singly Linked List.
Each student record will be represented using a node containing:
•	Student ID
•	Pointer to the next student
The first node of the linked list is accessed through a pointer called HEAD.
The department wants the system to perform the following basic operations:
1.	Create a singly linked list.
2.	Add student records dynamically.
3.	Traverse the linked list.
4.	Display all student records in the order in which they were added.
________________________________________*/


#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int n;                
    struct st *next;
} link;

link *head = NULL;

void create()
{
    int data;
    link *ptr = NULL, *temp = NULL;

    ptr = (link *)malloc(sizeof(link));

    printf("Enter Student ID: ");
    scanf("%d", &data);

    ptr->n = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = ptr;
    }
}

void traverse()
{
    link *temp;

    temp = head;

    if (head == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    printf("\nStudent IDs are:\n");

    while (temp != NULL)
    {
        printf("%d ", temp->n);
        temp = temp->next;
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;

        case 2:
            traverse();
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid Choice");
        }
    }

    return 0;
}