#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *link;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue() {
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	if (temp == NULL) {
		printf("queue is overflow\n");
		return;
	}
	printf("enter value : ");
	scanf("%d", &temp->data);
	temp->link = NULL;

	if (front == NULL) {
		front = temp;
		rear = temp;
		rear->link = front;
	} else {
		rear->link = temp;
		rear = temp;
		rear->link = front;
	}
}

void dequeue() {
	if (front == NULL) {
		printf("queue is underflow\n");
		return;
	}
	struct Node *temp = front;
	if (front == rear) {
		front = NULL;
		rear = NULL;
	} else {
		front = front->link;
		rear->link = front;
	}
	free(temp);
	printf("element dequeued\n");
}

void display() {
	if (front == NULL) {
		printf("queue is empty\n");
		return;
	}
	printf("queue --> ");
	struct Node *temp = front;
	do {
		printf("%d ", temp->data);
		temp = temp->link;
	} while (temp != front);
	printf("\n ");
}

int main() {
	int menu;
	do {
		printf("\tqueue menu\n");
		printf("\t1. display\n");
		printf("\t2. enqueue\n");
		printf("\t3. dequeue\n");
		printf("\t4. exit\n");
		printf("\t enter choice : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			display();
			break;
		case 2:
			enqueue();
			break;
		case 3:
			dequeue();
			break;
		case 4:
			printf("exiting...");
			break;
		default:
			printf("Invalid input\n");
		}
	} while (menu != 4);
	return 0;
}
