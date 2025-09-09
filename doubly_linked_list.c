#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *blink,*flink;
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
    head->flink = NULL;
    head->blink = NULL;
    int elements;
    printf("how many elements do you want to add at first : ");
    scanf("%d", &elements);
    if (elements != 0)
    {
        struct Node *prev;
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter value : ");
        scanf("%d", &temp->data);
        temp->flink = NULL;
        temp->blink = head;
        head->flink = temp;
        prev = temp;
        for (int i = 1; i < elements; i++)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            prev->flink = temp;
            printf("Enter value : ");
            scanf("%d", &temp->data);
            temp->flink = NULL;
            temp->blink = prev;
            prev = temp;
        }
    }
}
void display()
{
    temp = head->flink;
    while (temp != NULL)
    {
        printf("[%d:%d:%d] --> ", temp->blink , temp->data, temp->flink);
        temp = temp->flink;
    }
    printf("NULL\n");
}

void Insert_at_first()
{
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->flink = head->flink;
    temp->blink = head;
    head->flink = temp;
    printf("Enter value : ");
    scanf("%d", &temp->data);
}
void Insert_at_last()
{
    if (head->flink == NULL)
    {
        Insert_at_first();
        return;
    }
    ptr = head->flink;
    while (ptr->flink != NULL)
    {
        ptr = ptr->flink;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    ptr->flink = temp;
    temp->flink = NULL;
    temp->blink = ptr;
    printf("Enter value : ");
    scanf("%d", &temp->data);
}
void Insert_in_between()
{
    if (head->flink == NULL)
    {
        Insert_at_first();
        return;
    }
    ptr = head->flink;
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
            ptr = ptr->flink;
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
            ptr = ptr->flink;
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
    ptr->blink->flink = temp;
    temp->blink = ptr->flink;
    temp->flink = ptr;
    printf("Enter value : ");
    scanf("%d", &temp->data);
}
void Delete_first()
{
    if (head->flink == NULL)
    {
        printf("There is nothing to delete");
        return;
    }
    temp = head->flink;
    head->flink = temp->flink;
    temp->flink->blink = head;
    free(temp);
}
void Delete_last()
{
    if (head->flink == NULL)
    {
        printf("There is nothing to delete");
        return;
    }
    temp = head->flink;
    if (temp->flink != NULL)
    {
        while (temp->flink != NULL)
        {
            temp = temp->flink;
        }
        temp->blink->flink = NULL;
    }
    else
    {
        head->flink = NULL;
    }
    free(temp);
}
void Delete_from_between()
{
    if (head->flink == NULL)
    {
        printf("There is nothing to delete");
        return;
    }
    ptr = head->flink;
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
            ptr = ptr->flink;
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
            ptr = ptr->flink;
        }
        break;
    }
    }
    if (ptr == NULL)
    {
        printf("Key/position is not in the linked list");
        return;
    }
    ptr->blink->flink = ptr->flink;
    free(ptr);
}
void exit_linked_list()
{
    struct Node *temp;
    temp = head->flink;
    while (temp != NULL)
    {
        struct Node *next = temp->flink;
        free(temp);
        temp = next;
    }
    free(head);
}