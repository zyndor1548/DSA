#include <stdio.h>
int q[10], front = -1, rear = -1, item, m;
void push();
void pop();
void display();
void inject();
void eject();
int main()
{
    int choice;
    printf("operation of double ended queue  \n");
    printf("enter the size of queue : ");
    scanf("%d", &m);
    do
    {
        printf("\noperation of double ented queue by TABASSUM VK \n 1.pop() \n 2.push() \n 3.inject() \n 4.eject()\n 5.display()\n 6.exit\n");
        printf("enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            pop();
            break;
        case 2:
            push();
            break;
        case 3:
            inject();
            break;
        case 4:
            eject();
            break;
        case 5:
            display();
            break;
        case 6:
            break;
        default:
            printf("invalid choice try again");
        }
    } while (choice != 6);
    return 0;
}
void inject()
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        printf("enter the value :");
        scanf("%d", &item);
        q[rear] = item;
        printf("enqued sucessfully");
    }
    else if (front == (rear + 1) % m)
        printf("queue is full");
    else
    {
        rear = (rear + 1) % m;
        printf("enter the value :");
        scanf("%d", &item);
        q[rear] = item;
    }
}

void pop()
{
    if (front == -1 && rear == -1)
        printf("queue is empty");
    else if (rear == front)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % m;
}

void display()
{
    if (front == -1 && rear == -1)
        printf("queue is empty \n");
    else
    {
        for (int i = front; i != rear; i = (i + 1) % m)
        {
            printf("%d ", q[i]);
        }
        printf("%d\n", q[rear]);
    }
}
void push()
{
    int ahead = front;
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        printf("enter the value : ");
        scanf("%d", &item);
        q[front] = item;
    }
    else
    {
        if (front == 0)
            ahead = m - 1;
        else
            ahead = front - 1;
        if (ahead == rear)
        {
            printf("overflow \n");
        }
        else
        {
            front = ahead;
            printf("enter the value : ");
            scanf("%d", &item);
            q[front] = item;
        }
    }
}
void eject()
{
    if (rear == -1 && front == -1)
        printf("underflow");
    else
    {
        item = q[rear];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = m - 1;
        else
            rear = rear - 1;
    }
}