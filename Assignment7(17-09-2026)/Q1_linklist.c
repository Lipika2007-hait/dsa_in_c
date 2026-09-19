/*
17/09/2026
7.1.
In a shop the Product prices of 5 products are stored in a list.
The price is stored in a float/double .
Each node of list consist of price of one product and address of next.
Perform the following operation on the list in menu driven form.
option 1:Create List
option 2:Traverse list
option 3:Search one price in list taken input from user
option 4:Insert the price of new at the head
option 5:Insert the Price of new item at 3rd position of list.

Sample:
List : 50.5->20.25->13.5->18.5->41.25
at head insert 65.25
at position 3 insert 102.50
*/



#include <stdio.h>
#include <stdlib.h>

struct node
{
    float data;
    struct node *next;
};

struct node *head = NULL;


void createList()
{
    int n, i;
    float item;
    struct node *ptr, *temp;

    printf("Enter number of products: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter price of product %d: ", i);
        scanf("%f", &item);

        ptr = (struct node *)malloc(sizeof(struct node));

        ptr->next = NULL;
        ptr->data = item;

        if(head == NULL)
        {
            head = ptr;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = ptr;
        }
    }

    printf("List created successfully.\n");
}


void traverse()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List:\n");

    while(temp != NULL)
    {
        printf("%.2f -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


void search()
{
    float item;
    int pos = 1;
    struct node *temp;

    printf("Enter price to search: ");
    scanf("%f", &item);

    temp = head;

    while(temp != NULL)
    {
        if(temp->data == item)
        {
            printf("Item %.2f found at position %d.\n",
                   item, pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Item %.2f not found.\n", item);
}


void insertMinAtHead()
{
    struct node *temp, *ptr;
    float min;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    min = temp->data;

    while(temp != NULL)
    {
        if(temp->data < min)
        {
            min = temp->data;
        }

        temp = temp->next;
    }


    ptr = (struct node *)malloc(sizeof(struct node));

    ptr->next = head;
    ptr->data = min;

    head = ptr;

    printf("Minimum price %.2f inserted at head.\n", min);
}


void insertAtPosition()
{
    int pos, i;
    float item;
    struct node *ptr, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter price: ");
    scanf("%f", &item);

    ptr = (struct node *)malloc(sizeof(struct node));

    ptr->next = NULL;
    ptr->data = item;

    if(pos == 1)
    {
        ptr->next = head;
        head = ptr;

        printf("Item inserted successfully.\n");
        return;
    }

    temp = head;

    for(i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position.\n");
        free(ptr);
        return;
    }

    ptr->next = temp->next;

    temp->next = ptr;

    printf("Item inserted successfully.\n");
}


int main()
{
    int choice;

    while(1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Search an Item\n");
        printf("4. Insert Minimum Price at Head\n");
        printf("5. Insert Price at Any Position\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
         case 1:
                createList();
                break;

            case 2:
                traverse();
                break;

     case 3:
                search();
                break;

         case 4:
                insertMinAtHead();
                break;

         case 5:
                insertAtPosition();
                break;

            case 6:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}