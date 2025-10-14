#include <stdio.h>
int front = -1, rear = -1;
int max, q[50];
void enqueue() {
	if (rear + 1 > max) {
		printf("queue is overflow\n");
		return;
	}
	if (front == -1) {
		front = 0;
	}
	rear += 1;
	printf("enter value : ");
	scanf("%d", &q[rear]);
}
void dequeue() {
	if (front <= -1) {
		printf("queue is underflow\n");
		return;
	}
	front += 1;
	printf("element dequeued\n");
}
void display() {
	if (front == -1) {
		printf("queue is empty\n");
		return;
	}
	printf("queue --> ");
	for (int i = front; i <= rear; i++) {
		printf("%d ", q[i]);
	}
	printf("\n ");
}
int main() {
	printf("Enter total number of elements in the queue : ");
	scanf("%d", &max);
	int menu;
	do {
		printf("\tstack menu\n");
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
