#include <stdio.h>
int q[50], stack[50];
int top = -1, front = -1, rear = -1;
void push(int val) {
	if (top >= 50) {
		printf("stack overflow");
		return;
	}
	stack[++top] = val;
}
int pop() {
	if (top == -1) {
		printf("stack underflow");
		return -1;
	}
	return stack[top--];
}
void enqueue(int val) {
	if (rear >= 50) {
		printf("queue overflow");
	}
	if (front == -1 && rear == -1) {
		front = 0;
	}
	q[++rear] = val;
}
int dequque() {
	if (front == -1) {
		printf("queue underflow");
	}
	return q[front++];
}
void display_q() {
	for (int i = front; i <= rear; i++) {
		printf("%d ", q[i]);
	}
	printf("\n");
}
void Reverse() {
	for (int i = front; i <= rear; i++) {
		push(dequque());
	}
	for (int i = top; i >= 0; i--) {
		enqueue(pop());
	}
}
int main() {
	printf("Enter number : ");
	int num, num2;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		printf("enter input : ");
		scanf("%d", &num2);
		enqueue(num2);
	}
	printf("initial queue");
	display_q();
	Reverse();
	printf("reversed queue");
	display_q();
	return 0;
}