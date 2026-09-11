/* WAP in C to implement single link list*/ 

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

    printf("Enter data: ");
    scanf("%d",&data);

    ptr-> n= data ;
  
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
        printf("\n1. Create");
        printf("\n2. Traverse");
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