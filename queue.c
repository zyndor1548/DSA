#include <stdio.h>

int rear = -1;
int front = -1;
int max;
int q[100];

void enqueue();
void dequeue();
void display();

int main() {
    printf("Enter max queue size : ");
    scanf("%d", &max);

    int menu;
    do {
        printf("\nQueue Menu");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nChoose: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (menu != 4);

    return 0;
}

void enqueue() {
    if (rear + 1 >= max) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;

    rear += 1;
    printf("Enter value: ");
    scanf("%d", &q[rear]);
    printf("Enqueued: %d\n", q[rear]);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Dequeued: %d\n", q[front]);
    q[front] = 0;
    front += 1 ;

    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}
