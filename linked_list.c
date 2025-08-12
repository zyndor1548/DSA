#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
struct Node *head, *temp, *ptr;

void create_linked_list();
void display();
void Insert_at_first();
void Insert_at_last();
void Insert_in_between();
void Delete_first();
void Delete_last();
void Delete_from_between();
void exit_linked_list();
int main()
{
    create_linked_list();
    int choice, choice2;
    do
    {
        printf("\tLinked List Menu\n");
        printf("\t1. Insert\n");
        printf("\t2. Delete\n");
        printf("\t3. Display\n");
        printf("\t4. Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\tLinked List Insertion Menu\n");
            printf("\t1. Insert as First Node\n");
            printf("\t2. Insert as Last Node\n");
            printf("\t3. Insert In between\n");
            printf("Enter Choice : ");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                Insert_at_first();
                break;
            case 2:
                Insert_at_last();
                break;
            case 3:
                Insert_in_between();
                break;
            }
            break;
        case 2:
            printf("\tLinked List Deletetion Menu\n");
            printf("\t1. Delete First Node\n");
            printf("\t2. Delete Last Node\n");
            printf("\t3. Delete from between\n");
            printf("Enter Choice : ");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                Delete_first();
                break;
            case 2:
                Delete_last();
                break;
            case 3:
                Delete_from_between();
                break;
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit_linked_list();
            break;
        default:
            printf("invalid choice !!!");
            break;
        }
    } while (choice != 4);

    return 1;
}
void create_linked_list()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    head->link = NULL;
    int elements;
    printf("how many elements do you want to add at first : ");
    scanf("%d", &elements);
    if (elements != 0)
    {
        struct Node *prev;
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter value : ");
        scanf("%d", &temp->data);
        temp->link = NULL;
        head->link = temp;
        prev = temp;
        for (int i = 1; i < elements; i++)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            prev->link = temp;
            printf("Enter value : ");
            scanf("%d", &temp->data);
            temp->link = NULL;
            prev = temp;
        }
    }
}
void display()
{
    temp = head->link;
    while (temp != NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void Insert_at_first()
{
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->link = head->link;
    head->link = temp;
    printf("Enter value : ");
    scanf("%d", &temp->data);
}
void Insert_at_last()
{
    if (head->link == NULL)
    {
        Insert_at_first();
        return;
    }
    ptr = head->link;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    ptr->link = temp;
    temp->link = NULL;
    printf("Enter value : ");
    scanf("%d", &temp->data);
}
void Insert_in_between()
{
    if (head->link == NULL)
    {
        Insert_at_first();
        return;
    }
    struct Node *prev = head;
    ptr = head->link;
    int choice;
    printf("\tLinked List Insertion Between Menu\n");
    printf("\t1. Insert before a value\n");
    printf("\t2. Insert at position\n");
    printf("Enter Choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        int key;
        printf("Enter key : ");
        scanf("%d", &key);
        while (ptr != NULL && ptr->data != key)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        break;
    }
    default:
    {
        int pos;
        printf("Enter Position : ");
        scanf("%d", &pos);
        if (pos == 0)
        {
            Insert_at_first();
            return;
        }
        int i;
        for (i = 0; ptr != NULL && i < pos; i++)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        break;
    }
    }
    if (ptr == NULL)
    {
        printf("Key/position is not in the linked list");
        return;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    prev->link = temp;
    temp->link = ptr;
    printf("Enter value : ");
    scanf("%d", &temp->data);
}
void Delete_first()
{
    if (head->link == NULL)
    {
        printf("There is nothing to delete");
        return;
    }
    temp = head->link;
    head->link = temp->link;
    free(temp);
}
void Delete_last()
{
    if (head->link == NULL)
    {
        printf("There is nothing to delete");
        return;
    }
    temp = head->link;
    if (temp->link != NULL)
    {
        struct Node *prev = head->link;
        while (temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
    }
    else
    {
        head->link = NULL;
    }
    free(temp);
}
void Delete_from_between()
{
    if (head->link == NULL)
    {
        printf("There is nothing to delete");
        return;
    }
    struct Node *prev = head;
    ptr = head->link;
    int choice;
    printf("\tLinked List Deletion Between Menu\n");
    printf("\t1. Delete a value\n");
    printf("\t2. Delete a position\n");
    printf("Enter Choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        int key;
        printf("Enter key : ");
        scanf("%d", &key);
        while (ptr != NULL && ptr->data != key)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        break;
    }
    default:
    {
        int pos;
        printf("Enter Position : ");
        scanf("%d", &pos);
        if (pos == 0)
        {
            Delete_first();
            return;
        }
        int i;
        for (i = 0; ptr != NULL && i < pos; i++)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        break;
    }
    }
    if (ptr == NULL)
    {
        printf("Key/position is not in the linked list");
        return;
    }
    prev->link = ptr->link;
    free(ptr);
}
void exit_linked_list()
{
    struct Node *temp;
    temp = head->link;
    while (temp != NULL)
    {
        struct Node *next = temp->link;
        free(temp);
        temp = next;
    }
    free(head);
}